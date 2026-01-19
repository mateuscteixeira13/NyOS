#include <stdbool.h>

void itoa(int value, char *buffer, int base){

    bool is_negative = false;
    int temp;
    int i = 0;

    if (value == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }

    if (value < 0) {
        is_negative = true;
    }

    while (value != 0){
        temp = -(value % base);
        value = value / base;

        if (temp < 10){
            buffer[i] = '0' + temp;
        } else {
            buffer[i] = 'A' + (temp - 10);
        }

        i++;
    }

    if (is_negative == true){
        buffer[i] = '-';
        i++;
    }

    char stemp;
    int start = 0;
    int end = i - 1;

    while (start < end)
    {
        stemp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = stemp;
        start++;
        end--;
    }

    buffer[i] = '\0';
}
