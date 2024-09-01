#ifndef DEMONIST_H
#define DEMONIST_H
#include "SDL2/SDL.h"
#include <time.h>
#include <unistd.h>

#include "config.h"
#define ASPECT_RATIO 4
typedef struct{ int x,y; }vect;

// ass.c
void load_sprites(SDL_Renderer* rdr, SDL_Texture** t_char, SDL_Texture*** t);

// draw.c
void draw(SDL_Renderer* renderer, int win_h, int win_w,
		vect plpos, SDL_Texture* t_char,
		int zone[7][17], SDL_Texture** t);
void draw2(SDL_Renderer* renderer, int win_h, int win_w,
		vect plpos, SDL_Texture* t_char,
		int zone[7][17], SDL_Texture** t);

// logic.c
typedef struct { int up,left,down,right; } Keys;
void keydown(int sym, Keys* keys);
void keyup(int sym, Keys* keys);

// player.c
void player_movement(Keys* keys, vect* plpos, int zone[7][17],
		int collidables[11], int ncoll, int* redraw);
void player_movement2(Keys* keys, vect* plpos, int zone[7][17],
		int coll[14][17], int* redraw);
#endif
