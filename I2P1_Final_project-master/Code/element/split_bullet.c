#include "split_bullet.h"
#include "../shapes/Circle.h"
#include"../global.h"
#include "../scene/sceneManager.h"
#define PI acos(-1)
/*
   [Split_bullet function]
*/
Elements *New_Split_bullet(int label, int x, int y, int vx, int vy, double angle, int dir)
{
    Split_bullet *pDerivedObj = (Split_bullet *)malloc(sizeof(Split_bullet));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/bomb.png"); /////////////////////
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pDerivedObj->x = x-pDerivedObj->width/2;//對位置
    pDerivedObj->y = y-pDerivedObj->height/2;
    pDerivedObj->shift_y=0;
    pDerivedObj->dir = dir;
    pDerivedObj->angle = angle;
    pDerivedObj->vx = vx;
    pDerivedObj->vy = vy;
    pDerivedObj->hitbox = New_Circle(pDerivedObj->x + pDerivedObj->width / 2,
                                     pDerivedObj->y + pDerivedObj->height / 2,
                                     min(pDerivedObj->width, pDerivedObj->height) / 2);
    // setting the interact object

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Split_bullet_update;
    pObj->Interact = Split_bullet_interact;
    pObj->Draw = Split_bullet_draw;
    pObj->Destroy = Split_bullet_destory;

    return pObj;
}
void Split_bullet_update(Elements *self)
{
    Split_bullet *Obj = ((Split_bullet *)(self->pDerivedObj));
    _Split_bullet_update_position(self, Obj->vx, Obj->vy);          ///////////////////子彈方向更改
    Obj->shift_y+=Obj->vy;
    if(Obj->shift_y<=-300){
        Elements *pro1;
        pro1 = New_Bullet(Bullet_L, Obj->x, Obj->y, -20, 0, 0, 2);
        _Register_elements(scene, pro1);
        Elements *pro2;
        pro2 = New_Bullet(Bullet_L, Obj->x, Obj->y, 0, -20, 0, 2);
        _Register_elements(scene, pro2);
        Elements *pro3;
        pro3 = New_Bullet(Bullet_L, Obj->x, Obj->y, 20, 0, 0, 2);
        _Register_elements(scene, pro3);
        Elements *pro4;
        pro4 = New_Bullet(Bullet_L, Obj->x, Obj->y, 14, -14, 0, 2);
        _Register_elements(scene, pro4);
        Elements *pro5;
        pro5 = New_Bullet(Bullet_L, Obj->x, Obj->y, -14, -14, 0, 2);
        _Register_elements(scene, pro5);
        self->dele=true;
    }
}
void _Split_bullet_update_position(Elements *self, int dx, int dy)
{
    Split_bullet *Obj = ((Split_bullet *)(self->pDerivedObj));
    if(Obj->dir==1){
        Obj->x += dx*cos(Obj->angle);
        Obj->y += dy*sin(Obj->angle);
        Obj->angle-=0.01;
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
        Obj->angle+=0.01;
        if(Obj->angle>=2*PI)    Obj->angle=0;
        Shape *hitbox = Obj->hitbox;
        hitbox->update_center_x(hitbox, dx*cos(Obj->angle));
        hitbox->update_center_y(hitbox, dy*sin(Obj->angle));
    }
        // Obj->x += dx;
        // Obj->y += dy;
        // Shape *hitbox = Obj->hitbox;
        // hitbox->update_center_x(hitbox, dx);
        // hitbox->update_center_y(hitbox, dy);
}
void Split_bullet_interact(Elements *self, Elements *tar)
{
    Split_bullet *Obj = ((Split_bullet *)(self->pDerivedObj));
    if (Obj->y < (0 -HEIGHT)||Obj->x < 0-Obj->width||Obj->x >WIDTH)
        self->dele = true; 

    // else if (Obj->y > HEIGHT)
    //         self->dele = true;
}
void Split_bullet_draw(Elements *self)
{
    Split_bullet *Obj = ((Split_bullet *)(self->pDerivedObj));
    if (Obj->vy > 0)
        al_draw_bitmap(Obj->img, Obj->x, Obj->y, ALLEGRO_FLIP_HORIZONTAL);
    else
        al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Split_bullet_destory(Elements *self)
{
    Split_bullet *Obj = ((Split_bullet *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj->hitbox);
    free(Obj);
    free(self);
}
