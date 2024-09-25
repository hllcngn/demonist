#include "demonist.h"

#define ANIM 120000000

void player_movement3(Keys* keys, vect* plpos,
		int** coll, int* anim, vectf* movement){
if (!anim){
	if (keys->up) if (!coll[plpos->y-1][plpos->x]){ plpos->y--;
				*anim = ANIM; movement->y = -1; }
	if (keys->down) if (!coll[plpos->y][plpos->x]){ plpos->y++;
				*anim = ANIM; movement->y = 1; }
	if (keys->left) if (!coll[plpos->y][plpos->x-1]){ plpos->x--;
				*anim = ANIM; movement->x = -1; }
	if (keys->right) if (!coll[plpos->y][plpos->x+1]){ plpos->x++;
				*anim = ANIM; movement->x = 1; }}
}

void player_movement_increment(time_t clk_movediff, int anim,
			vectf* movement){
	if (movement->x < 0)
		movement->x -= clk_movediff/anim;
	else if (movement->x < 0)
		movement->x += clk_movediff/anim;
	if (movement->y < 0)
		movement->y -= clk_movediff/anim;
	else if (movement->y > 0)
		movement->y += clk_movediff/anim;
}


