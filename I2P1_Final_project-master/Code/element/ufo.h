#ifndef UFO_H_INCLUDED
#define UFO_H_INCLUDED
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include "element.h"
#include "../shapes/Shape.h"
#include "../algif5/src/algif.h"
#include <stdbool.h>
#include "../scene/gamescene.h" 
#include<math.h>
/*
   [Ufo object]
*/
typedef struct _Ufo
{
    int x, y;
    double hp,hp_max;          // the position of image
    int width, height; // the width and height of image
    ALLEGRO_BITMAP *img;
    Shape *hitbox; // the hitbox of object
    bool new_bul,super_mode;
    double cd,now_time,last_exe_time;
} Ufo;
Elements *New_Ufo(int label);
void Ufo_update(Elements *self);
void Ufo_interact(Elements *self, Elements *tar);
void Ufo_draw(Elements *self);
void Ufo_destory(Elements *self);

#endif
