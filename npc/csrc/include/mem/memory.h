#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <fstream>
#include "config/config.h"
#include <cstdint>

#define MEMORY_SIZE 					 (1024 * 1024 * 1024)
#define CONFIG_PC_RESET_OFFSET 0
#define CONFIG_MBASE  				 0x80000000
#define PMEM_LEFT  						 ((uint32_t)CONFIG_MBASE)
#define PMEM_RIGHT 						 ((uint32_t)CONFIG_MBASE + MEMORY_SIZE - 1)
#define RESET_VECTOR 					 (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)      

extern uint8_t memory[MEMORY_SIZE];

uint32_t vaddr_ifetch(uint32_t addr ,int len);
uint32_t vaddr_read(uint32_t addr , int len);
void vaddr_write(uint32_t addr, int len, uint32_t data);
uint8_t* guest_to_host(uint32_t paddr);
uint32_t host_to_guest(uint8_t *haddr);
void close_mtracelog_file();
void init_vga();
void vga_update_screen();

extern "C" uint32_t pmem_read(uint32_t addr, int size);
extern "C" void pmem_write(uint32_t addr, uint32_t data, int size);

bool loadFileToMemory(const std::string& path, uint8_t* mem, size_t size);

#endif
