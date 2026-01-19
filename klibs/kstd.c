#include <stdarg.h>
#include <stddef.h>
#include <klib.h>
#include <vga.h>

void puts(const char *str){
    writel(str);
}

void putc(char c){
    writec(c);
}

int printf(const char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);

    char buffer[1024];

    while (*fmt != '\0'){
        if(*fmt == '%'){
            fmt++;
            switch (*fmt){
              case 'd':
              int itemp = va_arg(ap, int);
              itoa(itemp, buffer, 10);
              puts(buffer);
              break;
              case 's':
              char* stemp = va_arg(ap, char*);
              if(stemp == NULL){
                puts("null");
              }
              while (*stemp != 0){
                putc(*stemp);
                stemp++;
              }
              break;
              default:
              putc('?');
              break;
            } 
        } else { 
            putc(*fmt);
        }
        
        fmt++;
    }
    
    va_end(ap);
    return 0;
}