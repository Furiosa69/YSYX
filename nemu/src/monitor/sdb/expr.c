/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include "memory/vaddr.h"

enum {
  TK_NOTYPE = 256, 
  TK_EQ    = 1,
  TK_NUM   = 2,
  TK_NEQ   = 3,
  TK_AND   = 4,
  TK_OR    = 5,
  TK_LT    = 6,
  TK_GT    = 7,
  TK_LE    = 8,
  TK_GE    = 9,
  TK_REG   = 10,
  TK_NEG   = 11,
  TK_DEREF = 12,
  TK_POS   = 13,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  {" +", TK_NOTYPE},    //空格串

  {"\\+",'+'},		//四则运算
  {"-",'-'},
  {"/",'/'},
  {"\\*",'*'},

  {"\\(",'('},		//括号
  {"\\)",')'},

  {"&&",TK_AND},	//逻辑
  {"\\|\\|",TK_OR},

  {"<",TK_LT},
  {">",TK_GT},
  {"<=",TK_LE},
  {">=",TK_GE},
  {"==", TK_EQ},
  {"!=",TK_NEQ},

  {"(0x)?[0-9]+",TK_NUM},	//可以匹配0x开头的数字
  {"\\$\\w*",TK_REG},		//匹配以$开头的regitser name
};

static word_t eval(int p,int q,bool *success);
static word_t return_num(int i,bool *success);
int find_major(int p ,int q);
bool check_parentheses(int p ,int q);
static word_t Count2(word_t val1,int op,word_t val2,bool *success);
static word_t Count1(int op,word_t val,bool *success);
static word_t return_num(int i,bool *success);

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

#define special_type(type,types) specialtype(type,types,ARRLEN(types))
static int type1[] = {TK_NEG,TK_DEREF,TK_POS};//-，*,+
static int type2[] = {')',TK_NUM,TK_REG};
static int type3[] = {'(',')',TK_NUM,TK_REG};

static bool specialtype(int type,int types[],int size) {
  for(int i = 0;i<size;i++){
	if(type == types[i]) return true;
  }
  return false;
}

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        position += substr_len;

		    if (rules[i].token_type == TK_NOTYPE) break;//丢弃空格
		    tokens[nr_token].type = rules[i].token_type;//记录类型
        //
        switch (rules[i].token_type) {
	         case TK_NUM : case TK_REG:
	      	    strncpy(tokens[nr_token].str,substr_start,substr_len);//将数字和字符内容记录在str中
	      	    tokens[nr_token].str[substr_len] = '\0';
	      	    break;
	      	case '*' : case '-' : case '+':
		    	    if(nr_token == 0 || !special_type(tokens[nr_token-1].type,type2)){
		    	    switch(rules[i].token_type)
		    	    {
		    	      case '*' :tokens[nr_token].type = TK_DEREF;break;
		    	      case '-' :tokens[nr_token].type = TK_NEG;break; 
		    	      case '+' :tokens[nr_token].type = TK_POS;break;
		    	    }
		          }
		      break;
         }

		   nr_token++;//已经被识别出的token数目+1
       break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  return eval(0,nr_token-1,success);
}

//一元运算
static word_t Count1(int op,word_t val,bool *success) {
	switch(op) {
		case TK_NEG : return -val;
		case TK_DEREF:return vaddr_read(val,4);
		case TK_POS : return val;
		default : *success = false;
	}
	return 0;
}

//二元运算
static word_t Count2(word_t val1,int op,word_t val2,bool *success) {
	switch(op) {
		case '+' : return val1 + val2;
		case '-' : return val1 - val2;
		case '*' : return val1 * val2;
		case '/' : if(val2 == 0) {
				*success = false;
				return 0;
		} 
		return (sword_t)val1 / (sword_t)val2;
		case TK_AND : return val1 && val2;
		case TK_OR :  return val1 || val2;
		case TK_EQ :  return val1 == val2;
		case TK_NEQ : return val1 != val2;
		case TK_GT :  return val1 > val2 ;
		case TK_LT :  return val1 < val2 ;
		case TK_GE :  return val1 >= val2;
		case TK_LE :  return val1 <= val2;

		default:*success = false ; 
			return 0;
	}
} 

