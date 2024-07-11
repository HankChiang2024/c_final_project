#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "scene.h"
#include"sceneManager.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
/*
   [Menu object]
*/
typedef struct _Menu
{
    ALLEGRO_FONT *font;
    ALLEGRO_BITMAP *background; 
    ALLEGRO_SAMPLE *song;
    ALLEGRO_SAMPLE_INSTANCE *sample_instance;
    int title_x, title_y,select;
    double last_exe_time,now_time;
} Menu;
typedef enum Select
{
    Start_S = 0,
    Guide_S,
    Story_S,
    Setting_S,
    Quit_S
} Select;
Scene *New_Menu(int label);
void menu_update(Scene *self);
void menu_draw(Scene *self);
void menu_destroy(Scene *self);

#endif
