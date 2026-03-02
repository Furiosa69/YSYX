#ifndef __FTRACE_H__
#define __FTRACE_H__

void init_ftrace();
void print_all_function_names(uint32_t current_pc,uint32_t target_pc,uint32_t inst);
void end_ftrace();

#endif
