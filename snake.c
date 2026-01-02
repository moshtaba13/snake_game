
#include <stdio.h>
#include <conio.h>

#include "snake.h"
#include "map.h"
#include "menu.h"

#define MAX 100


int x = WIDTH / 2, 
y = HEIGHT / 2;

int length = 1, key = 3, score = 0;

int gameover = 1;

int snakex[MAX], snakey[MAX];

void keyboard() {
    if (kbhit()) {
        switch (getch())
        {
        case 'w':
            y--;
            key = 1;
            break;

        case 's':
            y++;
            key = 2;
            break;
        
        case 'd':
            x++;
            key = 3;
            break;
        
        case 'a':
            x--;
            key = 4;
            break;

        case 'x':
            
            menu_maps();
            break;
        
        default:
            break;
        }
    }

    else {
        switch (key)
        {
        case 1:
            y--;
            break;
 
        case 2:
            y++;
            break;
        
        case 3:
            x++;
            break;
        
        case 4:
            x--;
            break;
               
        default:
            break;
        }
    }
}

void snake_movment() {

    if (x == applex && y == appley) {

        if (apple == 1) 
            score += 3;
        
        else {
            score++;
            length++;
        }
        
        which_apple();
        place_apple();

    }

  
    for (int i = length - 1; i > 0; i--) {
        snakex[i] = snakex[i - 1];
        snakey[i] = snakey[i - 1];
    }

    snakex[0] = x;
    snakey[0] = y;

    for (int i = 1; i < length; i++) {
        if (snakex[i] == x && snakey[i] == y)
            gameover = 0;
    }
    
    if (map[y][x] == '#') {
        gameover = 0;
    }

}

int draw_snake(int i, int j) {
    for(int k = 0; k < length; k++) {
        if (snakex[k] == j && snakey[k] == i) {
            return 1;
        }
    }

    return 0;
}
