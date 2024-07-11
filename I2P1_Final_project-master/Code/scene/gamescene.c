#include "gamescene.h"
#include"sceneManager.h"
/*
   [GameScene function]
*/
Scene *New_GameScene(int label)
{
    GameScene *pDerivedObj = (GameScene *)malloc(sizeof(GameScene));
    Scene *pObj = New_Scene(label);
    // setting derived object member
    pDerivedObj->font = al_load_ttf_font("assets/font/pirulen.ttf", 48, 0);
    pDerivedObj->background = al_load_bitmap("assets/image/background3.jpg");
    pObj->pDerivedObj = pDerivedObj;
    pDerivedObj->song = al_load_sample("assets/sound/music.mp3");
    al_reserve_samples(20);
    pDerivedObj->sample_instance = al_create_sample_instance(pDerivedObj->song);
    // Loop the song until the display closes
    al_set_sample_instance_playmode(pDerivedObj->sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(pDerivedObj->sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(pDerivedObj->sample_instance, 0.1*sound_volumn);
    // register element
    // _Register_elements(pObj, New_Floor(Floor_L));
    // _Register_elements(pObj, New_Teleport(Teleport_L));
    // _Register_elements(pObj, New_Tree(Tree_L));
    // _Register_elements(pObj, New_Character(Character_L));
    _Register_elements(pObj, New_Ufo(Ufo_L));
    // _Register_elements(pObj, New_Enemy(Enemy_L));
    _Register_elements(pObj, New_Enemy_gen(Enemy_gen_L));
    _Register_elements(pObj, New_Blood(Blood_L));
    // _Register_elements(pObj, New_score_background(Score_L));

    // setting derived object function
    pObj->Update = game_scene_update;
    pObj->Draw = game_scene_draw;
    pObj->Destroy = game_scene_destroy;
    SCORE=0;
    return pObj;
}
void game_scene_update(Scene *self)
{
    if (HP<=0)
    {
        self->scene_end = true;
        window = Lose_L;
    }
    // update every element
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++)
    {
        allEle.arr[i]->Update(allEle.arr[i]);
    }

    // run interact for every element
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        // run every interact object
        for (int j = 0; j < ele->inter_len; j++)
        {
            int inter_label = ele->inter_obj[j];
            ElementVec labelEle = _Get_label_elements(self, inter_label);
            for (int i = 0; i < labelEle.len; i++)
            {
                ele->Interact(ele, labelEle.arr[i]);
            }
        }
    }
    // remove element
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        if (ele->dele)
            _Remove_elements(self, ele);
    }
}
void game_scene_draw(Scene *self)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    GameScene *gs = ((GameScene *)(self->pDerivedObj));
    al_draw_bitmap(gs->background, 0, 0, 0);
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        ele->Draw(ele);
    }
    al_play_sample_instance(gs->sample_instance);
    al_draw_textf(gs->font, al_map_rgb(255, 255, 255), 1000, 10, ALLEGRO_ALIGN_CENTRE, "score:%d        cycle:%d    turn:%d",SCORE,cycle,turn);
}
void game_scene_destroy(Scene *self)
{
    GameScene *Obj = ((GameScene *)(self->pDerivedObj));
    ALLEGRO_BITMAP *background = Obj->background;
    al_destroy_bitmap(background);
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        ele->Destroy(ele);
    }
    al_destroy_font(Obj->font);
    al_destroy_sample(Obj->song);
    al_destroy_sample_instance(Obj->sample_instance);
    free(Obj);
    free(self);
}
