#include <allegro5/allegro_primitives.h>
#include "lose.h"
#include <stdbool.h>
#include"../global.h"
#include"sceneManager.h"
/*
   [lose function]
*/
Scene *New_lose(int label)
{
    lose *pDerivedObj = (lose *)malloc(sizeof(lose));
    Scene *pObj = New_Scene(label);
    // setting derived object member
    pDerivedObj->font = al_load_ttf_font("assets/font/pirulen.ttf", 60, 0);
    pDerivedObj->background = al_load_bitmap("assets/image/gameover.jpg");
    // Load sound
    pDerivedObj->song = al_load_sample("assets/sound/cyberpunk.mp3");
    al_reserve_samples(20);
    pDerivedObj->sample_instance = al_create_sample_instance(pDerivedObj->song);
    pDerivedObj->title_x = WIDTH / 2;
    pDerivedObj->title_y = 11*HEIGHT / 12-10;
    // Loop the song until the display closes
    al_set_sample_instance_playmode(pDerivedObj->sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(pDerivedObj->sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(pDerivedObj->sample_instance, 0.3*sound_volumn);
    pObj->pDerivedObj = pDerivedObj;
    // setting derived object function
    pObj->Update = lose_update;
    pObj->Draw = lose_draw;
    pObj->Destroy = lose_destroy;
    return pObj;
}
void lose_update(Scene *self)
{
    if (key_state[ALLEGRO_KEY_Q])
    {
        self->scene_end = true;
        run=false;
    }
    if (key_state[ALLEGRO_KEY_ENTER])
    {
        self->scene_end = true;
        HP=100;
        window=Menu_L;
    }

    return;
}
void lose_draw(Scene *self)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    lose *Obj = ((lose *)(self->pDerivedObj));
    al_draw_bitmap(Obj->background, 0, 0, 0);
    al_play_sample_instance(Obj->sample_instance);
    al_draw_textf(Obj->font, al_map_rgb(255, 255, 255), Obj->title_x, Obj->title_y-HEIGHT/5, ALLEGRO_ALIGN_CENTRE, "score:%d",SCORE);
    al_draw_textf(Obj->font, al_map_rgb(255, 255, 255), Obj->title_x, Obj->title_y-50, ALLEGRO_ALIGN_CENTRE, "press q to quit/enter to reset");
}
void lose_destroy(Scene *self)
{
    lose *Obj = ((lose *)(self->pDerivedObj));
    ALLEGRO_BITMAP *background = Obj->background;
    al_destroy_bitmap(background);
    al_destroy_font(Obj->font);
    al_destroy_sample(Obj->song);
    al_destroy_sample_instance(Obj->sample_instance);
    free(Obj);
    free(self);
}
