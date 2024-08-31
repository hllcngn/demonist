#include "demonist.h"

void player_movement(Keys* keys, vect* plpos){
if (keys->up) plpos->y-=1.75*ASPECT_RATIO;
if (keys->left) plpos->x-=1.75*ASPECT_RATIO;
if (keys->down) plpos->y+=1.75*ASPECT_RATIO;
if (keys->right) plpos->x+=1.75*ASPECT_RATIO;}
