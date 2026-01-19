#include <stdint.h>

volatile uint8_t *vga;

void writel(const char *str){
    while (*str){
        *vga++ = *str++;
        *vga++ = 0x07;   
    }
}

void writec(char c){
    *vga++ = c;
    *vga++ = 0x07;   
}

void __VGA(){
    vga = (uint8_t*)0xB8000;
}