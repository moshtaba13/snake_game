
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "map.h"

# define HEIGHT 20
# define WIDTH 40

int applex, appley;

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

int which_apple() {
    int chance = rand() % 10 ;

    if (chance == 5)
        return 1;        
    
    else
        return 0;
}

void place_apple() {
    applex = rand() % WIDTH;
    appley = rand() % HEIGHT;

    if (applex == 0 )
        applex = rand() % WIDTH;
    
    if (appley == 0)
        appley = rand() % HEIGHT;

}

void draw_maps() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (map[i][j] == '#')
                printf("█");
            
            else if (i == appley && j == applex) {
                if (which_apple())
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




