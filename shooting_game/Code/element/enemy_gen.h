#ifndef ENEMY_GEN_H_INCLUDED
#define ENEMY_GEN_H_INCLUDED
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include "element.h"
#include "../shapes/Shape.h"
#include "../algif5/src/algif.h"
#include <stdbool.h>
/*
   [Enemy_gen object]
*/
typedef struct _Enemy_gen
{
    int x, y,enemy_num,enemy_num2,enemy_num3,enemy_num4,enemy_num5,enemy_start_num[6];          // the position of image
    int width, height; // the width and height of image
    bool new_bul,gen,cycle_gen[11];//判斷已生成
    ALLEGRO_BITMAP *img;
    double  cd,now_time,start_time,exe_time,leave_time[11],
            last_exe_time,attack_time,
            last_exe_time2,attack_time2,
            last_exe_time3,attack_time3,
            last_exe_time4,attack_time4,
            last_exe_time5,attack_time5;
} Enemy_gen;
Elements *New_Enemy_gen(int label);
void Enemy_gen_update(Elements *self);
void Enemy_gen_interact(Elements *self, Elements *tar);
void Enemy_gen_draw(Elements *self);
void Enemy_gen_destory(Elements *self);
#endif