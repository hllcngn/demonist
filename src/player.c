#include "demonist.h"

void player_movement(Keys* keys, vect* plpos, int* redraw){
if (keys->up){ plpos->y-=1.75*ASPECT_RATIO; *redraw=1; }
if (keys->left){ plpos->x-=1.75*ASPECT_RATIO; *redraw=1; }
if (keys->down){ plpos->y+=1.75*ASPECT_RATIO; *redraw=1; }
if (keys->right){ plpos->x+=1.75*ASPECT_RATIO; *redraw=1; }}
