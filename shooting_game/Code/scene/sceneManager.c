#include "sceneManager.h"
#include "menu.h"
#include "gamescene.h"
#include "guide.h"
#include"lose.h"
#include"setting.h"
#include"story.h"
Scene *scene = NULL;
void create_scene(SceneType type)
{
    switch (type)
    {
    case Menu_L:
        scene = New_Menu(Menu_L);
        break;
    case GameScene_L:
        scene = New_GameScene(GameScene_L);
        break;
    case Guide_L:
        scene = New_Guide(Guide_L);
        break;
    case Lose_L:
        scene = New_lose(Lose_L);
        break;
    case Setting_L:
        scene = New_Setting(Setting_L);
        break;
    case Story_L:
        scene = New_Story(Story_L);
        break;
    default:
        break;
    }
}