#ifndef SCORE_BACKGROUND_H_INCLUDED
#define SCORE_BACKGROUND_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
/*
   [score_background object]
*/
typedef struct _score_background
{
    ALLEGRO_COLOR color;
    ALLEGRO_FONT *font;
    int x, y;          // the position of image
    int width, height; // the width and height of image
 // the hitbox of object
} score_background;
Elements *New_score_background(int label);
void score_background_update(Elements *self);
void score_background_interact(Elements *self, Elements *tar);
void score_background_draw(Elements *self);
void score_background_destory(Elements *self);

#endif
