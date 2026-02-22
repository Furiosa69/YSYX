#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000
static uint32_t keycode;

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
		keycode = inl(KBD_ADDR);
		kbd->keydown = (keycode & KEYDOWN_MASK) ? true : false;  
    kbd->keycode = (keycode != AM_KEY_NONE) ? (keycode&~KEYDOWN_MASK) : AM_KEY_NONE;
}
