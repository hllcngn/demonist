#include "demonist.h"

void load_sprites(SDL_Renderer* rdr, SDL_Texture** t_char, SDL_Texture*** t){
SDL_Surface *s = SDL_LoadBMP("sprites/Sprite-char.bmp");
*t_char = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
*t = malloc(sizeof(SDL_Texture*)*6); SDL_Texture** tt = *t;
s = SDL_LoadBMP("sprites/Sprite-0001.bmp");
tt[0] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0002.bmp");
tt[1] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0003.bmp");
tt[2] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0004.bmp");
tt[3] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0005.bmp");
tt[4] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0006.bmp");
tt[5] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);}
