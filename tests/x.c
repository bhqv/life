#include <stdio.h>
#include <unistd.h>
#include "asciii.h"

void ex1(void){

    clear_screen();

    usleep(1000000);
    move_cursor(1, 2);
    printf("*");
    fflush(stdout);

    usleep(1000000);
    move_cursor(5, 12);
    printf("*");
    fflush(stdout);
    usleep(1000000);

    move_cursor(23, 21);
    printf("*");
    fflush(stdout);
    usleep(1000000);

    move_cursor(4, 2);
    printf("*");
    fflush(stdout);
}

void ex2(void){

    int x = 10;
    int y = 10;


    while(1){
        clear_screen();

        move_cursor(x, y);

        printf("o");
        fflush(stdout);

        x++;
        y++;

        usleep(300000);
    }
}


int main () {

    ex2();

}
