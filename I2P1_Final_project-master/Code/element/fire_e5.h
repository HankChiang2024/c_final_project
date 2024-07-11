#ifndef Fire_e5_H_INCLUDED
#define Fire_e5_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
#include<math.h>
/*
   [Fire_e5 object]
*/
typedef struct _Fire_e5
{
    int x, y;          // the position of image
    int width, height; // the width and height of image
    double vx,vy;
    int dir;
    double angle,now_time,start_time,t,ai,ri;             // the velocity of Fire_e5
    ALLEGRO_BITMAP *img;
    Shape *hitbox; // the hitbox of object
} Fire_e5;
Elements *New_Fire_e5(int label, int x, int y, double vx, double vy, double angle, int dir);
void Fire_e5_update(Elements *self);
void Fire_e5_interact(Elements *self, Elements *tar);
void Fire_e5_draw(Elements *self);
void Fire_e5_destory(Elements *self);
void _Fire_e5_update_position(Elements *self, int dx, int dy);
#endif
