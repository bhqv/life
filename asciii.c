#include <stdio.h>

void clear_screen(void){
    printf("\033[H\033[J");
}

void move_cursor(int x, int y){
    printf("\033[%d;%dH", y, x);
}

