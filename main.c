
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
    snake_movment();
    which_apple();
    place_apple();

   while (1)
    {
        keyboard();
        snake_movment();
        reset();
        draw_maps();
        Sleep(150);

    }

    return 0;
}