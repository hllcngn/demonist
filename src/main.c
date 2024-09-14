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
//loading assets
SDL_Texture *t_char, **t; load_sprites(rdr, &t_char, &t);

//internal variables
Keys keys =(Keys){0,0,0,0};
int solution; if (ac <2) solution =1;
else { solution = atoi(av[1]); if (solution >3) solution =1; }
ZONE* zone1 = get_zone1();
//  first solution
int collidables[11] = {3,4,5,6,7,8,9,10,11,12,13};
int ncoll = 11;
vect plpos = (vect){12*ASPECT_RATIO*8,24*ASPECT_RATIO*4};
//  second solution
int** coll1 = get_coll1();
vect plpos2 = (vect){8, 9};
struct timespec clk_move, clk_move_start;
clock_gettime(CLOCK_REALTIME, &clk_move_start);

//MAIN LOOP
struct timespec clk, clk_start;
clock_gettime(CLOCK_REALTIME, &clk_start);
//clk_move_start = clk_start;
SDL_Event* ev = malloc(sizeof(SDL_Event));
if (solution == 1)	draw(rdr, win_w, win_h, plpos, t_char, zone1, t);
else			draw2(rdr, win_w, win_h, plpos2, t_char, zone1, t);
int redraw = 0;
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
if (solution == 1) player_movement(&keys, &plpos, zone1, collidables, ncoll, &clk_move_start, &redraw);
else if (solution == 2){
clock_gettime(CLOCK_REALTIME, &clk_move);
time_t clk_movediff = clk_move.tv_nsec - clk_move_start.tv_nsec;
if (clk_movediff < 0)
	clk_movediff = 1000000000 - clk_move_start.tv_nsec + clk_move.tv_nsec;
if (clk_movediff > MOV_2_MS*1000000){
	player_movement2(&keys, &plpos2, coll1, &redraw);
	clock_gettime(CLOCK_REALTIME, &clk_move_start);}}

  //drawing
if (redraw){
	if (solution == 1) draw(rdr, win_w, win_h, plpos, t_char, zone1, t);
	else if (solution == 2) draw2(rdr, win_w, win_h, plpos2, t_char, zone1, t);}

  //end of loop
clock_gettime(CLOCK_REALTIME, &clk);
time_t clkdiff = clk.tv_nsec - clk_start.tv_nsec;
if (clkdiff < 0) clkdiff = 1000000000 - clk_start.tv_nsec + clk.tv_nsec;
time_t framerate = 1000000/FPS;
usleep(framerate - clkdiff/1000);
clock_gettime(CLOCK_REALTIME, &clk_start);}

//freeing memory
// functional variables
free(ev);
// internal variables
free_zone1(zone1);
/*if (solution ==2)*/ free_coll1(coll1, 18);
// assets
SDL_DestroyTexture(t_char);
for (int i =0; i <ncoll; i++) SDL_DestroyTexture(t[i]); free(t);
// video
SDL_DestroyRenderer(rdr);
SDL_DestroyWindow(win);
SDL_Quit();  return 0;}
