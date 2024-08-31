#include "SDL2/SDL.h"

#ifdef main	//avoid WinMain error
#undef main	//on windows
#endif

int main(int ac, char** av){
SDL_Init(SDL_INIT_VIDEO);
int window_width = 1100, window_height = 700;
SDL_Window* win = SDL_CreateWindow("manor,",
		100, 100, window_width, window_height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
SDL_Renderer* rdr = SDL_CreateRenderer(win, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

SDL_Event ev;
int quit = 0;
while(!quit){

while(SDL_PollEvent(&ev)){ switch(ev.type){
case SDL_QUIT:	quit++;		break;
case SDL_KEYDOWN:
	switch(ev.key.keysym.sym){
	case SDLK_ESCAPE:	quit++;		break;
	}			break;
}}
}

SDL_DestroyRenderer(rdr);
SDL_DestroyWindow(win);
SDL_Quit();
return 0;}
