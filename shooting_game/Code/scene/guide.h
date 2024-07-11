#ifndef GUIDE_H_INCLUDED
#define GUIDE_H_INCLUDED
#include "scene.h"
#include"sceneManager.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
/*
   [Guide object]
*/
typedef struct _Guide
{
    ALLEGRO_FONT *font;
    ALLEGRO_BITMAP *background;
    ALLEGRO_SAMPLE *song;
    ALLEGRO_SAMPLE_INSTANCE *sample_instance;
    int title_x, title_y;
    double now_time,last_exe_time;
} Guide;
Scene *New_Guide(int label);
void Guide_update(Scene *self);
void Guide_draw(Scene *self);
void Guide_destroy(Scene *self);

#endif
