#include <allegro5/allegro_primitives.h>
#include "guide.h"
#include <stdbool.h>
#include"../global.h"
/*
   [Guide function]
*/
Scene *New_Guide(int label)
{
    Guide *pDerivedObj = (Guide *)malloc(sizeof(Guide));
    Scene *pObj = New_Scene(label);
    // setting derived object member
    pDerivedObj->font = al_load_ttf_font("assets/font/pirulen.ttf", 60, 0);
    pDerivedObj->background = al_load_bitmap("assets/image/guide.jpg");
    // Load sound
    pDerivedObj->song = al_load_sample("assets/sound/cyberpunk.mp3");
    al_reserve_samples(20);
    pDerivedObj->sample_instance = al_create_sample_instance(pDerivedObj->song);
    pDerivedObj->title_x = WIDTH / 2;
    pDerivedObj->title_y = 11*HEIGHT / 12-10;
    pDerivedObj->now_time=al_get_time();
    pDerivedObj->last_exe_time=pDerivedObj->now_time;
    // Loop the song until the display closes
    al_set_sample_instance_playmode(pDerivedObj->sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(pDerivedObj->sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(pDerivedObj->sample_instance, 0.3*sound_volumn);
    pObj->pDerivedObj = pDerivedObj;
    // setting derived object function
    pObj->Update = Guide_update;
    pObj->Draw = Guide_draw;
    pObj->Destroy = Guide_destroy;
    return pObj;
}
void Guide_update(Scene *self)
{
    Guide *Obj = ((Guide *)(self->pDerivedObj));
    Obj->now_time=al_get_time();
    if(Obj->now_time-Obj->last_exe_time>0.2){
        if (key_state[ALLEGRO_KEY_ENTER])
        {
            self->scene_end = true;
            window = Menu_L;
        }
    }
    return;
}
void Guide_draw(Scene *self)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    Guide *Obj = ((Guide *)(self->pDerivedObj));
    al_draw_bitmap(Obj->background, 0, 0, 0);
    al_draw_text(Obj->font, al_map_rgb(255, 255, 255), Obj->title_x, Obj->title_y, ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to go back to menu");
    al_play_sample_instance(Obj->sample_instance);
}
void Guide_destroy(Scene *self)
{
    Guide *Obj = ((Guide *)(self->pDerivedObj));
    ALLEGRO_BITMAP *background = Obj->background;
    al_destroy_bitmap(background);
    al_destroy_font(Obj->font);
    al_destroy_sample(Obj->song);
    al_destroy_sample_instance(Obj->sample_instance);
    free(Obj);
    free(self);
}
