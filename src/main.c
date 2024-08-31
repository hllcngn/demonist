#include "demonist.h"
#ifdef main	//avoid WinMain error
#undef main	//on windows
#endif
int main(int ac, char** av){
//video initialization
SDL_Init(SDL_INIT_VIDEO);
int win_w, win_h;
{SDL_DisplayMode dm; SDL_GetCurrentDisplayMode(0, &dm);
win_w = dm.w; win_h = dm.h;}
SDL_Window* win = SDL_CreateWindow("manor,",
		0, 0, win_w, win_h,
		SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
SDL_Renderer* rdr = SDL_CreateRenderer(win, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

//internal variables
Keys keys =(Keys){0,0,0,0};
int zone1[7][17] =  {{5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,6},
		{4,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,4},
		{4,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,4},
		{2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2},
		{4,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,4},
		{4,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,4},
		{5,3,3,3,3,3,3,3,1,2,3,3,3,3,3,3,6}};
int zone_w = 17, zone_h = 7;
vect plpos = (vect){12*ASPECT_RATIO*8,24*ASPECT_RATIO*4};

//loading assets
SDL_Texture *t_char, **t; load_sprites(rdr, &t_char, &t);

//MAIN LOOP
clock_t clk, clk_start = clock();
SDL_Event* ev = malloc(sizeof(SDL_Event));
int redraw = 0; draw(rdr, win_w, win_h, plpos, t_char, zone1, t);
int quit = 0;  while(!quit){
  //event handling
while(SDL_PollEvent(ev)){ switch(ev->type){
case SDL_QUIT:  quit++;  break;
case SDL_KEYDOWN:  switch(ev->key.keysym.sym){
	case K_QUIT:  quit++;  break;
	default:
		keydown(ev->key.keysym.sym, &keys); break;} break;
case SDL_KEYUP:  switch(ev->key.keysym.sym){
	default:
		keyup(ev->key.keysym.sym, &keys); break;} break;}}
  //updating states
player_movement(&keys, &plpos, &redraw);
if (redraw) draw(rdr, win_w, win_h, plpos, t_char, zone1, t);
  //clock tic
clk = clock()-clk_start;
usleep((CLOCKS_PER_SEC/FPS-clk)*(1000000/CLOCKS_PER_SEC));
clk_start = clock();}

//freeing memory
free(ev);
SDL_DestroyTexture(t_char);
for (int i =0; i <4; i++) SDL_DestroyTexture(t[i]); free(t);
SDL_DestroyRenderer(rdr);
SDL_DestroyWindow(win);
SDL_Quit();  return 0;}
