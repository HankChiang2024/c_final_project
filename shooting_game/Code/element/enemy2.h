#ifndef ENEMY2_H_INCLUDED
#define ENEMY2_H_INCLUDED
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include "element.h"
#include "../shapes/Shape.h"
#include "../algif5/src/algif.h"
#include <stdbool.h>
#include "../scene/gamescene.h"
/*
   [Enemy2 object]
*/
typedef struct _Enemy2
{
    int x, y, v, life;          // the position of image
    int width, height; // the width and height of image
    ALLEGRO_BITMAP *img;
    Shape *hitbox; // the hitbox of object
    bool new_bul,fire_mod;
    double cd,now_time,last_exe_time,atk_time,start_time,leave_time;
} Enemy2;
Elements *New_Enemy2(int label,int x,int y,int v,double leave_time,int difficulty);
void Enemy2_update(Elements *self);
void Enemy2_interact(Elements *self, Elements *tar);
void Enemy2_draw(Elements *self);
void Enemy2_destory(Elements *self);
void _Enemy2_update_position(Elements *self, int dx, int dy);
#endif
