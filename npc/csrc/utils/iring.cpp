#include "utils/iringbuf.h"
#include "common.h"

void init_ringbuf(RingBuffer *ringbuf){
	ringbuf->head = 0;
	ringbuf->tail = 0;
	ringbuf->count = 0;
	ringbuf->c_idx = 0;
	for (int i = 0; i< RING_BUFFER_SIZE; ++i){
		ringbuf->entries[i].pc = 0;
		ringbuf->entries[i].inst = 0;
		memset(ringbuf->entries[i].inst_str,0,sizeof(ringbuf->entries[i].inst_str));
	}
}

void add_to_ringbuffer(RingBuffer *ringbuf,uint32_t pc,uint32_t inst){
	if (ringbuf->count == RING_BUFFER_SIZE) { 
		ringbuf->tail = (ringbuf->tail + 1) % RING_BUFFER_SIZE;
	}else{
		ringbuf->count++;
	}

	int idx = ringbuf->head;
	ringbuf->head = (ringbuf->head + 1) % RING_BUFFER_SIZE;

	ringbuf->c_idx = idx;

	ringbuf->entries[idx].pc = pc;
	ringbuf->entries[idx].inst = inst;

	uint8_t code[4];
	memcpy(code, &inst,sizeof(inst));

	void disassemble(char *str,int size,uint64_t pc, uint8_t *code,int nbype);
	uint64_t pc_trans = pc;
	disassemble(ringbuf->entries[idx].inst_str,sizeof(ringbuf->entries[idx].inst_str),pc_trans,code,sizeof(code));
}

void print_ringbuf(RingBuffer *ringbuf){
	int idx = ringbuf->tail;
	for (int i = 0; i< ringbuf->count; ++i) {
		if(idx == ringbuf->c_idx){
			printf("\t      -->|  ");
		} else {
			printf("\t	 |  ");
		}
		printf("0x%08x: %s\n",ringbuf->entries[idx].pc,ringbuf->entries[idx].inst_str);

		idx = (idx + 1) % RING_BUFFER_SIZE;
	}
}
