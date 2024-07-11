#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include "element.h"
#include "../shapes/Shape.h"
#include "../algif5/src/algif.h"
#include <stdbool.h>
#include "../scene/gamescene.h"
/*
   [Enemy object]
*/
typedef struct _Enemy
{
    int x, y, v, life;          // the position of image
    int width, height; // the width and height of image
    ALLEGRO_BITMAP *img;
    Shape *hitbox; // the hitbox of object
    bool new_bul;
    double cd,now_time,last_exe_time;
} Enemy;
Elements *New_Enemy(int label,int x,int y,int v,int difficulty);
void Enemy_update(Elements *self);
void Enemy_interact(Elements *self, Elements *tar);
void Enemy_draw(Elements *self);
void Enemy_destory(Elements *self);
void _Enemy_update_position(Elements *self, int dx, int dy);
#endif
