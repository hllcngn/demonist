#include "demonist.h"

void load_sprites(SDL_Renderer* rdr, SDL_Texture** t_char, SDL_Texture*** t){
SDL_Surface *s = SDL_LoadBMP("sprites/Sprite-char.bmp");
*t_char = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
*t = malloc(sizeof(SDL_Texture*)*13); SDL_Texture** tt = *t;
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
tt[5] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0007.bmp");
tt[6] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0008.bmp");
tt[7] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0009.bmp");
tt[8] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0010.bmp");
tt[9] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0011.bmp");
tt[10] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0012.bmp");
tt[11] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);
s = SDL_LoadBMP("sprites/Sprite-0013.bmp");
tt[12] = SDL_CreateTextureFromSurface(rdr, s); SDL_FreeSurface(s);}
