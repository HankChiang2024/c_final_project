#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED
#include "scene.h"
#include "../element/element.h"
#include "../element/charater.h"
#include "../element/floor.h"
#include "../element/teleport.h"
#include "../element/tree.h"
#include "../element/projectile.h"
#include "../element/ufo.h" /////////////////////////modified
#include "../element/bullet.h"
#include "../element/enemy.h"
#include "../element/enemy_gen.h"
#include "../element/blood.h"
#include "../element/score.h"
#include"../element/enemy2.h"
#include"../element/enemy3.h"
#include"../element/enemy4.h"
#include"../element/enemy5.h"
#include"../element/fire.h"
#include"../element/fire_e3.h"
#include"../element/fire_e4.h"
#include"../element/fire_e5.h"
#include"../element/split_bullet.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
/*
   [game scene object]
*/
typedef enum EleType
{
    Floor_L,
    Teleport_L,
    Tree_L,
    Character_L,
    Projectile_L,
    Ufo_L, /////////////////////
    Bullet_L,
    Enemy_L,
    Enemy_gen_L,
    Blood_L,
    Score_L,
    Enemy2_L,
    Enemy3_L,
    Enemy4_L,
    Enemy5_L,
    Fire_L,
    Fire_e3_L,
    Fire_e4_L,
    Fire_e5_L,
    Split_bullet_L

    
} EleType;
typedef struct _GameScene
{
    ALLEGRO_FONT *font;
    ALLEGRO_BITMAP *background;
    ALLEGRO_SAMPLE *song;
    ALLEGRO_SAMPLE_INSTANCE *sample_instance;

} GameScene;
Scene *New_GameScene(int label);
void game_scene_update(Scene *self);
void game_scene_draw(Scene *self);
void game_scene_destroy(Scene *self);

#endif
