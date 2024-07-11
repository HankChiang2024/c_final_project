#include"blood.h"
#include "../shapes/Rectangle.h"
#include <allegro5/allegro_primitives.h>
#include "../global.h"
#include"ufo.h"
/*
   [Blood function]
*/
Elements *New_Blood(int label)
{
    Blood *pDerivedObj = (Blood *)malloc(sizeof(Blood));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/blood.png");
    pDerivedObj->x = 0;
    pDerivedObj->y = 0;
    pDerivedObj->width = 265;
    pDerivedObj->height = 30;
    pDerivedObj->percentage=1;
    pDerivedObj->color = al_map_rgb(255, 0, 0);
    pDerivedObj->color_b = al_map_rgb(255, 255, 255);
    pObj->inter_obj[pObj->inter_len++] = Ufo_L;
    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Blood_update;
    pObj->Interact = Blood_interact;
    pObj->Draw = Blood_draw;
    pObj->Destroy = Blood_destory;
    return pObj;
}
void Blood_update(Elements *self) {}
void Blood_interact(Elements *self, Elements *tar) {
    Blood *Obj = ((Blood *)(self->pDerivedObj));
    Ufo *Obj2 = ((Ufo *)(tar->pDerivedObj));
    Obj->percentage=Obj2->hp/Obj2->hp_max;
}
void Blood_draw(Elements *self)
{
    Blood *Obj = ((Blood *)(self->pDerivedObj));
    
    // al_draw_filled_rectangle(Obj->x, Obj->y,Obj->x+Obj->width,Obj->y+Obj->height,Obj->color_b);
    al_draw_filled_rectangle(Obj->x+50, Obj->y+25,Obj->x+50+Obj->width*Obj->percentage,Obj->y+Obj->height+25,Obj->color);
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Blood_destory(Elements *self)
{
    Blood *Obj = ((Blood *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
