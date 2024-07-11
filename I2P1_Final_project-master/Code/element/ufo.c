#include "ufo.h"
#include "../scene/sceneManager.h"
#include "bullet.h"
#include"split_bullet.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Circle.h"
#include "../algif5/src/algif.h"
#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro_primitives.h>
#include"../global.h"
#define PI acos(-1)

/*
   [Ufo function]
*/
Elements *New_Ufo(int label)
{
    Ufo *pDerivedObj = (Ufo *)malloc(sizeof(Ufo));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/ufo.png"); /////////////////////////////////////////////////// modified
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pDerivedObj->x = 85;
    pDerivedObj->y = HEIGHT - pDerivedObj->height;
    pDerivedObj->hp=100;
    pDerivedObj->hp_max=100;
    pDerivedObj->new_bul = false;
    pDerivedObj->super_mode = super_mode;
    pDerivedObj->cd=0.1;
    pDerivedObj->last_exe_time=0;
    pObj->inter_obj[pObj->inter_len++] = Enemy_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy2_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy3_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy4_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy5_L;
    pObj->inter_obj[pObj->inter_len++] = Fire_L;
    pObj->inter_obj[pObj->inter_len++] = Fire_e3_L;
    pObj->inter_obj[pObj->inter_len++] = Fire_e4_L;
    pObj->inter_obj[pObj->inter_len++] = Fire_e5_L;
    // pDerivedObj->hitbox = New_Circle(pDerivedObj->x + pDerivedObj->width / 2,
    //                                  pDerivedObj->y + pDerivedObj->height / 2,
    //                                  min(pDerivedObj->width, pDerivedObj->height) / 2);
    pDerivedObj->hitbox = New_Rectangle(pDerivedObj->x + pDerivedObj->width / 3,
                                        pDerivedObj->y + pDerivedObj->height / 3,
                                        pDerivedObj->x + 2 * pDerivedObj->width / 3,
                                        pDerivedObj->y + 2 * pDerivedObj->height / 3);
    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Ufo_update;
    pObj->Interact = Ufo_interact;
    pObj->Draw = Ufo_draw;
    pObj->Destroy = Ufo_destory;
    return pObj;
}
void Ufo_update(Elements *self) 
{
    Ufo *Obj = ((Ufo *)(self->pDerivedObj));
    Shape *hitbox = Obj->hitbox;
    hitbox->update_center_x(hitbox, mouse.x-Obj->width/2 - Obj->x);
    hitbox->update_center_y(hitbox, mouse.y-Obj->height/2 - Obj->y);
    Obj->x = mouse.x-Obj->width/2;
    Obj->y = mouse.y-Obj->height/2;
    Obj->new_bul = false;
    Obj->now_time=al_get_time();
    if(Obj->now_time-Obj->last_exe_time>Obj->cd){
        if(Obj->new_bul == false){
            if((key_state[ALLEGRO_KEY_LEFT]))
            {
                Elements *pro;
                pro = New_Bullet(Bullet_L, mouse.x, mouse.y, 10, -100, PI, 1);
                _Register_elements(scene, pro);
                Obj->new_bul = true;
                Obj->last_exe_time=Obj->now_time;
            }
            if((key_state[ALLEGRO_KEY_UP]))
            {
                Elements *pro;
                pro = New_Bullet(Bullet_L, mouse.x, mouse.y, 0, -20,0,2);
                _Register_elements(scene, pro);
                Obj->new_bul = true;
                Obj->last_exe_time=Obj->now_time;
            }
            if((key_state[ALLEGRO_KEY_RIGHT]))
            {
                Elements *pro;
                pro = New_Bullet(Bullet_L, mouse.x, mouse.y, 10, -100, 0, 3);
                _Register_elements(scene, pro);
                Obj->new_bul = true;
                Obj->last_exe_time=Obj->now_time;
            }
            if(key_state[ALLEGRO_KEY_DOWN]){
                Elements *pro;
                pro = New_Split_bullet(Split_bullet_L, mouse.x, mouse.y, 0, -10, 0, 2);
                _Register_elements(scene, pro);
                Obj->new_bul = true;
                Obj->last_exe_time=Obj->now_time;
            }
        }
    }

    if(key_state[ALLEGRO_KEY_S]){
        Obj->super_mode=true;
    }
    if(key_state[ALLEGRO_KEY_W]){
        Obj->super_mode=false;
    }
    if(key_state[ALLEGRO_KEY_P])
        Obj->hp=0;
    // if((key_state[ALLEGRO_KEY_H]))Obj->hp-=10;測試血條變動
    HP=Obj->hp;


}
void Ufo_interact(Elements *self, Elements *tar) {
    Ufo *Obj = ((Ufo *)(self->pDerivedObj));
    if (tar->label == Enemy_L)
    {
        Enemy *enemy = ((Enemy *)(tar->pDerivedObj));
        if (enemy->hitbox->overlap(enemy->hitbox, Obj->hitbox)){
        tar->dele = true;
        // self->dele = true;
        if(!Obj->super_mode)
            Obj->hp -= 20;
        }
    }
    if (tar->label == Enemy2_L)
    {
        Enemy2 *enemy2 = ((Enemy2 *)(tar->pDerivedObj));
        if (enemy2->hitbox->overlap(enemy2->hitbox, Obj->hitbox)){
        tar->dele = true;
        // self->dele = true;
        if(!Obj->super_mode)
            Obj->hp -= 10;
        }
    }
    if (tar->label == Enemy3_L)
    {
        Enemy3 *enemy = ((Enemy3 *)(tar->pDerivedObj));
        if (enemy->hitbox->overlap(enemy->hitbox, Obj->hitbox)){
        tar->dele = true;
        // self->dele = true;
        if(!Obj->super_mode)
            Obj->hp -= 10;
        }
    }
    if (tar->label == Enemy4_L)
    {
        Enemy4 *enemy = ((Enemy4 *)(tar->pDerivedObj));
        if (enemy->hitbox->overlap(enemy->hitbox, Obj->hitbox)){
        tar->dele = true;
        // self->dele = true;
        if(!Obj->super_mode)
            Obj->hp -= 10;
        }
    }
    if (tar->label == Enemy5_L)
    {
        Enemy5 *enemy = ((Enemy5 *)(tar->pDerivedObj));
        if (enemy->hitbox->overlap(enemy->hitbox, Obj->hitbox)){
        tar->dele = true;
        // self->dele = true;
        if(!Obj->super_mode)
            Obj->hp -= 10;
        }
    }
    if (tar->label == Fire_L)
    {
        Fire *fire = ((Fire *)(tar->pDerivedObj));
        if (fire->hitbox->overlap(fire->hitbox, Obj->hitbox)){
        tar->dele = true;
        // self->dele = true;
        if(!Obj->super_mode)
            Obj->hp -= 10;
        }
    }
    if (tar->label == Fire_e3_L)
    {
        Fire_e3 *fire = ((Fire_e3 *)(tar->pDerivedObj));
        if (fire->hitbox->overlap(fire->hitbox, Obj->hitbox)){
        tar->dele = true;
        // self->dele = true;
        if(!Obj->super_mode)
            Obj->hp -= 5;
        }
    }
    if (tar->label == Fire_e4_L)
    {
        Fire_e4 *fire = ((Fire_e4 *)(tar->pDerivedObj));
        if (fire->hitbox->overlap(fire->hitbox, Obj->hitbox)){
        tar->dele = true;
        // self->dele = true;
        if(!Obj->super_mode)
            Obj->hp -= 10;
        }
    }
    if (tar->label == Fire_e5_L)
    {
        Fire_e5 *fire = ((Fire_e5 *)(tar->pDerivedObj));
        if (fire->hitbox->overlap(fire->hitbox, Obj->hitbox)){
        tar->dele = true;
        // self->dele = true;
        if(!Obj->super_mode)
            Obj->hp -= 5;
        }
    }              
}
void Ufo_draw(Elements *self)
{
    Ufo *Obj = ((Ufo *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Ufo_destory(Elements *self)
{
    Ufo *Obj = ((Ufo *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj->hitbox);
    free(Obj);
    free(self);
}
