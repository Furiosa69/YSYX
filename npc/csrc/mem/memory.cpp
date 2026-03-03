#include "mem/memory.h"
#include "utils/difftest.h"
#include "common.h"
#include "main.h"
#include <fcntl.h>
#include <chrono>
#include <SDL2/SDL.h>

extern "C" void flash_read(int32_t addr,int32_t *data){assert(0);}
extern "C" void mrom_read(int32_t addr,int32_t *data){assert(0);}

uint8_t memory[MEMORY_SIZE];

IFONE(CONFIG_MTRACE,
	FILE *mtrace_file= fopen(TRACE_DIR "trace_mtrace.txt","a");
	#define LOG_TRACE_READ(addr ,len, data)  fprintf(mtrace_file, "TRACE:Read  %d bytes from 0x%x, data = 0x%x\n", len, addr, data)
	#define LOG_TRACE_WRITE(addr, len, data) fprintf(mtrace_file, "TRACE:Write %d bytes to   0x%x, data = 0x%x\n", len, addr, data)

	void close_mtracelog_file(){
	  if(mtrace_file != NULL){
	    fclose(mtrace_file);
	  }
	}
)

uint8_t* guest_to_host(uint32_t paddr) { return memory + paddr - CONFIG_MBASE; }
uint32_t host_to_guest(uint8_t *haddr) { return haddr - memory + CONFIG_MBASE; }

// ---------------- timer ------------------------------------
static const auto startup_time = std::chrono::steady_clock::now();

uint64_t get_uptime_us() {
    auto now = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(now - startup_time);
    return duration.count();
}

// --------------- gpu ---------------------------------------
uint32_t vga_ctl_reg = 0;
uint32_t *framebuffer = NULL;
uint32_t screen_width = 0;
uint32_t screen_height = 0;
#define SCREEN_W 400
#define SCREEN_H 300

static uint32_t screen_size() {
    return screen_width * screen_height * sizeof(uint32_t);
}

static void *vmem = NULL;
static uint32_t *vgactl_port_base = NULL;

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

static void init_screen() {
    SDL_Window *window = NULL;
    char title[128];
    sprintf(title, "riscv32-NPC");
    SDL_Init(SDL_INIT_VIDEO);
    
    int scale = 2;
    SDL_CreateWindowAndRenderer(
        SCREEN_W * scale,
        SCREEN_H * scale,
        0, &window, &renderer);
    
    SDL_SetWindowTitle(window, title);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STATIC, SCREEN_W , SCREEN_H);
    SDL_RenderPresent(renderer);
}

static inline void update_screen() {
  SDL_UpdateTexture(texture, NULL, vmem, SCREEN_W * sizeof(uint32_t));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}

void vga_update_screen() {
    if (vgactl_port_base && vgactl_port_base[1]) {
        update_screen();
        vgactl_port_base[1] = 0;
    }
}

void init_vga() {
    init_screen();
    
    if (framebuffer == NULL) {
        framebuffer = new uint32_t[SCREEN_W * SCREEN_H];
        memset(framebuffer, 0, SCREEN_W * SCREEN_H * sizeof(uint32_t)); 
    }
    
    if (vmem == NULL) {
				size_t size = screen_size();
        //vmem = malloc(size);
        //memset(vmem, 0, size); 
				vmem = calloc(SCREEN_W * SCREEN_H, sizeof(uint32_t));
    }
}

// ---------------- mmio ---------------------------------------
uint32_t mmio_read(uint32_t addr_in, int size) {
		uint32_t addr = addr_in & ~0x3u;

    switch (addr) {
				case RTC_ADDR_low :
				case RTC_ADDR_high: {
				    uint64_t microseconds = get_uptime_us();
				    if (addr == RTC_ADDR_low) {
				        return microseconds & 0xFFFFFFFF;  // 低32位
            IFONE(CONFIG_MTRACE,LOG_TRACE_READ(addr, size, microseconds & 0xFFFFFFFF);)
				    } else {
				        return (microseconds >> 32) & 0xFFFFFFFF;  // 高32位
            IFONE(CONFIG_MTRACE,LOG_TRACE_READ(addr, size, (microseconds >> 32) & 0xFFFFFFFF);)
				    }
				}
				case VGACTL_ADDR_high:
				case VGACTL_ADDR: {
						IFONE(CONFIG_MTRACE,LOG_TRACE_READ(addr, size, vga_ctl_reg);)
						return vga_ctl_reg;
				}
				case FB_ADDR: {
						if (framebuffer == NULL) {
							std::cerr << "Error: Framebuffer not initialized" << std::endl;
                return 0;
            }
						uint32_t pixel_index = (addr_in - FB_ADDR) / 4;
            if (pixel_index < screen_width * screen_height) {
                uint32_t value = framebuffer[pixel_index];
                IFONE(CONFIG_MTRACE, LOG_TRACE_READ(addr, size, value);)
                return value;
            } else {
                std::cerr << "Error: Framebuffer read out of bounds" << std::endl;
                return 0;
            }
				}
        default:
            std::cerr << "Error: Unknown device address read 0x" << std::hex << addr << std::endl;
            return 0;
    }
}

