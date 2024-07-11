#ifndef SETTING_H_INCLUDED
#define SETTING_H_INCLUDED
#include "scene.h"
#include"sceneManager.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
/*
   [Setting object]
*/
typedef struct _Setting
{
    ALLEGRO_COLOR color,color_b;
    ALLEGRO_FONT *font;
    ALLEGRO_BITMAP *background;
    ALLEGRO_SAMPLE *song;
    ALLEGRO_SAMPLE_INSTANCE *sample_instance;
    int title_x, title_y,select,
        sound_bar_x,sound_bar_y,sound_bar_width,sound_bar_height,
        super_mode_x,super_mode_y,super_mode_width,super_mode_height;
    double now_time,last_exe_time;
} Setting;
typedef enum Select_setting
{
    Sound_S = 0,
    Super_mode_S
} Select_setting;
Scene *New_Setting(int label);
void Setting_update(Scene *self);
void Setting_draw(Scene *self);
void Setting_destroy(Scene *self);

#endif
