#include "fire_e3.h"
#include "../shapes/Circle.h"
#include"ufo.h"
#include"../global.h"
#define PI acos(-1)
/*
   [Fire_e3 function]
*/
Elements *New_Fire_e3(int label, int x, int y, int vx, int vy, double angle, int dir)
{
    Fire_e3 *pDerivedObj = (Fire_e3 *)malloc(sizeof(Fire_e3));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/blue.png"); /////////////////////
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pDerivedObj->x = x-pDerivedObj->width/2;//對位置
    pDerivedObj->y = y-pDerivedObj->height/2;
    pDerivedObj->dir = dir;
    pDerivedObj->now_time=al_get_time();
    pDerivedObj->start_time=pDerivedObj->now_time;
    pDerivedObj->angle = angle;
    pDerivedObj->vx = vx;
    pDerivedObj->vy = vy;
    pDerivedObj->ai=1.35;
    pDerivedObj->ri=15;
    pDerivedObj->hitbox = New_Circle(pDerivedObj->x + pDerivedObj->width / 2,
                                     pDerivedObj->y + pDerivedObj->height / 2,
                                     min(pDerivedObj->width, pDerivedObj->height) / 2);
    // setting the interact object
    // pObj->inter_obj[pObj->inter_len++] = Ufo_L;

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Fire_e3_update;
    pObj->Interact = Fire_e3_interact;
    pObj->Draw = Fire_e3_draw;
    pObj->Destroy = Fire_e3_destory;

    return pObj;
}
void Fire_e3_update(Elements *self)
{
    Fire_e3 *Obj = ((Fire_e3 *)(self->pDerivedObj));
    Obj->now_time=al_get_time();
    
    Obj->t=Obj->now_time-Obj->start_time;
    if(Obj->dir==1){
        Obj->vx=Obj->ri*cos(-(Obj->ai*Obj->t+Obj->angle))-Obj->ai*Obj->ri*Obj->t*sin(-(Obj->ai*Obj->t+Obj->angle));
        Obj->vy=Obj->ri*sin(-(Obj->ai*Obj->t+Obj->angle))+Obj->ai*Obj->ri*Obj->t*cos(-(Obj->ai*Obj->t+Obj->angle));
    }
    if(Obj->dir==2){
        Obj->vx=Obj->ri*cos(Obj->ai*Obj->t+Obj->angle)-Obj->ai*Obj->ri*Obj->t*sin(Obj->ai*Obj->t+Obj->angle);
        Obj->vy=Obj->ri*sin(Obj->ai*Obj->t+Obj->angle)+Obj->ai*Obj->ri*Obj->t*cos(Obj->ai*Obj->t+Obj->angle);
    }
    if (Obj->y > HEIGHT*2||Obj->x < -WIDTH-Obj->width||Obj->x >2*WIDTH||Obj->y<-WIDTH)
        self->dele = true; 
    _Fire_e3_update_position(self, Obj->vx, Obj->vy);          ///////////////////子彈方向更改
    
}
void _Fire_e3_update_position(Elements *self, int dx, int dy)
{
    Fire_e3 *Obj = ((Fire_e3 *)(self->pDerivedObj));
    if(Obj->dir==1){
        Obj->x += dx;
        Obj->y += dy;
        Shape *hitbox = Obj->hitbox;
        hitbox->update_center_x(hitbox, dx);
        hitbox->update_center_y(hitbox, dy);
    }
    else if(Obj->dir==2){    
        Obj->x += dx;
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
void Fire_e3_interact(Elements *self, Elements *tar)
{
    // Fire_e3 *Obj = ((Fire_e3 *)(self->pDerivedObj));

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
void Fire_e3_draw(Elements *self)
{
    Fire_e3 *Obj = ((Fire_e3 *)(self->pDerivedObj));
    if (Obj->vy > 0)
        al_draw_bitmap(Obj->img, Obj->x, Obj->y, ALLEGRO_FLIP_HORIZONTAL);
    else
        al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Fire_e3_destory(Elements *self)
{
    Fire_e3 *Obj = ((Fire_e3 *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj->hitbox);
    free(Obj);
    free(self);
}