void mmio_write(uint32_t addr_in, uint32_t data, uint wstrb) {
    uint32_t addr = addr_in & ~0x3u;  // 对齐到4字节边界
    
    switch (addr) {
        case SERIAL_PORT: {
            if (wstrb & 0b0001) {
                uint8_t ch = data & 0xFF;
                putc(ch, stderr);
                IFONE(CONFIG_MTRACE, {
                    LOG_TRACE_WRITE(addr_in, 1, ch);
                });
            }
            break;
        }
        
        case VGACTL_ADDR_high:
        case VGACTL_ADDR: {
            if (wstrb == 0b1111) {  // 所有字节都使能
                vga_ctl_reg = data;
                screen_height = data & 0xFFFF;      
                screen_width = (data >> 16) & 0xFFFF; 
                
                if (framebuffer == NULL && screen_width > 0 && screen_height > 0) {
                    framebuffer = new uint32_t[screen_width * screen_height];
                    for (int i = 0; i < screen_width * screen_height; i++) {
                        framebuffer[i] = 0;
                    }
                }
                
                IFONE(CONFIG_MTRACE, {
                    LOG_TRACE_WRITE(addr_in, 4, data);
                });
            }
            else {
                for (int i = 0; i < 4; i++) {
                    if (wstrb & (1 << i)) {
                        uint8_t byte = (data >> (i * 8)) & 0xFF;
                        uint32_t shift = i * 8;
                        vga_ctl_reg = (vga_ctl_reg & ~(0xFF << shift)) | (byte << shift);
                    }
                }
                screen_height = vga_ctl_reg & 0xFFFF;
                screen_width = (vga_ctl_reg >> 16) & 0xFFFF;
                
                if (framebuffer == NULL && screen_width > 0 && screen_height > 0) {
                    framebuffer = new uint32_t[screen_width * screen_height];
                    for (int i = 0; i < screen_width * screen_height; i++) {
                        framebuffer[i] = 0;
                    }
                }
            }
            break;
        }
        
        case FB_ADDR: {
            if (framebuffer == NULL) {
                std::cerr << "Error: Framebuffer not initialized" << std::endl;
                return;
            }
            
            uint32_t pixel_index = (addr_in - FB_ADDR) / 4;
            uint32_t byte_offset = (addr_in - FB_ADDR) % 4;
            
            if (pixel_index < screen_width * screen_height) {
                for (int i = 0; i < 4; i++) {
                    if (wstrb & (1 << i)) {
                        uint8_t byte = (data >> (i * 8)) & 0xFF;
                        uint32_t shift = (byte_offset + i) * 8;
                        if (shift < 32) {  // 确保不超过32位
                            framebuffer[pixel_index] = 
                                (framebuffer[pixel_index] & ~(0xFF << shift)) | 
                                (byte << shift);
                        }
                    }
                }
                
                IFONE(CONFIG_MTRACE, {
                    LOG_TRACE_WRITE(addr_in, wstrb, data);
                });
            } else {
                std::cerr << "Error: Framebuffer write out of bounds at index " 
                          << pixel_index << std::endl;
            }
            break;
        }
        
        default:
            std::cerr << "Error: Unknown device address write 0x" << std::hex << addr 
                      << " with wstrb=" << std::bitset<4>(wstrb) << std::endl;
    }
}

// ------------------------ pmem -----------------------------
uint32_t pmem_read(uint32_t addr, int size) {

		if( addr >= DEVICE_BASE ) {
				difftest_skip_ref();
				return mmio_read(addr, size);
		}

    if ((size == 2 && addr % 2 != 0) || (size == 4 && addr % 4 != 0)) {
        std::cerr << "Error: Read Address is not " << size << "-byte aligned" << std::endl;
        return 0;
    }

    size_t offset = (addr - 0x80000000);

    if (offset + size > sizeof(memory)) {
        return 0;
    }

    switch (size) {
        case 1:{
						uint32_t data1 = static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(&memory[offset]));
						IFONE(CONFIG_MTRACE,LOG_TRACE_READ(addr ,size, data1);)
            return data1;
				}
        case 2:{
            uint32_t data2 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(&memory[offset]));
						IFONE(CONFIG_MTRACE,LOG_TRACE_READ(addr ,size, data2);)
						return data2;
				}
        case 4:{
            uint32_t data4 = static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(&memory[offset]));
						IFONE(CONFIG_MTRACE,LOG_TRACE_READ(addr ,size, data4);)
						return data4;
				}
        default:
            std::cerr << "Error: Invalid size " << size << " (must be 1, 2, or 4)" << std::endl;
            return 0;
    }
}

void pmem_write(uint32_t addr, uint32_t data, uint32_t wstrb) {
    if (addr >= DEVICE_BASE) {
        difftest_skip_ref();
        mmio_write(addr, data, wstrb);  
        return;
    }
    
    size_t offset = (addr - 0x80000000);
    
    if (offset + 4 > sizeof(memory)) {  // 最多写入4字节
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (wstrb & (1 << i)) {
            uint32_t byte_addr = addr + i;
            size_t byte_offset = offset + i;
            uint8_t byte_data = (data >> (i * 8)) & 0xFF;
            
            memory[byte_offset] = byte_data;
            
            IFONE(CONFIG_MTRACE, {
                LOG_TRACE_WRITE(byte_addr, 1, byte_data);
            });
        }
    }
}

bool loadFileToMemory(const std::string& path, uint8_t* mem, size_t size) {
    std::ifstream file(path, std::ios::binary);   
    if (!file) {
        std::cerr << "无法打开文件: " << path << std::endl;
        return false;
    }
    file.read(reinterpret_cast<char*>(mem), size);
    return true;
}

void init_mem() {
  memset(memory, rand(), MEMORY_SIZE);
}

