#include "enemy3.h"

#include "../scene/sceneManager.h"
#include "fire_e3.h"
#include "../shapes/Rectangle.h"
#include "../algif5/src/algif.h"
#include <stdio.h>
#include <stdbool.h>
#include"../global.h"
#include<math.h>
#define PI acos(-1)
/*
   [Enemy3 function]
*/
Elements *New_Enemy3(int label,int x,int y,int v,double leave_time,int difficulty)
{
    Enemy3 *pDerivedObj = (Enemy3 *)malloc(sizeof(Enemy3));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/enemy3.png"); ///////////////////////////////////////////////////
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pDerivedObj->x = x;
    pDerivedObj->y = y;
    pDerivedObj->v = v;
    pDerivedObj->life=2+difficulty/2;
    pDerivedObj->new_bul = false;
    pDerivedObj->fire_mod = false;
    pDerivedObj->cd=0.1;
    pDerivedObj->last_exe_time=0;
    pDerivedObj->start_time=al_get_time();
    pDerivedObj->leave_time=leave_time;
    pDerivedObj->atk_time=0.2;
    pDerivedObj->fire_num=(difficulty<=4)?(4+difficulty):8;
    pDerivedObj->hitbox = New_Rectangle(pDerivedObj->x + pDerivedObj->width / 3,
                                        pDerivedObj->y + pDerivedObj->height / 3,
                                        pDerivedObj->x + 2 * pDerivedObj->width / 3,
                                        pDerivedObj->y + 2 * pDerivedObj->height / 3);
    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Enemy3_update;
    pObj->Interact = Enemy3_interact;
    pObj->Draw = Enemy3_draw;
    pObj->Destroy = Enemy3_destory;
    return pObj;
}
void Enemy3_update(Elements *self) 
{
    Enemy3 *Obj = ((Enemy3 *)(self->pDerivedObj));
    if(Obj->now_time-Obj->start_time>Obj->leave_time){
        _Enemy3_update_position(self, 0, -Obj->v);
        if (Obj->y<-Obj->height)
            self->dele = true;
    }
    else {
        if(Obj->y<=WIDTH/12)
            _Enemy3_update_position(self, 0, Obj->v);
        else
            Obj->fire_mod=true;
    }
    Obj->now_time=al_get_time();
    if(Obj->fire_mod){
        if(Obj->now_time-Obj->last_exe_time>=Obj->atk_time){
            for(int i=0;i<Obj->fire_num;i++){
                Elements *pro;
                pro = New_Fire_e3(Fire_e3_L, Obj->x+Obj->width/2, Obj->y+Obj->height, 0, 10, i*(2*PI/Obj->fire_num), 2);
                _Register_elements(scene, pro);
            }
            Obj->last_exe_time=Obj->now_time;
        }

    }
}
void Enemy3_interact(Elements *self, Elements *tar) {
    // Enemy3 *Obj = ((Enemy3 *)(self->pDerivedObj));
}
void Enemy3_draw(Elements *self)
{
    Enemy3 *Obj = ((Enemy3 *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Enemy3_destory(Elements *self)
{
    Enemy3 *Obj = ((Enemy3 *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj->hitbox);
    free(Obj);
    free(self);
}
void _Enemy3_update_position(Elements *self, int dx, int dy)
{
    Enemy3 *Obj = ((Enemy3 *)(self->pDerivedObj));
    Obj->x += dx;
    Obj->y += dy;
    Shape *hitbox = Obj->hitbox;
    hitbox->update_center_x(hitbox, dx);
    hitbox->update_center_y(hitbox, dy);
}
