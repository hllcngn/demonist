#include "demonist.h"
#include "stdio.h"
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
int zone1[7][17] =  {{8,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,9},
		{11,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,10},
		{11,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,10},
		{2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2},
		{11,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,10},
		{11,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,10},
		{8,13,13,13,13,13,13,13,1,2,13,13,13,13,13,13,9}};
int zone_w = 17, zone_h = 7;
int collidables[11] = {3,4,5,6,7,8,9,10,11,12,13};
int ncoll = 11;
vect plpos = (vect){12*ASPECT_RATIO*8,24*ASPECT_RATIO*4};
int coll[14][17] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1}};
vect plpos2 = (vect){8, 9};
clock_t clk_move, clk_move_start; int umove = 1;

//loading assets
SDL_Texture *t_char, **t; load_sprites(rdr, &t_char, &t);

//MAIN LOOP
clock_t clk, clk_start = clock();
clk_move_start = clk_start;
//printf("first clock = %i", clock());
SDL_Event* ev = malloc(sizeof(SDL_Event));
//int redraw = 0; draw(rdr, win_w, win_h, plpos, t_char, zone1, t);
int redraw = 0; draw2(rdr, win_w, win_h, plpos2, t_char, zone1, t);
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
//player_movement(&keys, &plpos, zone1, collidables, ncoll, &redraw);
//clk_move = clock()-clk_move_start;
//printf("clock = %lu,", clock());
//printf("clk_move = %lu,", clk_move);
//printf("clk_move_start = %lu", clk_move_start);
//if (clk_move > 0){
	player_movement2(&keys, &plpos2, zone1, coll, &redraw);
	usleep(200000);
	//clk_move_start = clock();}
//if (redraw) draw(rdr, win_w, win_h, plpos, t_char, zone1, t);
if (redraw) draw2(rdr, win_w, win_h, plpos2, t_char, zone1, t);

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
