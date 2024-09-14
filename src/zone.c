#include "demonist.h"

ZONE* get_zone1(void){
ZONE* zone = malloc(sizeof(ZONE));
FILE* f = fopen("src/zone1.txt", "r");
fscanf(f, "%d,%d,\n", &(zone->w), &(zone->h));
//printf("w=%d,h=%d", zone->w, zone->h);
zone->m = malloc(zone->h*sizeof(int*));
for (int y =0; y <zone->h; y++){
zone->m[y] = malloc(zone->w*sizeof(int));
	for (int x =0; x <zone->w; x++){
		fscanf(f, "%d,", &(zone->m[y][x]));
	//printf("%d read", zone->m[y][x]);
} fgetc(f); }
fclose(f);
return zone;}

void free_zone1(ZONE* zone){
for (int y =0; y <zone->h; y++)
	free(zone->m[y]);
free(zone);}


int** get_coll1(void){
FILE* f = fopen("src/zone1coll.txt", "r");
int w,h;
fscanf(f, "%d,%d,\n", &w, &h);
//printf("w=%d,h=%d", w,h);
int** coll1 = malloc(h*sizeof(int*));
for (int y =0; y <h; y++){
	coll1[y] = malloc(w*sizeof(int));
	for (int x =0; x <w; x++){
		fscanf(f, "%d,", &(coll1[y][x]));
} fgetc(f); }
fclose(f);
return coll1;}

void free_coll1(int** coll,int h){
for (int y =0; y <h; y++)
	free(coll[y]);
free(coll);}
