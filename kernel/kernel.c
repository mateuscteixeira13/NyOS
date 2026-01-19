#include <kstd.h>
#include <hal.h>
#include <vga.h>

int init(){
    __VGA();

    printf("NyOS booted!");
}

void kernel_main(){
    init();

    while(1){
        Halt();
    }
}