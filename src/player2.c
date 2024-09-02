#include "demonist.h"

void player_movement2(Keys* keys, vect* plpos,
		int coll[14][17], int* redraw){
if (keys->up) if (!coll[plpos->y-1][plpos->x]){ plpos->y--; *redraw = 1; }
if (keys->down) if (!coll[plpos->y][plpos->x]){ plpos->y++; *redraw = 1; }
if (keys->left) if (!coll[plpos->y][plpos->x-1]){ plpos->x--; *redraw = 1; }
if (keys->right) if (!coll[plpos->y][plpos->x+1]){ plpos->x++; *redraw = 1; }}
