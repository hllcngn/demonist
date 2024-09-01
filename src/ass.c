#include "demonist.h"
void load_sprites(SDL_Renderer* rdr, SDL_Texture** t_char, SDL_Texture*** t){
SDL_Surface *s = SDL_LoadBMP("sprites/Sprite-char.bmp");
*t_char = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
*t = malloc(sizeof(SDL_Texture*)*13); SDL_Texture** tt = *t;
for (int i =0; i <13; i++){
	char* path = malloc(24);
	strncpy(path, "sprites/Sprite-0000.bmp", 24);
	for (int n =i+1, j=3; n && j>=0; n/=10, j--) path[15+j] = '0'+n%10;
	s = SDL_LoadBMP(path);
	tt[i] = SDL_CreateTextureFromSurface(rdr, s);
	SDL_FreeSurface(s);}}
