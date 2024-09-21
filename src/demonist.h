#ifndef DEMONIST_H
#define DEMONIST_H
#include "SDL2/SDL.h"
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "config.h"
#define ASPECT_RATIO 4
typedef struct{ int x,y; }vect;

// ass.c
void load_sprites(SDL_Renderer* rdr, SDL_Texture** t_char, SDL_Texture*** t);

typedef struct{ int w,h,**m; }ZONE;
ZONE* get_zone1(void);
void free_zone1(ZONE* zone);
int** get_coll1(void); // for solution 2
void free_coll1(int** coll,int h);

// draw.c
void draw(SDL_Renderer* renderer, int win_h, int win_w,
		vect plpos, SDL_Texture* t_char,
		ZONE* zone, SDL_Texture** t);
void draw2(SDL_Renderer* renderer, int win_h, int win_w,
		vect plpos, SDL_Texture* t_char,
		ZONE* zone, SDL_Texture** t);

// logic.c
typedef struct { int up,left,down,right; } Keys;
void keydown(int sym, Keys* keys);
void keyup(int sym, Keys* keys);

// player.c
void player_movement(Keys* keys, vect* plpos, ZONE* zone,
		int collidables[11], int ncoll,
		struct timespec* clk_move_start, int* redraw);
void player_movement2(Keys* keys, vect* plpos,
		int** coll, int* redraw);
#endif
