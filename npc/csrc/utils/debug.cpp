#include "utils/debug.h"
#include "common.h"

// 用来打印内存内容
void dump_memory() {
    std::cout << "Memory contents (hex):" << std::endl;
    for (size_t i = 0; i < MEMORY_SIZE; i += 4) {  // 按4字节打印
        uint32_t value;
        memcpy(&value, &memory[i], sizeof(uint32_t));

        // 打印地址和值                                                                                                                                                      
        std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0')
                  << (0x80000000 + i) << ": 0x"
                  << std::setw(8) << std::setfill('0') << value;

        // 每行打印2个32位字
        if ((i + 4) % 8 == 0) std::cout << std::endl;
        else std::cout << "    ";
    }
    std::cout << std::dec << std::endl;
}

