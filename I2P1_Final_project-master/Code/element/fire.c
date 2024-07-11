#include "fire.h"
#include "../shapes/Circle.h"
#include"ufo.h"
#include"../global.h"
#define PI acos(-1)
/*
   [Fire function]
*/
Elements *New_Fire(int label, int x, int y, int vx, int vy, double angle, int dir)
{
    Fire *pDerivedObj = (Fire *)malloc(sizeof(Fire));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/red.png"); /////////////////////
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pDerivedObj->x = x-pDerivedObj->width/2;//對位置
    pDerivedObj->y = y-pDerivedObj->height/2;
    pDerivedObj->dir = dir;
    pDerivedObj->angle = angle;
    pDerivedObj->vx = vx;
    pDerivedObj->vy = vy;
    pDerivedObj->hitbox = New_Circle(pDerivedObj->x + pDerivedObj->width / 2,
                                     pDerivedObj->y + pDerivedObj->height / 2,
                                     min(pDerivedObj->width, pDerivedObj->height) / 2);
    // setting the interact object
    // pObj->inter_obj[pObj->inter_len++] = Ufo_L;

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Fire_update;
    pObj->Interact = Fire_interact;
    pObj->Draw = Fire_draw;
    pObj->Destroy = Fire_destory;

    return pObj;
}
void Fire_update(Elements *self)
{
    Fire *Obj = ((Fire *)(self->pDerivedObj));
    if (Obj->y > HEIGHT||Obj->x < 0-Obj->width||Obj->x >WIDTH)
        self->dele = true; 
    _Fire_update_position(self, Obj->vx, Obj->vy);          ///////////////////子彈方向更改
}
void _Fire_update_position(Elements *self, int dx, int dy)
{
    Fire *Obj = ((Fire *)(self->pDerivedObj));
    if(Obj->dir==1){
        Obj->x += dx*cos(Obj->angle);
        Obj->y += dy*sin(Obj->angle);
        Obj->angle-=0.1;
        if(Obj->angle<=-PI)    Obj->angle=PI;
        Shape *hitbox = Obj->hitbox;
        hitbox->update_center_x(hitbox, dx*cos(Obj->angle));
        hitbox->update_center_y(hitbox, dy*sin(Obj->angle));
    }
    else if(Obj->dir==2){    
        // Obj->x += dx;
        Obj->y += dy;
        Shape *hitbox = Obj->hitbox;
        hitbox->update_center_x(hitbox, dx);
        hitbox->update_center_y(hitbox, dy);
    }
    else if(Obj->dir==3){
        Obj->x += dx*cos(Obj->angle);
        Obj->y += dy*sin(Obj->angle);
        Obj->angle+=0.1;
        if(Obj->angle>=2*PI)    Obj->angle=0;
        Shape *hitbox = Obj->hitbox;
        hitbox->update_center_x(hitbox, dx*cos(Obj->angle));
        hitbox->update_center_y(hitbox, dy*sin(Obj->angle));
    }
}
void Fire_interact(Elements *self, Elements *tar)
{
    // Fire *Obj = ((Fire *)(self->pDerivedObj));

    // if (tar->label == Ufo_L)
    // {
    //     Ufo *ufo = ((Ufo *)(tar->pDerivedObj));
    //     if (ufo->hitbox->overlap(ufo->hitbox, Obj->hitbox)){
    //     ufo->hp-=10;
    //     self->dele = true;
    //     }
    // }

    // else if (Obj->y > HEIGHT)
    //         self->dele = true;
}
void Fire_draw(Elements *self)
{
    Fire *Obj = ((Fire *)(self->pDerivedObj));
    if (Obj->vy > 0)
        al_draw_bitmap(Obj->img, Obj->x, Obj->y, ALLEGRO_FLIP_HORIZONTAL);
    else
        al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Fire_destory(Elements *self)
{
    Fire *Obj = ((Fire *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj->hitbox);
    free(Obj);
    free(self);
}
