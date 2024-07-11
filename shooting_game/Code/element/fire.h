#ifndef FIRE_H_INCLUDED
#define FIRE_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
#include<math.h>
/*
   [Fire object]
*/
typedef struct _Fire
{
    int x, y;          // the position of image
    int width, height; // the width and height of image
    int vx,vy;
    int dir;
    double angle;             // the velocity of Fire
    ALLEGRO_BITMAP *img;
    Shape *hitbox; // the hitbox of object
} Fire;
Elements *New_Fire(int label, int x, int y, int vx, int vy, double angle, int dir);
void Fire_update(Elements *self);
void Fire_interact(Elements *self, Elements *tar);
void Fire_draw(Elements *self);
void Fire_destory(Elements *self);
void _Fire_update_position(Elements *self, int dx, int dy);
#endif
