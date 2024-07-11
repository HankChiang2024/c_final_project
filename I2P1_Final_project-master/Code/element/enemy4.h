#ifndef ENEMY4_H_INCLUDED
#define ENEMY4_H_INCLUDED
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include "element.h"
#include "../shapes/Shape.h"
#include "../algif5/src/algif.h"
#include <stdbool.h>
#include "../scene/gamescene.h"
/*
   [Enemy4 object]
*/
typedef struct _Enemy4
{
    int x, y, v, life;          // the position of image
    int width, height; // the width and height of image
    ALLEGRO_BITMAP *img;
    Shape *hitbox; // the hitbox of object
    bool new_bul,fire_mod;
    double cd,now_time,last_exe_time,atk_time,start_time,leave_time;
} Enemy4;
Elements *New_Enemy4(int label,int x,int y,int v,double leave_time,int difficulty);
void Enemy4_update(Elements *self);
void Enemy4_interact(Elements *self, Elements *tar);
void Enemy4_draw(Elements *self);
void Enemy4_destory(Elements *self);
void _Enemy4_update_position(Elements *self, int dx, int dy);
#endif
