#ifndef Bullet_H_INCLUDED
#define Bullet_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
#include<math.h>
/*
   [Bullet object]
*/
typedef struct _Bullet
{
    int x, y;          // the position of image
    int width, height; // the width and height of image
    int vx,vy;
    int dir;
    double angle;             // the velocity of Bullet
    ALLEGRO_BITMAP *img;
    Shape *hitbox; // the hitbox of object
} Bullet;
Elements *New_Bullet(int label, int x, int y, int vx, int vy,double angle,int dir);
void Bullet_update(Elements *self);
void Bullet_interact(Elements *self, Elements *tar);
void Bullet_draw(Elements *self);
void Bullet_destory(Elements *self);
void _Bullet_update_position(Elements *self, int dx, int dy);
#endif
