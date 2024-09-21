#include "demonist.h"
#define ANIM 120

int player_movement3(Keys* keys, vect* plpos,
		int** coll, int* anim, vect* movement){
if (keys->up) if (!coll[plpos->y-1][plpos->x]){ plpos->y--;
					*anim = ANIM; movement->y = -120;}
if (keys->down) if (!coll[plpos->y][plpos->x]){ plpos->y++;
					*anim = ANIM; movement->y = 120;}
if (keys->left) if (!coll[plpos->y][plpos->x-1]){ plpos->x--;
					*anim = ANIM; movement->x = -120;}
if (keys->right) if (!coll[plpos->y][plpos->x+1]){ plpos->x++;
					*anim = ANIM; movement->x = 120;}}
