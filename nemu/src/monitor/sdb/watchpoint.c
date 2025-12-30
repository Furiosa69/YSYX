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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  word_t old;//讲义默认32位无符号数
  char expr[512];
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

//申请新监视点
static WP* new_wp() {
  if(free_ == NULL) {
	printf("No free watchpoint!");
	assert(free_);
  }
  WP* ret = free_;//向free请求结点
  free_ = free_->next;//free指向下一个结点
  ret->next = head;//结点分配给head
  head = ret;
  return ret;
}

//归还监视点给free
void free_wp(WP *wp) {
  WP* h = head;
  if(h == wp) head = NULL;
  else {
			while(h && h->next != wp) h = h->next;
			assert(h);
			h->next = wp->next;
  }
  wp->next = free_;
  free_ = wp;
}

//开启监视点
void wp_watch(char *args,word_t res) {
  WP* wp = new_wp();
  strcpy(wp->expr,args);
  wp->old = res;
  printf("Watchpoint %d: %s\n",wp->NO,wp->expr);
}
//删除监视点
void wp_remove(int no) {
  assert (no < NR_WP);
  WP* wp = &wp_pool[no];
  free_wp(wp);
  printf("Delete watchpoint %d: %s\n",wp->NO,wp->expr);
}
//打印监视点
void wp_iterate() {
  WP* h = head;
  if(!h) {
	printf("No watchpoints.\n");
	return;
  }
  while(h) {
	printf("%8d %8s\n",h->NO,h->expr);
	h = h->next;
  }
}
//不相等则触发信息
void wp_check() {
  WP* h = head;
  while (h) {
	bool success;
	word_t new = expr(h->expr,&success);
	if(h->old != new) {
	  printf("Watchpoint %d: %s \tOld value = %x \tNew value = %x\n",h->NO,h->expr,h->old,new);
	  nemu_state.state = NEMU_STOP;//触发监视点暂停
	  h->old = new;
	}
	h = h->next;
  }
}

