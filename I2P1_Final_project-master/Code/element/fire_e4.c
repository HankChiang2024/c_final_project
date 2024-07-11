#include "fire_e4.h"
#include "../shapes/Circle.h"
#include"ufo.h"
#include"../global.h"
#define PI acos(-1)
/*
   [Fire_e4 function]
*/
Elements *New_Fire_e4(int label, int x, int y, int vx, int vy, double angle, int dir)
{
    Fire_e4 *pDerivedObj = (Fire_e4 *)malloc(sizeof(Fire_e4));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/purple.png"); /////////////////////
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pDerivedObj->x = x-pDerivedObj->width/2;//對位置
    pDerivedObj->y = y-pDerivedObj->height/2;
    pDerivedObj->dir = dir;
    pDerivedObj->angle = angle;
    pDerivedObj->vx = vx;
    pDerivedObj->vy = vy;
    pDerivedObj->trace = 1; //////////////////////
    pDerivedObj->hitbox = New_Circle(pDerivedObj->x + pDerivedObj->width / 2,
                                     pDerivedObj->y + pDerivedObj->height / 2,
                                     min(pDerivedObj->width, pDerivedObj->height) / 2);
    // setting the interact object
    // pObj->inter_obj[pObj->inter_len++] = Ufo_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy2_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy3_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy4_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy5_L;
    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Fire_e4_update;
    pObj->Interact = Fire_e4_interact;
    pObj->Draw = Fire_e4_draw;
    pObj->Destroy = Fire_e4_destory;
    return pObj;
}
void Fire_e4_update(Elements *self)
{
    Fire_e4 *Obj = ((Fire_e4 *)(self->pDerivedObj));
    if (Obj->y > HEIGHT||Obj->x < 0-Obj->width||Obj->x >WIDTH||Obj->y<-Obj->height)
        self->dele = true; 
    Obj->dist = sqrt((mouse.x - Obj->x)*(mouse.x - Obj->x) + (mouse.y - Obj->y)*(mouse.y - Obj->y));

    if(Obj->trace)
    {
        Obj->vx = (mouse.x - Obj->x)*15 / Obj->dist;
        Obj->vy = (mouse.y - Obj->y)*15 / Obj->dist;
    }

    if(Obj->dist <= 200)
    {
        Obj->trace = 0;
    }
    

    _Fire_e4_update_position(self, Obj->vx, Obj->vy);          ///////////////////子彈方向更改
}
void _Fire_e4_update_position(Elements *self, int dx, int dy)
{
    Fire_e4 *Obj = ((Fire_e4 *)(self->pDerivedObj));
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
        // Obj->y += dy;
        // Obj->x += (mouse.x - Obj->x) / 100;
        // Obj->y += (mouse.y - Obj->y) / 100;

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
void Fire_e4_interact(Elements *self, Elements *tar)
{
    Fire_e4 *Obj = ((Fire_e4 *)(self->pDerivedObj));
    if(!Obj->trace){
        if (tar->label == Enemy_L)
        {
            Enemy *enemy = ((Enemy *)(tar->pDerivedObj));
            if (enemy->hitbox->overlap(enemy->hitbox, Obj->hitbox)){
            SCORE+=50;
            tar->dele = true;
            self->dele = true;
            }
        }
        else if (tar->label == Enemy2_L)
        {
            Enemy2 *enemy2 = ((Enemy2 *)(tar->pDerivedObj));
            if (enemy2->hitbox->overlap(enemy2->hitbox, Obj->hitbox)){
            SCORE+=50;
            tar->dele = true;
            self->dele = true;
            }
        }
        else if (tar->label == Enemy3_L)
        {
            Enemy3 *enemy2 = ((Enemy3 *)(tar->pDerivedObj));
            if (enemy2->hitbox->overlap(enemy2->hitbox, Obj->hitbox)){
            SCORE+=50;
            tar->dele = true;
            self->dele = true;
            }
        }
        else if (tar->label == Enemy4_L)
        {
            Enemy4 *enemy2 = ((Enemy4 *)(tar->pDerivedObj));
            if (enemy2->hitbox->overlap(enemy2->hitbox, Obj->hitbox)){
            SCORE+=50;
            tar->dele = true;
            self->dele = true;
            }
        }
        else if (tar->label == Enemy5_L)
        {
            Enemy5 *enemy2 = ((Enemy5 *)(tar->pDerivedObj));
            if (enemy2->hitbox->overlap(enemy2->hitbox, Obj->hitbox)){
            SCORE+=50;
            tar->dele = true;
            self->dele = true;
            }
        }
    }

}
void Fire_e4_draw(Elements *self)
{
    Fire_e4 *Obj = ((Fire_e4 *)(self->pDerivedObj));
    if (Obj->vy > 0)
        al_draw_bitmap(Obj->img, Obj->x, Obj->y, ALLEGRO_FLIP_HORIZONTAL);
    else
        al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Fire_e4_destory(Elements *self)
{
    Fire_e4 *Obj = ((Fire_e4 *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj->hitbox);
    free(Obj);
    free(self);
}
