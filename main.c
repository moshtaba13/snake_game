
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "map.h"
#include "menu.h"
#include "snake.h"

int main()
{
    srand(time(NULL));
    system("cls");
    printf("welcome to snake game!\n");

    enter();
    menu_game();
    menu_maps();
    which_apple();
    place_apple();
    snake_movment();
    
    while (gameover){
        keyboard();
        snake_movment();
        reset();
        if (gameover)
            draw_maps();
        
        else {
            system("cls");
            printf("========GAMEOVER========\n");
            printf("score:%d",score);
            update_score(score);

        }
        Sleep(150);
    }


    

    return 0;
}