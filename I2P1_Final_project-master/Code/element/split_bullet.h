#ifndef Split_bullet_H_INCLUDED
#define Split_bullet_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
#include<math.h>
/*
   [Split_bullet object]
*/
typedef struct _Split_bullet
{
    int x, y ,shift_y;          // the position of image
    int width, height; // the width and height of image
    int vx,vy;
    int dir;
    double angle;             // the velocity of Split_bullet
    ALLEGRO_BITMAP *img;
    Shape *hitbox; // the hitbox of object
} Split_bullet;
Elements *New_Split_bullet(int label, int x, int y, int vx, int vy,double angle,int dir);
void Split_bullet_update(Elements *self);
void Split_bullet_interact(Elements *self, Elements *tar);
void Split_bullet_draw(Elements *self);
void Split_bullet_destory(Elements *self);
void _Split_bullet_update_position(Elements *self, int dx, int dy);
#endif
