#include"score.h"
#include "../shapes/Rectangle.h"
#include <allegro5/allegro_primitives.h>
#include "../global.h"
/*
   [score_background function]
*/
Elements *New_score_background(int label)
{
    score_background *pDerivedObj = (score_background *)malloc(sizeof(score_background));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->font = al_load_ttf_font("assets/font/pirulen.ttf", 48, 0);
    pDerivedObj->x = 500;
    pDerivedObj->y = 0;
    pDerivedObj->width = 100;
    pDerivedObj->height = 20;
    pDerivedObj->color = al_map_rgb(255, 255, 255);
    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = score_background_update;
    pObj->Interact = score_background_interact;
    pObj->Draw = score_background_draw;
    pObj->Destroy = score_background_destory;
    return pObj;
}
void score_background_update(Elements *self) {}
void score_background_interact(Elements *self, Elements *tar) {}
void score_background_draw(Elements *self)
{
    score_background *Obj = ((score_background *)(self->pDerivedObj));
    al_draw_textf(Obj->font, al_map_rgb(255, 255, 255), Obj->x, Obj->y+10, ALLEGRO_ALIGN_CENTRE, "score:%d",SCORE);
}
void score_background_destory(Elements *self)
{
    score_background *Obj = ((score_background *)(self->pDerivedObj));
    free(Obj);
    free(self);
}
