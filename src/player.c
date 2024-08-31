#include "demonist.h"
int collision(int zone[7][17], int collidables[4], vect pos){
for (int i =0; i <4; i++)
	if(zone[pos.y/24/ASPECT_RATIO]
	       [pos.x/12/ASPECT_RATIO] == collidables[i]) return 1;
return 0;}

// TODO keep a list of obstacles in front of the char
//      to then draw them on top of it
void player_movement(Keys* keys, vect* plpos, int zone[7][17],
		int collidables[4], int* redraw){
int step = 1.75*ASPECT_RATIO;
if (keys->up){ //if there is a collidable at the head of the char
	int collide = collision(zone, collidables,
			(vect){plpos->x,
			plpos->y -step});
		+ collision(zone, collidables,
			(vect){plpos->x +12*ASPECT_RATIO-1,
			plpos->y -step});
	//move if there is no such obstacle
	if (!collide){ plpos->y -=step; *redraw = 1; }
	if (collide){ //else figure out the collision with the upward obstacle
		collide = collision(zone, collidables,
				(vect){plpos->x,
				plpos->y +16*ASPECT_RATIO -step})
			+ collision(zone, collidables,
				(vect){plpos->x +12*ASPECT_RATIO-1,
				plpos->y +16*ASPECT_RATIO -step});
		if (!collide){ plpos->y -= step;  *redraw = 1;}
		else { int diff =(plpos->y +16*ASPECT_RATIO)%(24*ASPECT_RATIO);
			if (diff < step){ plpos->y -=diff; *redraw = 1;}}}}
	// we must do this in order to be able to walk behind walls

if (keys->left){ plpos->x-=1.75*ASPECT_RATIO; *redraw=1; }

if (keys->down){//if there is a collidable at the feet of the char
	int collide = collision(zone, collidables,
			(vect){plpos->x,
			plpos->y +24*ASPECT_RATIO +step});
		+ collision(zone, collidables,
			(vect){plpos->x +12*ASPECT_RATIO-1,
			plpos->y +24*ASPECT_RATIO +step});
	//move if there is no such obstacle
	if (!collide){ plpos->y +=step; *redraw = 1; }
	if (collide){ //else figure out the collision with the down obstacle
		collide = collision(zone, collidables,
				(vect){plpos->x,
				plpos->y +8*ASPECT_RATIO +step})
			+ collision(zone, collidables,
				(vect){plpos->x +12*ASPECT_RATIO-1,
				plpos->y +8*ASPECT_RATIO +step});
		if (!collide){ plpos->y += step;  *redraw = 1;}
		else { int diff = (plpos->y +8*ASPECT_RATIO)%(24*ASPECT_RATIO);
			if (diff < step){ plpos->y +=diff; *redraw = 1;}}}}
	// we must do this in order to be able to walk behind walls
	/*
	vect tmp1; tmp1.x = plpos->x/12/ASPECT_RATIO;
		   tmp1.y = (plpos->y + 24*ASPECT_RATIO - 16*ASPECT_RATIO
			+ (int)(1.75*ASPECT_RATIO))/24/ASPECT_RATIO;
	vect tmp2; tmp2.x = (plpos->x + 11*ASPECT_RATIO)/12/ASPECT_RATIO;
		   tmp2.y = tmp1.y;
	int collision = 0; for (int i =0; i <4; i++)
		if (zone[tmp1.y][tmp1.x] == collidables[i]
		 || zone[tmp2.y][tmp2.x] == collidables[i]){
			collision = 1; break;}
	if (!collision){ plpos->y+=1.75*ASPECT_RATIO; *redraw = 1;}
	//else { int diff = 24 - (plpos->y + 24*ASPECT_RATIO
	//		- 16*ASPECT_RATIO)%24;
	//	if (diff){ plpos->y += diff; *redraw = 1;}}}
	*/
if (keys->right){ plpos->x+=1.75*ASPECT_RATIO; *redraw=1; }}
