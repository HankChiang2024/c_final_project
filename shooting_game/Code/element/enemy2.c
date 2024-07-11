#include "enemy2.h"

#include "../scene/sceneManager.h"
#include "fire.h"
#include "../shapes/Rectangle.h"
#include "../algif5/src/algif.h"
#include <stdio.h>
#include <stdbool.h>
#include"../global.h"
/*
   [Enemy2 function]
*/
Elements *New_Enemy2(int label,int x,int y,int v,double leave_time,int difficulty)
{
    Enemy2 *pDerivedObj = (Enemy2 *)malloc(sizeof(Enemy2));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/enemy2.png"); ///////////////////////////////////////////////////
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pDerivedObj->x = x;
    pDerivedObj->y = y;
    pDerivedObj->v = v;
    pDerivedObj->life=1+difficulty/2;
    pDerivedObj->new_bul = false;
    pDerivedObj->fire_mod = false;
    pDerivedObj->cd=0.1;
    pDerivedObj->last_exe_time=0;
    pDerivedObj->start_time=al_get_time();
    pDerivedObj->leave_time=leave_time;
    pDerivedObj->atk_time=(difficulty<=5)?(2-0.2*difficulty):1;
    pDerivedObj->hitbox = New_Rectangle(pDerivedObj->x + pDerivedObj->width / 3,
                                        pDerivedObj->y + pDerivedObj->height / 3,
                                        pDerivedObj->x + 2 * pDerivedObj->width / 3,
                                        pDerivedObj->y + 2 * pDerivedObj->height / 3);
    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Enemy2_update;
    pObj->Interact = Enemy2_interact;
    pObj->Draw = Enemy2_draw;
    pObj->Destroy = Enemy2_destory;
    return pObj;
}
void Enemy2_update(Elements *self) 
{
    Enemy2 *Obj = ((Enemy2 *)(self->pDerivedObj));
    if(Obj->now_time-Obj->start_time>Obj->leave_time){
        _Enemy2_update_position(self, 0, -Obj->v);
        if (Obj->y<-Obj->height)
            self->dele = true;
    }
    else {
        if(Obj->y<=WIDTH/12)
            _Enemy2_update_position(self, 0, Obj->v);
        else
            Obj->fire_mod=true;
    }
    Obj->now_time=al_get_time();
    if(Obj->fire_mod){
        if(Obj->now_time-Obj->last_exe_time>=Obj->atk_time){
            Elements *pro;
            pro = New_Fire(Fire_L, Obj->x+Obj->width/2, Obj->y+Obj->height, 0, 10, 0, 2);
            _Register_elements(scene, pro);
            Obj->last_exe_time=Obj->now_time;
        }

    }
}
void Enemy2_interact(Elements *self, Elements *tar) {
    // Enemy2 *Obj = ((Enemy2 *)(self->pDerivedObj));
}
void Enemy2_draw(Elements *self)
{
    Enemy2 *Obj = ((Enemy2 *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Enemy2_destory(Elements *self)
{
    Enemy2 *Obj = ((Enemy2 *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj->hitbox);
    free(Obj);
    free(self);
}
void _Enemy2_update_position(Elements *self, int dx, int dy)
{
    Enemy2 *Obj = ((Enemy2 *)(self->pDerivedObj));
    Obj->x += dx;
    Obj->y += dy;
    Shape *hitbox = Obj->hitbox;
    hitbox->update_center_x(hitbox, dx);
    hitbox->update_center_y(hitbox, dy);
}
