#ifndef BLOOD_H_INCLUDED
#define BLOOD_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
/*
   [Blood object]
*/
typedef struct _Blood
{
    ALLEGRO_COLOR color,color_b;
    ALLEGRO_BITMAP *img;
    int x, y;          // the position of image
    int width, height; // the width and height of image
 // the hitbox of object
    double percentage;
} Blood;
Elements *New_Blood(int label);
void Blood_update(Elements *self);
void Blood_interact(Elements *self, Elements *tar);
void Blood_draw(Elements *self);
void Blood_destory(Elements *self);

#endif
