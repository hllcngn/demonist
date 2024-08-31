#include "demonist.h"

void keydown(int sym, Keys* keys){
switch(sym){
case K_UP:     keys->up    =1;	break;
case K_LEFT:   keys->left  =1;	break;
case K_DOWN:   keys->down  =1;	break;
case K_RIGHT:  keys->right =1;	break;}}

void keyup(int sym, Keys* keys){
switch(sym){
case K_UP:     keys->up    =0;	break;
case K_LEFT:   keys->left  =0;	break;
case K_DOWN:   keys->down  =0;	break;
case K_RIGHT:  keys->right =0;	break;}}