//此函数用于返回对应的数值
static word_t return_num(int i,bool *success) {
	switch(tokens[i].type) {
		case TK_NUM :
		  if(strncmp("0x",tokens[i].str,2) == 0) {
		  	return strtol(tokens[i].str,NULL,16);
		  } else {
			return strtol(tokens[i].str,NULL,10);
		  }
		case TK_REG :
		  	return isa_reg_str2val(tokens[i].str,success);//根据讲义使用准备好的API,返回寄存器的值
		default:
		  *success = false;
		  return 0;
	}
}

//p、q分别为子表达式的开始和结束位置,此函数为求值函数
static word_t eval(int p,int q,bool *success){

  *success = true;

  if(p>q){
	//Bad expression
	*success = false;
	return 0;
  } else if (p == q) {
	//Single token.For now this token should be a number.Return the value of the number.
	return return_num(p,success);
  } else if (check_parentheses(p,q) == true) {
	//The expression is surrounded by a matched pair of parentheses.If that is the case, just throw away the parentheses.
	return eval(p+1,q-1,success);
  } else {

	int major = find_major(p,q);
	if(major < 0) {
		*success = false;
		return 0;
	}

	//对分裂出来的两个子表达式进行递归求值
	bool success1,success2;
	//右优先级
	int32_t val2 = eval(major+1,q,&success2);
	word_t val1 = eval(p,major-1,&success1);

	//整体表达式的success必须建立在右表达式的success上,左表达式false归入一元运算符中,如-1
	if(!success2){
	  *success = false;
	  return 0;
	}	

	if(success1) {
	  word_t ret = Count2(val1,tokens[major].type,val2,success);//左T右T为二元运算
	  return ret;
	} else {
	  int32_t ret = Count1(tokens[major].type,val2,success);//左F右T为一元运算
	  return ret;
	}	
  }
}

int find_major(int p ,int q) {

  int ret = -1;
  int par = 0;	   //括号的数量
  int op_type = 0; //当前找到的最高优先级的运算符类型

  for (int i = p;i <= q; i++) {
	if(tokens[i].type == '(') {
		par ++;
	} else if (tokens[i].type == ')') {
		if(par == 0){ return -1;}
		par--;
	} else if(special_type(tokens[i].type,type3)){
		continue;
	} else if (par > 0) {
		continue;	//par>0说明在括号内
	} else {//运算优先级
  	int tmp_type = 0;//运算符的等级
		switch(tokens[i].type) {
				case TK_OR : tmp_type++;
				case TK_AND : tmp_type++; 
				case TK_EQ : case TK_NEQ :tmp_type++;
				case TK_LT: case TK_GT  : case TK_GE : case TK_LE  : tmp_type++;
				case '+': case '-':tmp_type++;
				case '*': case '/' :tmp_type++;
				case TK_DEREF : case TK_NEG : case TK_POS : tmp_type++;
				     break;
				default: return -1;
		}
		//非type中的指针解和负数类型
		if(tmp_type > op_type || (tmp_type == op_type && !special_type(tokens[i].type,type1))) {
			op_type = tmp_type;
			ret = i;
		}
	}
  }
  if(par != 0) return -1;//找不到主运算符
  return ret;
}

bool check_parentheses(int p ,int q) {
  if(tokens[p].type == '(' &&tokens[q].type == ')') {
	int count = 0;//count 记录有多少个未匹配的左括号
	int i;
	for(i = p;i<= q;i++) {
		if(tokens[i].type == '(') count ++;
		else if(tokens[i].type == ')') count --;
	
		if(count == 0) return i==q;
	}
  }
  return false;
}
