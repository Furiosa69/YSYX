#include "mem/memory.h"
#include "utils/difftest.h"
#include "common.h"
#include "main.h"
#include "TOP_DPI.h"     
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


uint8_t* guest_to_host(uint32_t paddr) { return memory + paddr - CONFIG_MBASE; }
uint32_t host_to_guest(uint8_t *haddr) { return haddr - memory + CONFIG_MBASE; }

uint32_t vaddr_ifetch(uint32_t addr, int len) {
  return pmem_read(addr, len);
}

uint32_t vaddr_read(uint32_t addr, int len) {
  return pmem_read(addr, len);
}

void vaddr_write(uint32_t addr, int len, uint32_t data) {
  pmem_write(addr, data,len );
}                

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

void mmio_write(uint32_t addr_in, uint32_t data, int size) {
		uint32_t addr = addr_in & ~0x3u;
    switch (addr) {
        case SERIAL_PORT: {
            if (size == 1) {
								putc(data & 0xFF, stderr);
            }
            IFONE(CONFIG_MTRACE,LOG_TRACE_READ(addr, size, data);)
            break;
				}
				case VGACTL_ADDR_high:
				case VGACTL_ADDR: {
            // 设置VGA控制寄存器，触发屏幕同步
            vga_ctl_reg = data;
            screen_height = data & 0xFFFF;      
            screen_width = (data >> 16) & 0xFFFF; 
            
            if (framebuffer == NULL && screen_width > 0 && screen_height > 0) {
                framebuffer = new uint32_t[screen_width * screen_height];
                for (int i = 0; i < screen_width * screen_height; i++) {
                    framebuffer[i] = 0;
                }
            }
            
            IFONE(CONFIG_MTRACE, LOG_TRACE_WRITE(addr, size, data);)
            break;
        } 
        case FB_ADDR: {
            if (framebuffer == NULL) {
                std::cerr << "Error: Framebuffer not initialized" << std::endl;
                return;
            }
            
            uint32_t pixel_index = (addr_in - FB_ADDR) / 4;
            if (pixel_index < screen_width * screen_height) {
                framebuffer[pixel_index] = data;
                IFONE(CONFIG_MTRACE, LOG_TRACE_WRITE(addr, size, data);)
            } else {
                std::cerr << "Error: Framebuffer write out of bounds" << std::endl;
            }
            break;
        } 
        default:
            std::cerr << "Error: Unknown device address write 0x" << std::hex << addr << std::endl;
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


void pmem_write(uint32_t addr, uint32_t data, int size) {
		if (addr >= DEVICE_BASE) {
			 difftest_skip_ref();
			 mmio_write(addr, data, size);		
			 return;
		}

    if ((size == 2 && addr % 2 != 0) || (size == 4 && addr % 4 != 0)) {
        std::cerr << "Error: Write Address is not " << size << "-byte aligned" << std::endl;
        return;
    }

    size_t offset = (addr - 0x80000000);
    
		if (offset + size > sizeof(memory)) {
        return;
    }

    switch (size) {
        case 1:{
						uint8_t data1 = static_cast<uint8_t>(data);
						IFONE(CONFIG_MTRACE,LOG_TRACE_WRITE(addr, size, data1);)
            *reinterpret_cast<uint8_t*>(&memory[offset]) = data1;
            break;
				}
        case 2:{
						uint16_t data2 = static_cast<uint16_t>(data);
						IFONE(CONFIG_MTRACE,LOG_TRACE_WRITE(addr, size, data2);)
            *reinterpret_cast<uint16_t*>(&memory[offset]) = data2;
            break;
				}
        case 4:{
						uint32_t data4 = static_cast<uint32_t>(data);
						IFONE(CONFIG_MTRACE,LOG_TRACE_WRITE(addr, size, data4);)
            *reinterpret_cast<uint32_t*>(&memory[offset]) = data4;
            break;
				}
        default:
            std::cerr << "Error: Invalid size " << size << " (must be 1, 2, or 4)" << std::endl;
            return;
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

