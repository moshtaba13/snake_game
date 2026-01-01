
#ifndef MAP_H
#define MAP_H

# define HEIGHT 20
# define WIDTH 40

void map1(void);
void map2(void);

void place_apple(void);
void which_apple(void);
void draw_maps(void);
void reset(void);

extern char map[HEIGHT][WIDTH];
extern int applex, appley, apple;

#endif