#include <allegro5/allegro_primitives.h>
#include "menu.h"
#include <stdbool.h>
#include"../global.h"
/*
   [Menu function]
*/
Scene *New_Menu(int label)
{
    Menu *pDerivedObj = (Menu *)malloc(sizeof(Menu));
    Scene *pObj = New_Scene(label);
    // setting derived object member
    pDerivedObj->font = al_load_ttf_font("assets/font/pirulen.ttf", 60, 0);
    pDerivedObj->background = al_load_bitmap("assets/image/menu.jpg");
    // Load sound
    pDerivedObj->song = al_load_sample("assets/sound/cyberpunk.mp3");
    al_reserve_samples(20);
    pDerivedObj->sample_instance = al_create_sample_instance(pDerivedObj->song);
    pDerivedObj->title_x = 7*WIDTH / 10;
    pDerivedObj->title_y = 0;
    // Loop the song until the display closes
    al_set_sample_instance_playmode(pDerivedObj->sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(pDerivedObj->sample_instance, al_get_default_mixer());
    pDerivedObj->select=Start_S;
    pDerivedObj->last_exe_time=al_get_time();
    pDerivedObj->now_time=pDerivedObj->last_exe_time;
    // set the volume of instance
    al_set_sample_instance_gain(pDerivedObj->sample_instance, 0.3*sound_volumn);
    pObj->pDerivedObj = pDerivedObj;
    // setting derived object function
    pObj->Update = menu_update;
    pObj->Draw = menu_draw;
    pObj->Destroy = menu_destroy;
    return pObj;
}
void menu_update(Scene *self)
{
    Menu *Obj = ((Menu *)(self->pDerivedObj));
    Obj->now_time=al_get_time();

    if(Obj->now_time-Obj->last_exe_time>0.5){
        if (Obj->select==Start_S&&key_state[ALLEGRO_KEY_ENTER])
        {
            self->scene_end = true;
            window = GameScene_L;
            Obj->last_exe_time=Obj->now_time;
        }
        else if (Obj->select==Quit_S&&key_state[ALLEGRO_KEY_ENTER])
        {
            self->scene_end = true;
            run=false;
        }
        else if (Obj->select==Guide_S&&key_state[ALLEGRO_KEY_ENTER])
        {
            self->scene_end = true;
            window = Guide_L;
            Obj->last_exe_time=Obj->now_time;
        }
        else if (Obj->select==Story_S&&key_state[ALLEGRO_KEY_ENTER])
        {
            self->scene_end = true;
            window = Story_L;
            Obj->last_exe_time=Obj->now_time;
        }
        else if (Obj->select==Setting_S&&key_state[ALLEGRO_KEY_ENTER])
        {
            self->scene_end = true;
            window = Setting_L;
            Obj->last_exe_time=Obj->now_time;
        }
        else if(key_state[ALLEGRO_KEY_DOWN]){
            if(Obj->select!=Quit_S)Obj->select++;
            else Obj->select=Start_S;
            Obj->last_exe_time=Obj->now_time;
        }
        else if(key_state[ALLEGRO_KEY_UP]){
            if(Obj->select!=Start_S)Obj->select--;
            else Obj->select=Quit_S;
            Obj->last_exe_time=Obj->now_time;
        }
    }
    return;
}
void menu_draw(Scene *self)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    Menu *Obj = ((Menu *)(self->pDerivedObj));
    al_draw_bitmap(Obj->background, 0, 0, 0);
    al_draw_text(Obj->font, (Obj->select==Start_S)?al_map_rgb(255, 255, 255):al_map_rgb(100, 100, 100), Obj->title_x, Obj->title_y+2*HEIGHT/16, ALLEGRO_ALIGN_CENTRE, "Start");
    al_draw_text(Obj->font, (Obj->select==Guide_S)?al_map_rgb(255, 255, 255):al_map_rgb(100, 100, 100), Obj->title_x, Obj->title_y+5*HEIGHT/16-15, ALLEGRO_ALIGN_CENTRE, "Guide");
    al_draw_text(Obj->font, (Obj->select==Story_S)?al_map_rgb(255, 255, 255):al_map_rgb(100, 100, 100), Obj->title_x, Obj->title_y+8*HEIGHT/16-30, ALLEGRO_ALIGN_CENTRE, "Story");
    al_draw_text(Obj->font, (Obj->select==Setting_S)?al_map_rgb(255, 255, 255):al_map_rgb(100, 100, 100), Obj->title_x, Obj->title_y+11*HEIGHT/16-45, ALLEGRO_ALIGN_CENTRE, "Setting");
    al_draw_text(Obj->font, (Obj->select==Quit_S)?al_map_rgb(255, 255, 255):al_map_rgb(100, 100, 100), Obj->title_x, Obj->title_y+14*HEIGHT/16-60, ALLEGRO_ALIGN_CENTRE, "Quit");
    al_play_sample_instance(Obj->sample_instance);
}
void menu_destroy(Scene *self)
{
    Menu *Obj = ((Menu *)(self->pDerivedObj));
    ALLEGRO_BITMAP *background = Obj->background;
    al_destroy_bitmap(background);
    al_destroy_font(Obj->font);
    al_destroy_sample(Obj->song);
    al_destroy_sample_instance(Obj->sample_instance);
    free(Obj);
    free(self);
}
