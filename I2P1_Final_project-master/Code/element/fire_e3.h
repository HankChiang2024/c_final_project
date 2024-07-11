#ifndef Fire_e3_H_INCLUDED
#define Fire_e3_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
#include<math.h>
/*
   [Fire_e3 object]
*/
typedef struct _Fire_e3
{
    int x, y;          // the position of image
    int width, height; // the width and height of image
    int vx,vy;
    int dir;
    double angle,now_time,start_time,t,ai,ri;             // the velocity of Fire_e3
    ALLEGRO_BITMAP *img;
    Shape *hitbox; // the hitbox of object
} Fire_e3;
Elements *New_Fire_e3(int label, int x, int y, int vx, int vy, double angle, int dir);
void Fire_e3_update(Elements *self);
void Fire_e3_interact(Elements *self, Elements *tar);
void Fire_e3_draw(Elements *self);
void Fire_e3_destory(Elements *self);
void _Fire_e3_update_position(Elements *self, int dx, int dy);
#endif
