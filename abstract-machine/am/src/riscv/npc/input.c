#include <am.h>

#define DEVICE_BASE 0xa0000000
#define KBD_ADDR        (DEVICE_BASE + 0x0000060)
#define KEYDOWN_MASK 0x8000
static uint32_t keycode;

static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }
void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
		keycode = inl(KBD_ADDR);
		kbd->keydown = (keycode & KEYDOWN_MASK) ? true : false;  
    kbd->keycode = (keycode != AM_KEY_NONE) ? (keycode&~KEYDOWN_MASK) : AM_KEY_NONE;
}
