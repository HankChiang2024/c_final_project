#include "enemy.h"

#include "../scene/sceneManager.h"
#include "bullet.h"
#include "../shapes/Rectangle.h"
#include "../algif5/src/algif.h"
#include <stdio.h>
#include <stdbool.h>
#include"../global.h"

/*
   [Enemy function]
*/
Elements *New_Enemy(int label,int x,int y,int v,int difficulty)
{
    Enemy *pDerivedObj = (Enemy *)malloc(sizeof(Enemy));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/enemy1.png"); ///////////////////////////////////////////////////
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pDerivedObj->x = x;
    pDerivedObj->y = y;
    pDerivedObj->v = v;
    pDerivedObj->life=1+difficulty/2;
    pDerivedObj->new_bul = false;
    pDerivedObj->cd=0.1;
    pDerivedObj->last_exe_time=0;
    pDerivedObj->hitbox = New_Rectangle(pDerivedObj->x + pDerivedObj->width / 3,
                                        pDerivedObj->y + pDerivedObj->height / 3,
                                        pDerivedObj->x + 2 * pDerivedObj->width / 3,
                                        pDerivedObj->y + 2 * pDerivedObj->height / 3);
    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Enemy_update;
    pObj->Interact = Enemy_interact;
    pObj->Draw = Enemy_draw;
    pObj->Destroy = Enemy_destory;
    return pObj;
}
void Enemy_update(Elements *self) 
{
    Enemy *Obj = ((Enemy *)(self->pDerivedObj));
    if (Obj->y >HEIGHT)
        self->dele = true;
    _Enemy_update_position(self, 0, Obj->v);
}
void Enemy_interact(Elements *self, Elements *tar) {
    // Enemy *Obj = ((Enemy *)(self->pDerivedObj));
}
void Enemy_draw(Elements *self)
{
    Enemy *Obj = ((Enemy *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Enemy_destory(Elements *self)
{
    Enemy *Obj = ((Enemy *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj->hitbox);
    free(Obj);
    free(self);
}
void _Enemy_update_position(Elements *self, int dx, int dy)
{
    Enemy *Obj = ((Enemy *)(self->pDerivedObj));
    Obj->x += dx;
    Obj->y += dy;
    Shape *hitbox = Obj->hitbox;
    hitbox->update_center_x(hitbox, dx);
    hitbox->update_center_y(hitbox, dy);
}
