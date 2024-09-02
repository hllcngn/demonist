#include "demonist.h"
int collision(ZONE* zone, int collidables[11], int ncoll, vect pos){
for (int i =0; i <ncoll; i++)
	if(zone->m[pos.y/24/ASPECT_RATIO]
		[pos.x/12/ASPECT_RATIO] == collidables[i]) return 1;
return 0;}

// TODO keep a list of obstacles in front of the char
//      to then draw them on top of it
void player_movement(Keys* keys, vect* plpos, ZONE* zone,
		int collidables[11], int ncoll, int* redraw){
int step = 1.75*ASPECT_RATIO;
if (keys->up){ //if there is a collidable at the head of the char
	int collide = collision(zone, collidables, ncoll,
			(vect){plpos->x,
			plpos->y -step})
		+ collision(zone, collidables, ncoll,
			(vect){plpos->x +12*ASPECT_RATIO-1,
			plpos->y -step});
	//move if there is no such obstacle
	if (!collide){ plpos->y -=step; *redraw = 1; }
	if (collide){ //else figure out the collision with the upward obstacle
		collide = collision(zone, collidables, ncoll,
				(vect){plpos->x,
				plpos->y +16*ASPECT_RATIO -step})
			+ collision(zone, collidables, ncoll,
				(vect){plpos->x +12*ASPECT_RATIO-1,
				plpos->y +16*ASPECT_RATIO -step});
		if (!collide){ plpos->y -= step;  *redraw = 1;}
		else { int diff =(plpos->y +16*ASPECT_RATIO)%(24*ASPECT_RATIO);
			if (diff < step){ plpos->y -=diff; *redraw = 1;}}}}
	// we must do this in order to be able to walk behind walls

if (keys->left){
	int collide = collision(zone, collidables, ncoll,
			(vect){plpos->x -step, plpos->y +8*ASPECT_RATIO-1});
	if (!collide){ plpos->x -=step; *redraw = 1; }
	else { int diff = plpos->x%(12*ASPECT_RATIO);
		if (diff < step){ plpos->x -=diff; *redraw = 1;}}}

if (keys->down){//if there is a collidable at the feet of the char
	int collide = collision(zone, collidables, ncoll,
			(vect){plpos->x,
			plpos->y +24*ASPECT_RATIO +step})
		+ collision(zone, collidables, ncoll,
			(vect){plpos->x +12*ASPECT_RATIO-1,
			plpos->y +24*ASPECT_RATIO +step});
	//move if there is no such obstacle
	if (!collide){ plpos->y +=step; *redraw = 1; }
	if (collide){ //else figure out the collision with the down obstacle
		collide = collision(zone, collidables, ncoll,
				(vect){plpos->x,
				plpos->y +8*ASPECT_RATIO +step})
			+ collision(zone, collidables, ncoll,
				(vect){plpos->x +12*ASPECT_RATIO-1,
				plpos->y +8*ASPECT_RATIO +step});
		if (!collide){ plpos->y += step;  *redraw = 1;}
		else { int diff = 24*ASPECT_RATIO-(plpos->y +8*ASPECT_RATIO
				-24*ASPECT_RATIO)%(24*ASPECT_RATIO);
			if (diff < step){ plpos->y +=diff; *redraw = 1;}}}}
	// we must do this in order to be able to walk behind walls
if (keys->right){
	int collide = collision(zone, collidables, ncoll,
			(vect){plpos->x +12*ASPECT_RATIO +step,
			plpos->y +16*ASPECT_RATIO-1});
	if (!collide){ plpos->x +=step; *redraw = 1; }
	else { int diff = 12*ASPECT_RATIO -plpos->x%(12*ASPECT_RATIO);
		if (diff < step){ plpos->x +=diff; *redraw = 1;}}}}
