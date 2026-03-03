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

#define DEVICE_BASE      0xa0000000   
#define MMIO_BASE        0xa0000000
#define SERIAL_PORT      (DEVICE_BASE + 0x00003f8)
#define KBD_ADDR         (DEVICE_BASE + 0x0000060)
#define RTC_ADDR_low     (DEVICE_BASE + 0x0000048)
#define RTC_ADDR_high    (DEVICE_BASE + 0x000004c)
#define VGACTL_ADDR      (DEVICE_BASE + 0x0000100)
#define VGACTL_ADDR_high (DEVICE_BASE + 0x0000104)
#define AUDIO_ADDR       (DEVICE_BASE + 0x0000200)
#define DISK_ADDR        (DEVICE_BASE + 0x0000300)
#define FB_ADDR          (MMIO_BASE   + 0x1000000)
#define AUDIO_SBUF_ADDR  (MMIO_BASE   + 0x1200000)

extern uint8_t memory[MEMORY_SIZE];

uint8_t* guest_to_host(uint32_t paddr);
uint32_t host_to_guest(uint8_t *haddr);
void close_mtracelog_file();
void init_vga();
void vga_update_screen();

extern "C" uint32_t pmem_read(uint32_t addr, int size);
extern "C" void pmem_write(uint32_t addr, uint32_t data, uint32_t wstrb);

bool loadFileToMemory(const std::string& path, uint8_t* mem, size_t size);

#endif
