#include <am.h>
#include <klib-macros.h>
#include <stdio.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

#define DEVICE_BASE     0xa0000000
#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }

void putch(char ch) {
	outb(SERIAL_PORT, ch);
}

void halt(int code) {
	asm volatile("ebreak");
  while (1);
}

unsigned long read_mvendorid(void){
	unsigned long result;
	asm volatile ("csrr %0, 0xF11" : "=r"(result));
	return result;
}

unsigned long read_marchid(void){
	unsigned long result;
	asm volatile ("csrr %0, 0xF12" : "=r"(result));
	return result;
}

void write_mvendorid(unsigned long value){
	asm volatile ("csrw 0xF11, %0" : : "r"(value));
}

void write_marchid(unsigned long value){
	asm volatile ("csrw 0xF12, %0" : : "r"(value));
}
void _trm_init() {
//	write_mvendorid(0x79737978);
//	write_marchid(0x16F6E92);
//
//	unsigned long mvendorid_val = read_mvendorid();
//	unsigned long marchid_val   = read_marchid();
//
//	printf("mvendorid is 0x%lx\n",mvendorid_val);
//	printf("marchid is 0x%lx\n",marchid_val);

  int ret = main(mainargs);
  halt(ret);
}
