
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "map.h"
#include "snake.h"

int applex, appley, apple;

char map[HEIGHT][WIDTH];

void map1() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH-1)
                map[i][j] = '#';   
            else
                map[i][j] = ' ';   
        }
    }
}

void map2() {

    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            map[i][j] = ' ';


    for(int i = 0; i < HEIGHT; i++) {
        map[i][0] = '#';
        map[i][WIDTH-1] = '#';
    }
    for(int j = 0; j < WIDTH; j++) {
        map[0][j] = '#';
        map[HEIGHT-1][j] = '#';
    }

    int midh = HEIGHT / 2;
    for(int j = 0; j < WIDTH; j++) {
        if(j < 15 || j > WIDTH-15) 
            map[midh][j] = '#';
    }
    
    int midw = WIDTH / 2;
    for(int i = 0; i < HEIGHT; i++) {
        if(i < 7 || i > HEIGHT-7)
            map[i][midw] = '#';
    }
}

void which_apple() {
    int chance = rand() % 10 ;

    if (chance == 5)
        apple = 1;      
    
    else
        apple = 0;
}

void place_apple() {
    do {
        applex = rand() % WIDTH;
        appley = rand() % HEIGHT;
    } 
    while (map[appley][applex] == '#');
}

void draw_maps() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (draw_snake(i,j)) 
                printf("0");

            else if (map[i][j] == '#')
                printf("█");
            
            else if (i == appley && j == applex) {
                if (apple == 1)
                    printf("@");
                else
                    printf("*");
            }

            else
                printf(" ");
        }
        printf("\n");
    }
}


void reset() {
    COORD pos = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}




