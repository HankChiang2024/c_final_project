#include <allegro5/allegro_primitives.h>
#include "setting.h"
#include <stdbool.h>
#include"../global.h"
/*
   [Setting function]
*/
Scene *New_Setting(int label)
{
    Setting *pDerivedObj = (Setting *)malloc(sizeof(Setting));
    Scene *pObj = New_Scene(label);
    // setting derived object member
    pDerivedObj->font = al_load_ttf_font("assets/font/pirulen.ttf", 36, 0);
    pDerivedObj->background = al_load_bitmap("assets/image/setting.jpg");
    // Load sound
    pDerivedObj->song = al_load_sample("assets/sound/cyberpunk.mp3");
    al_reserve_samples(20);
    pDerivedObj->sample_instance = al_create_sample_instance(pDerivedObj->song);
    pDerivedObj->title_x = WIDTH / 2;
    pDerivedObj->title_y = 5*HEIGHT / 6;
    pDerivedObj->sound_bar_x=WIDTH / 2-50;
    pDerivedObj->sound_bar_y=3*HEIGHT / 8+10;
    pDerivedObj->sound_bar_width=400;
    pDerivedObj->sound_bar_height=40;
    pDerivedObj->super_mode_x=WIDTH / 2;
    pDerivedObj->super_mode_y=5*HEIGHT / 8+20;
    pDerivedObj->super_mode_width=400;
    pDerivedObj->super_mode_height=40;
    pDerivedObj->color = al_map_rgb(255, 255, 255);
    pDerivedObj->color_b = al_map_rgb(100, 100, 100);
    pDerivedObj->now_time=al_get_time();
    pDerivedObj->last_exe_time=pDerivedObj->now_time;
    pDerivedObj->select=Sound_S;
    // Loop the song until the display closes
    al_set_sample_instance_playmode(pDerivedObj->sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(pDerivedObj->sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(pDerivedObj->sample_instance, 0.3*sound_volumn);
    pObj->pDerivedObj = pDerivedObj;
    // setting derived object function
    pObj->Update = Setting_update;
    pObj->Draw = Setting_draw;
    pObj->Destroy = Setting_destroy;
    return pObj;
}
void Setting_update(Scene *self)
{
    Setting *Obj = ((Setting *)(self->pDerivedObj));
    Obj->now_time=al_get_time();
    if(Obj->now_time-Obj->last_exe_time>0.2){
        if (key_state[ALLEGRO_KEY_ENTER])
        {
            self->scene_end = true;
            window = Menu_L;
        }
        else if(key_state[ALLEGRO_KEY_DOWN]){
            if(Obj->select!=Super_mode_S)Obj->select++;
            else Obj->select=Sound_S;
            Obj->last_exe_time=Obj->now_time;
        }
        else if(key_state[ALLEGRO_KEY_UP]){
            if(Obj->select!=Sound_S)Obj->select--;
            else Obj->select=Super_mode_S;
            Obj->last_exe_time=Obj->now_time;
        }
        else if(Obj->select==Sound_S){
            if(sound_volumn>=0&&key_state[ALLEGRO_KEY_LEFT])
                sound_volumn-=0.01;
            else if(sound_volumn<=1&&key_state[ALLEGRO_KEY_RIGHT])
                sound_volumn+=0.01;
        }
        else if(Obj->select==Super_mode_S){
            if(key_state[ALLEGRO_KEY_LEFT])
                super_mode=true;
            else if(key_state[ALLEGRO_KEY_RIGHT])
                super_mode=false;
        }

    }
    return;
}
void Setting_draw(Scene *self)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    Setting *Obj = ((Setting *)(self->pDerivedObj));
    al_draw_bitmap(Obj->background, 0, 0, 0);
    al_draw_text(Obj->font, al_map_rgb(255, 255, 255), Obj->title_x, Obj->title_y, ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to go back to menu");
    
    // sound
    al_draw_text(Obj->font, (Obj->select==Sound_S)?al_map_rgb(255, 255, 255):al_map_rgb(100, 100, 100), Obj->sound_bar_x-Obj->sound_bar_width/2, Obj->sound_bar_y, ALLEGRO_ALIGN_CENTRE, "Sound");
    al_draw_filled_rectangle(Obj->sound_bar_x, Obj->sound_bar_y,Obj->sound_bar_x+Obj->sound_bar_width,Obj->sound_bar_y+Obj->sound_bar_height,Obj->color_b);
    al_draw_filled_rectangle(Obj->sound_bar_x, Obj->sound_bar_y,Obj->sound_bar_x+Obj->sound_bar_width*sound_volumn,Obj->sound_bar_y+Obj->sound_bar_height,Obj->color);
    // super_mode
    al_draw_text(Obj->font, (Obj->select==Super_mode_S)?al_map_rgb(255, 255, 255):al_map_rgb(100, 100, 100), Obj->super_mode_x-Obj->super_mode_width/2, Obj->super_mode_y, ALLEGRO_ALIGN_CENTRE, "Super_mode");
    al_draw_text(Obj->font, (super_mode)?al_map_rgb(255, 255, 255):al_map_rgb(100, 100, 100), Obj->super_mode_x+Obj->super_mode_width/4, Obj->super_mode_y, ALLEGRO_ALIGN_CENTRE, "On");
    al_draw_text(Obj->font, (!super_mode)?al_map_rgb(255, 255, 255):al_map_rgb(100, 100, 100), Obj->super_mode_x+3*Obj->super_mode_width/4, Obj->super_mode_y, ALLEGRO_ALIGN_CENTRE, "Off");

    al_play_sample_instance(Obj->sample_instance);
}
void Setting_destroy(Scene *self)
{
    Setting *Obj = ((Setting *)(self->pDerivedObj));
    ALLEGRO_BITMAP *background = Obj->background;
    al_destroy_bitmap(background);
    al_destroy_font(Obj->font);
    al_destroy_sample(Obj->song);
    al_destroy_sample_instance(Obj->sample_instance);
    free(Obj);
    free(self);
}
