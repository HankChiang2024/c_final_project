#ifndef FIRE_e4_H_INCLUDED
#define FIRE_e4_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
#include<math.h>
/*
   [Fire_e4 object]
*/
typedef struct _Fire_e4
{
    int x, y;          // the position of image
    int width, height; // the width and height of image
    int vx,vy;
    int dir;
    double angle,dist;             // the velocity of Fire_e4
    int trace; //追蹤
    ALLEGRO_BITMAP *img;
    Shape *hitbox; // the hitbox of object
} Fire_e4;
Elements *New_Fire_e4(int label, int x, int y, int vx, int vy, double angle, int dir);
void Fire_e4_update(Elements *self);
void Fire_e4_interact(Elements *self, Elements *tar);
void Fire_e4_draw(Elements *self);
void Fire_e4_destory(Elements *self);
void _Fire_e4_update_position(Elements *self, int dx, int dy);
#endif
