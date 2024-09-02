#include "demonist.h"
vect get_camera_offset(int win_w, int win_h, vect plpos);
void draw_zone(SDL_Renderer* rdr, int win_w, int win_h, vect up_left,
		vect plpos, ZONE* zone, SDL_Texture** t);
void draw_character(SDL_Renderer* rdr, int win_w, int win_h,
		vect plpos, SDL_Texture* t_char);


vect get_camera_offset(int win_w, int win_h, vect plpos){
int x =plpos.x-(win_w/2-12*ASPECT_RATIO/2);
int y =plpos.y-(win_h/2-24*ASPECT_RATIO/2);
return (vect){x,y};}


void draw(SDL_Renderer* rdr, int win_w, int win_h,
		vect plpos, SDL_Texture* t_char,
		ZONE* zone, SDL_Texture** t){
vect up_left =get_camera_offset(win_w, win_h, plpos);
SDL_RenderClear(rdr);
draw_zone(rdr, win_w, win_h, up_left, plpos, zone, t);
draw_character(rdr, win_w, win_h, plpos, t_char);
SDL_RenderPresent(rdr);}

void draw_zone(SDL_Renderer* rdr, int win_w, int win_h, vect up_left,
		vect plpos, ZONE* zone, SDL_Texture** t){
int i1 = up_left.y/ASPECT_RATIO/24;
if (i1 < 0) i1 = 0; else if (i1 >= zone->h) i1 = zone->h;
int i2 = up_left.y/ASPECT_RATIO/24 + win_h/ASPECT_RATIO/24;
if (i2 >= zone->h) i2 = zone->h; else i2++; //increment to avoiding missing last sprite
int j1 = up_left.x/ASPECT_RATIO/12; //as size of screen
if (j1 < 0) j1 = 0; else if (j1 >= zone->w) j1 = zone->w;
int j2 = up_left.x/ASPECT_RATIO/12 + win_w/ASPECT_RATIO/12;
if (j2 >= zone->w) j2 = zone->w; else j2++; //isn't necessarily a multiple of 12
for (int i =i1; i <i2; i++) for (int j =j1; j <j2; j++){
	SDL_Rect draw_r = (SDL_Rect){j*12*ASPECT_RATIO-up_left.x,
				     i*24*ASPECT_RATIO-up_left.y,
				     12*ASPECT_RATIO,24*ASPECT_RATIO};
	SDL_RenderCopy(rdr, t[zone->m[i][j]], NULL, &draw_r);}}

void draw_character(SDL_Renderer* rdr, int win_w, int win_h,
		vect plpos, SDL_Texture* t_char){
SDL_Rect draw_r = (SDL_Rect){win_w/2-12*ASPECT_RATIO/2,
			     win_h/2-24*ASPECT_RATIO/2,
			12*ASPECT_RATIO,24*ASPECT_RATIO};
SDL_RenderCopy(rdr, t_char, NULL, &draw_r);}
