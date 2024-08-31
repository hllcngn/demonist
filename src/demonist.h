#ifndef DEMONIST_H
#define DEMONIST_H
#include "SDL2/SDL.h"
#include "config.h"
#define ASPECT_RATIO 4
typedef struct{
	int x,y;	}vect;
typedef struct {
	int up,left,down,right;	} Keys;

void load_sprites(SDL_Renderer* rdr, SDL_Texture** t_char, SDL_Texture*** t);
void draw(SDL_Renderer* renderer, int win_h, int win_w,
		vect plpos, SDL_Texture* t_char,
		int zone[7][17], SDL_Texture** t);

void movement_keydown(int sym, Keys* keys);
void movement_keyup(int sym, Keys* keys);
void player_movement(Keys* keys, vect* plpos);
#endif
