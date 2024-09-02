#include "demonist.h"

void draw2(SDL_Renderer* rdr, int win_w, int win_h,
		vect plpos2, SDL_Texture* t_char,
		ZONE* zone, SDL_Texture** t){
SDL_RenderClear(rdr);
// drawing scenery
int win_sprites_w = win_w/12/ASPECT_RATIO +2;
int win_sprites_h = win_h/24/ASPECT_RATIO +2;
vect corner = (vect){ plpos2.x -win_sprites_w/2,
		plpos2.y/2 -win_sprites_h/2 };
vect offset = (vect){ win_w%(12*ASPECT_RATIO)/2,
		win_h%(24*ASPECT_RATIO)/2 };
if (plpos2.y%2) offset.y += 12*ASPECT_RATIO;
for (int i =0; i <win_sprites_w; i++){
for (int j =0; j <win_sprites_h; j++){
if (corner.x+i>=0 && corner.y+j>=0 && corner.x+i<zone->w && corner.y+j<zone->h){
	SDL_Rect draw_r = (SDL_Rect){
		i*12*ASPECT_RATIO -offset.x,
		j*24*ASPECT_RATIO -offset.y,
		12*ASPECT_RATIO,24*ASPECT_RATIO };
	SDL_RenderCopy(rdr, t[zone->m[corner.y+j][corner.x+i]-1], NULL, &draw_r);
}}}
// drawing char
if (plpos2.y%2) offset.y -= 12*ASPECT_RATIO;
SDL_Rect draw_r = (SDL_Rect){
		win_sprites_w/2*12*ASPECT_RATIO-offset.x,
		win_sprites_h/2*24*ASPECT_RATIO-offset.y,
		12*ASPECT_RATIO,24*ASPECT_RATIO };
SDL_RenderCopy(rdr, t_char, NULL, &draw_r);
SDL_RenderPresent(rdr);
}
