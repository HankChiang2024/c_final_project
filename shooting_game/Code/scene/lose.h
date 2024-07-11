#ifndef LOSE_H_INCLUDED
#define LOSE_H_INCLUDED
#include "scene.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
/*
   [lose object]
*/
typedef struct _lose
{
    ALLEGRO_FONT *font;
    ALLEGRO_SAMPLE *song;
    ALLEGRO_BITMAP *background;
    ALLEGRO_SAMPLE_INSTANCE *sample_instance;
    int title_x, title_y;
} lose;
Scene *New_lose(int label);
void lose_update(Scene *self);
void lose_draw(Scene *self);
void lose_destroy(Scene *self);

#endif
