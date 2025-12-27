
#include <stdio.h>
#include "map.h"

# define HEIGHT 20
# define WIDTH 40

char map[HEIGHT][WIDTH];

void map1(void) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH-1)
                map[i][j] = '#';   
            else
                map[i][j] = ' ';   
        }
    }
}

void draw_map1(void) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (map[i][j] == '#')
                printf("█"); 
            else
                printf(" ");
        }
        printf("\n");
        fflush(stdout);
    }
}