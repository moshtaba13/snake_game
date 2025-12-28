
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "map.h"
#include "menu.h"

int main()
{
    srand(time(NULL));
    printf("welcome to snake game!\n");

    enter();
    menu_game();

    place_apple();
    draw_maps();

    return 0;
}