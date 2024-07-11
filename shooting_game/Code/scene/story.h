#ifndef STORY_H_INCLUDED
#define STORY_H_INCLUDED
#include "scene.h"
#include"sceneManager.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
/*
   [Story object]
*/
typedef struct _Story
{
    ALLEGRO_FONT *font;
    ALLEGRO_SAMPLE *song;
    ALLEGRO_BITMAP *background;
    ALLEGRO_SAMPLE_INSTANCE *sample_instance;
    int title_x, title_y;
    double now_time,last_exe_time;
} Story;
Scene *New_Story(int label);
void Story_update(Scene *self);
void Story_draw(Scene *self);
void Story_destroy(Scene *self);

#endif
