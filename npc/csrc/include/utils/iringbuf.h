#ifndef __IRINGBUF_H__
#define __IRINGBUF_H__

#define RING_BUFFER_SIZE 128
#include <cstdint>

void init_disasm(const char *triple);

typedef struct {  
  uint32_t pc;
  uint32_t inst;
  char inst_str[128];
} RingBufferEntry;

typedef struct {
  int head;
  int tail;
  int count;
  int c_idx;
  RingBufferEntry entries[RING_BUFFER_SIZE];
} RingBuffer;


void init_ringbuf(RingBuffer *ringbuf);
void add_to_ringbuffer(RingBuffer *ringbuf,uint32_t pc,uint32_t inst);
void print_ringbuf(RingBuffer *ringbuf);

#endif
