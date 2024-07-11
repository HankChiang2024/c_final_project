#ifndef ENEMY3_H_INCLUDED
#define ENEMY3_H_INCLUDED
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include "element.h"
#include "../shapes/Shape.h"
#include "../algif5/src/algif.h"
#include <stdbool.h>
#include "../scene/gamescene.h"
/*
   [Enemy3 object]
*/
typedef struct _Enemy3
{
    int x, y, v, fire_num, life;          // the position of image
    int width, height; // the width and height of image
    ALLEGRO_BITMAP *img;
    Shape *hitbox; // the hitbox of object
    bool new_bul,fire_mod;
    double cd,now_time,last_exe_time,atk_time,start_time,leave_time;
} Enemy3;
Elements *New_Enemy3(int label,int x,int y,int v,double leave_time,int difficulty);
void Enemy3_update(Elements *self);
void Enemy3_interact(Elements *self, Elements *tar);
void Enemy3_draw(Elements *self);
void Enemy3_destory(Elements *self);
void _Enemy3_update_position(Elements *self, int dx, int dy);
#endif
