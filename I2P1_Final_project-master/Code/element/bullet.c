#include "bullet.h"
#include "../shapes/Circle.h"
#include"enemy.h"
#include"../global.h"
#define PI acos(-1)
/*
   [Bullet function]
*/
Elements *New_Bullet(int label, int x, int y, int vx, int vy, double angle, int dir)
{
    Bullet *pDerivedObj = (Bullet *)malloc(sizeof(Bullet));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/lightball.png"); /////////////////////
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
    pObj->inter_obj[pObj->inter_len++] = Enemy_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy2_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy3_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy4_L;
    pObj->inter_obj[pObj->inter_len++] = Enemy5_L;

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Bullet_update;
    pObj->Interact = Bullet_interact;
    pObj->Draw = Bullet_draw;
    pObj->Destroy = Bullet_destory;

    return pObj;
}
void Bullet_update(Elements *self)
{
    Bullet *Obj = ((Bullet *)(self->pDerivedObj));
    if (Obj->y > HEIGHT||Obj->x < -Obj->width||Obj->x >WIDTH||Obj->y<-WIDTH||Obj->y<-Obj->height)
        self->dele = true; 
    _Bullet_update_position(self, Obj->vx, Obj->vy);          ///////////////////子彈方向更改
}
void _Bullet_update_position(Elements *self, int dx, int dy)
{
    Bullet *Obj = ((Bullet *)(self->pDerivedObj));
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
        Obj->x += dx;
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
}
void Bullet_interact(Elements *self, Elements *tar)
{
    Bullet *Obj = ((Bullet *)(self->pDerivedObj));
    if (tar->label == Enemy_L)
    {
        Enemy *enemy = ((Enemy *)(tar->pDerivedObj));
        if (enemy->hitbox->overlap(enemy->hitbox, Obj->hitbox)){
        enemy->life--;
        if(enemy->life<=0){
            tar->dele = true;
            SCORE+=10;
        }
        self->dele = true;
        }
    }
    else if (tar->label == Enemy2_L)
    {
        Enemy2 *enemy2 = ((Enemy2 *)(tar->pDerivedObj));
        if (enemy2->hitbox->overlap(enemy2->hitbox, Obj->hitbox)){
        enemy2->life--;
        if(enemy2->life<=0){
            tar->dele = true;
            SCORE+=10;
        }
        self->dele = true;
        }
    }
    else if (tar->label == Enemy3_L)
    {
        Enemy3 *enemy2 = ((Enemy3 *)(tar->pDerivedObj));
        if (enemy2->hitbox->overlap(enemy2->hitbox, Obj->hitbox)){
        
        enemy2->life--;
        if(enemy2->life<=0){
            tar->dele = true;
            SCORE+=30;
        }
        self->dele = true;
        }
    }
    else if (tar->label == Enemy4_L)
    {
        Enemy4 *enemy2 = ((Enemy4 *)(tar->pDerivedObj));
        if (enemy2->hitbox->overlap(enemy2->hitbox, Obj->hitbox)){
        enemy2->life--;
        if(enemy2->life<=0){
            tar->dele = true;
            SCORE+=20;
        }
        self->dele = true;
        }
    }
    else if (tar->label == Enemy5_L)
    {
        Enemy5 *enemy2 = ((Enemy5 *)(tar->pDerivedObj));
        if (enemy2->hitbox->overlap(enemy2->hitbox, Obj->hitbox)){
        enemy2->life--;
        if(enemy2->life<=0){
            tar->dele = true;
            SCORE+=50;
        }
        self->dele = true;
        }
    }
}
void Bullet_draw(Elements *self)
{
    Bullet *Obj = ((Bullet *)(self->pDerivedObj));
    if (Obj->vy > 0)
        al_draw_bitmap(Obj->img, Obj->x, Obj->y, ALLEGRO_FLIP_HORIZONTAL);
    else
        al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Bullet_destory(Elements *self)
{
    Bullet *Obj = ((Bullet *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj->hitbox);
    free(Obj);
    free(self);
}
