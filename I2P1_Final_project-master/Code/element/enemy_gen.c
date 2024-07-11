#include"enemy_gen.h"
#include "../scene/sceneManager.h"
#include "enemy.h"
#include"enemy2.h"
#include"enemy3.h"
#include"enemy4.h"
#include"enemy5.h"
#include "../shapes/Rectangle.h"
#include "../algif5/src/algif.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include<stdlib.h>
#include"../global.h"
/*
   [Enemy_gen function]
*/
Elements *New_Enemy_gen(int label)
{
    Enemy_gen *pDerivedObj = (Enemy_gen *)malloc(sizeof(Enemy_gen));
    Elements *pObj = New_Elements(label);
    // pDerivedObj->img = al_load_bitmap("assets/image/ufo.png"); ///////////////////////////////////////////////////
    // pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    // pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    // pDerivedObj->x = WIDTH/2;
    // pDerivedObj->y = pDerivedObj->height;
    // setting derived object member
    pDerivedObj->gen=true;
    pDerivedObj->start_time=al_get_time();
    pDerivedObj->now_time=pDerivedObj->start_time;
    turn=0;
    cycle=0;
    for(int i=0;i<=10;i++)
        pDerivedObj->cycle_gen[i]=true;
    pDerivedObj->leave_time[0]=2;
    pDerivedObj->leave_time[1]=2;
    pDerivedObj->leave_time[2]=5;
    pDerivedObj->leave_time[3]=2;
    pDerivedObj->leave_time[4]=15;
    pDerivedObj->leave_time[5]=2;
    pDerivedObj->leave_time[6]=5;
    pDerivedObj->leave_time[7]=2;
    pDerivedObj->leave_time[8]=10;
    pDerivedObj->leave_time[9]=2;
    pDerivedObj->leave_time[10]=15;
    pDerivedObj->enemy_start_num[1]=8;
    pDerivedObj->enemy_start_num[2]=6;
    pDerivedObj->enemy_start_num[3]=2;
    pDerivedObj->enemy_start_num[4]=3;
    pDerivedObj->enemy_start_num[5]=1;
    pDerivedObj->enemy_num=8;
    pDerivedObj->enemy_num2=6;
    pDerivedObj->enemy_num3=2;
    pDerivedObj->enemy_num4=3;
    pDerivedObj->enemy_num5=1;
    pDerivedObj->attack_time=3;
    pDerivedObj->attack_time2=5;
    pDerivedObj->attack_time3=5;
    pDerivedObj->attack_time4=5;
    pDerivedObj->attack_time5=5;
    pDerivedObj->last_exe_time=al_get_time();
    pDerivedObj->last_exe_time2=pDerivedObj->last_exe_time;
    pDerivedObj->last_exe_time3=pDerivedObj->last_exe_time;
    pDerivedObj->last_exe_time4=pDerivedObj->last_exe_time;
    pDerivedObj->last_exe_time5=pDerivedObj->last_exe_time;
    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Enemy_gen_update;
    pObj->Interact = Enemy_gen_interact;
    pObj->Draw = Enemy_gen_draw;
    pObj->Destroy = Enemy_gen_destory;
    return pObj;
}
void Enemy_gen_update(Elements *self) 
{
    Enemy_gen *Obj = ((Enemy_gen *)(self->pDerivedObj));
    Obj->new_bul = false;
    Obj->now_time=al_get_time();
    Obj->exe_time=Obj->now_time-Obj->start_time;
    time_t t;
    srand((unsigned)time(&t));
    if(cycle==0&&Obj->exe_time>=Obj->leave_time[0]){
        cycle++;
        Obj->start_time=Obj->now_time;
    }
    else if(cycle==1&&Obj->exe_time>=Obj->leave_time[1]){
        cycle++;
        Obj->start_time=Obj->now_time;
    }
    else if(cycle==2&&Obj->exe_time>=Obj->leave_time[2]){
        cycle++;
        Obj->start_time=Obj->now_time;
    }
    else if(cycle==3&&Obj->exe_time>=Obj->leave_time[3]){
        cycle++;
        Obj->start_time=Obj->now_time;
    }
    else if(cycle==4&&Obj->exe_time>=Obj->leave_time[4]){
        cycle++;
        Obj->start_time=Obj->now_time;
    }
    else if(cycle==5&&Obj->exe_time>=Obj->leave_time[5]){
        cycle++;
        Obj->start_time=Obj->now_time;
    }
    else if(cycle==6&&Obj->exe_time>=Obj->leave_time[6]){
        cycle++;
        Obj->start_time=Obj->now_time;
    }
    else if(cycle==7&&Obj->exe_time>=Obj->leave_time[7]){
        cycle++;
        Obj->start_time=Obj->now_time;
    }
    else if(cycle==8&&Obj->exe_time>=Obj->leave_time[8]){
        cycle++;
        Obj->start_time=Obj->now_time;
    }
    else if(cycle==9&&Obj->exe_time>=Obj->leave_time[9]){
        cycle++;
        Obj->start_time=Obj->now_time;
    }
    else if(cycle==10&&Obj->exe_time>=Obj->leave_time[10]){
        cycle=1;
        Obj->start_time=Obj->now_time;
        turn++;
        if(Obj->enemy_num<12)
            Obj->enemy_num=Obj->enemy_start_num[1]+turn*2;
        if(Obj->enemy_num2<10)
            Obj->enemy_num2=Obj->enemy_start_num[2]+turn;
        if(Obj->enemy_num3<4)
            Obj->enemy_num3=Obj->enemy_start_num[3]+turn;
        if(Obj->enemy_num4<6)
            Obj->enemy_num4=Obj->enemy_start_num[4]+turn;
        if(Obj->enemy_num5<3)
            Obj->enemy_num5=Obj->enemy_start_num[5]+turn;
        for(int i=0;i<=10;i++)
            Obj->cycle_gen[i]=true;
    }
    if(key_state[ALLEGRO_KEY_O]){
        if(Obj->gen){
            for(int i=0;i<5;i++){
                turn++;
                if(Obj->enemy_num<12)
                    Obj->enemy_num=Obj->enemy_start_num[1]+turn*2;
                if(Obj->enemy_num2<10)
                    Obj->enemy_num2=Obj->enemy_start_num[2]+turn;
                if(Obj->enemy_num3<4)
                    Obj->enemy_num3=Obj->enemy_start_num[3]+turn;
                if(Obj->enemy_num4<6)
                    Obj->enemy_num4=Obj->enemy_start_num[4]+turn;
                if(Obj->enemy_num5<3)
                    Obj->enemy_num5=Obj->enemy_start_num[5]+turn;
            }
            Obj->gen=false;
        }
    }
    // if(Obj->now_time-Obj->last_exe_time>Obj->attack_time){
    //     for(int  i=1;i<=Obj->enemy_num;i++){
    //         Elements *pro;
    //         time_t t;
    //         srand((unsigned)time(&t));
    //         pro = New_Enemy(Enemy_L, WIDTH/Obj->enemy_num*i-WIDTH/12-64, -HEIGHT/12, rand()%10+10);
    //         _Register_elements(scene, pro);
    //     }
    //     Obj->last_exe_time=Obj->now_time;
    // }
    // if(Obj->now_time-Obj->last_exe_time2>Obj->attack_time2){
    //     for(int  i=0;i<Obj->enemy_num2;i++){
    //         Elements *pro;
    //         pro = New_Enemy2(Enemy2_L,(WIDTH/Obj->enemy_num2)*i+ ((WIDTH/Obj->enemy_num2)*(((double)(rand()%10))/9)), -HEIGHT/12, 10);
    //         _Register_elements(scene, pro);
    //     }
    //     Obj->last_exe_time2=Obj->now_time;
    // }
    
    // if(Obj->now_time-Obj->last_exe_time3>Obj->attack_time3){
    //     for(int  i=0;i<Obj->enemy_num3;i++){
    //         Elements *pro;
    //         pro = New_Enemy3(Enemy3_L,(WIDTH/Obj->enemy_num3)*i+ ((WIDTH/Obj->enemy_num3)*(((double)(rand()%10))/9)), -HEIGHT/12, 10);
    //         _Register_elements(scene, pro);
    //     }
    //     Obj->last_exe_time3=Obj->now_time;
        
    // }
    // if(Obj->now_time-Obj->last_exe_time4>Obj->attack_time4){
    //     for(int  i=0;i<Obj->enemy_num4;i++){
    //         Elements *pro;
    //         pro = New_Enemy4(Enemy4_L,(WIDTH/Obj->enemy_num4)*i+ ((WIDTH/Obj->enemy_num4)*(((double)(rand()%10))/9)), -HEIGHT/12, 10);
    //         _Register_elements(scene, pro);
    //     }
    //     Obj->last_exe_time4=Obj->now_time;
        
    // }
    // // if(Obj->gen)
    // if(Obj->now_time-Obj->last_exe_time5>Obj->attack_time5){
    //     for(int  i=0;i<Obj->enemy_num5;i++){
    //         Elements *pro;
    //         pro = New_Enemy5(Enemy5_L,(WIDTH/Obj->enemy_num5)*i+ (WIDTH/(Obj->enemy_num5*2)), -HEIGHT/12, 10);
    //         _Register_elements(scene, pro);
    //     }
    //     Obj->last_exe_time5=Obj->now_time;
    //     Obj->gen=false;
    // }
    if(cycle==1){
        if(Obj->cycle_gen[cycle]){
            for(int  i=1;i<=Obj->enemy_num;i++){
                Elements *pro;
                time_t t;
                srand((unsigned)time(&t));
                pro = New_Enemy(Enemy_L, WIDTH/Obj->enemy_num*i-WIDTH/12-64, -HEIGHT/12, rand()%10+10,turn);
                _Register_elements(scene, pro);
            }
            Obj->cycle_gen[cycle]=false;
        }
    }
    else if(cycle==2){
        if(Obj->cycle_gen[cycle]){
            for(int  i=0;i<Obj->enemy_num2;i++){
                Elements *pro;
                pro = New_Enemy2(Enemy2_L,(0.95*WIDTH/Obj->enemy_num2)*i+ ((0.95*WIDTH/(Obj->enemy_num2))*(((double)(rand()%9)+1)/9))-64, -HEIGHT/12, 10,Obj->leave_time[cycle],turn);
                _Register_elements(scene, pro);
            }
            Obj->cycle_gen[cycle]=false;
        }
    }
    else if(cycle==3){
        if(Obj->cycle_gen[cycle]){
            for(int  i=1;i<=(Obj->enemy_num);i++){
                Elements *pro;
                time_t t;
                srand((unsigned)time(&t));
                pro = New_Enemy(Enemy_L, WIDTH/(Obj->enemy_num)*i-WIDTH/12-64, -HEIGHT/12, rand()%10+10,turn);
                _Register_elements(scene, pro);
            }
            Obj->cycle_gen[cycle]=false;
        }
    }
    else if(cycle==4){
        if(Obj->cycle_gen[cycle]){
            for(int  i=0;i<(Obj->enemy_num3);i++){
                Elements *pro;
                pro = New_Enemy3(Enemy3_L,(0.95*WIDTH/(Obj->enemy_num3))*i+ ((0.95*WIDTH/(Obj->enemy_num3))*(((double)(rand()%9)+1)/9))-64, -HEIGHT/12, 10,Obj->leave_time[cycle],turn);
                _Register_elements(scene, pro);
            }   
            Obj->cycle_gen[cycle]=false;
        }
    }
    else if(cycle==5){
        if(Obj->cycle_gen[cycle]){
            for(int  i=1;i<=(Obj->enemy_num);i++){
                Elements *pro;
                time_t t;
                srand((unsigned)time(&t));
                pro = New_Enemy(Enemy_L, WIDTH/(Obj->enemy_num)*i-WIDTH/12-64, -HEIGHT/12, rand()%10+10,turn);
                _Register_elements(scene, pro);
            }
            Obj->cycle_gen[cycle]=false;
        }
    }
    else if(cycle==6){
        if(Obj->cycle_gen[cycle]){
            for(int  i=0;i<(Obj->enemy_num2);i++){
                Elements *pro;
                pro = New_Enemy2(Enemy2_L,(0.95*WIDTH/(Obj->enemy_num2))*i+ ((0.95*WIDTH/(Obj->enemy_num2))*(((double)(rand()%9)+1)/9))-64, -HEIGHT/12, 10,Obj->leave_time[cycle],turn);
                _Register_elements(scene, pro);
            }
            Obj->cycle_gen[cycle]=false;
        }
    }
    else if(cycle==7){
        if(Obj->cycle_gen[cycle]){
            for(int  i=1;i<=(Obj->enemy_num);i++){
                Elements *pro;
                time_t t;
                srand((unsigned)time(&t));
                pro = New_Enemy(Enemy_L, WIDTH/(Obj->enemy_num)*i-WIDTH/12-64, -HEIGHT/12, rand()%10+10,turn);
                _Register_elements(scene, pro);
            }
            Obj->cycle_gen[cycle]=false;
        }
    }
    else if(cycle==8){
        if(Obj->cycle_gen[cycle]){
            for(int  i=0;i<(Obj->enemy_num4);i++){
                Elements *pro;
                pro = New_Enemy4(Enemy4_L,(0.95*WIDTH/(Obj->enemy_num4))*i+ ((0.95*WIDTH/(Obj->enemy_num4))*(((double)(rand()%9)+1)/9))-64, -HEIGHT/12, 10,Obj->leave_time[cycle],turn);
                _Register_elements(scene, pro);
            }
            Obj->cycle_gen[cycle]=false;
        }
    }
    else if(cycle==9){
        if(Obj->cycle_gen[cycle]){
            for(int  i=1;i<=(Obj->enemy_num);i++){
                Elements *pro;
                time_t t;
                srand((unsigned)time(&t));
                pro = New_Enemy(Enemy_L, WIDTH/(Obj->enemy_num)*i-WIDTH/12-64, -HEIGHT/12, rand()%10+10,turn);
                _Register_elements(scene, pro);
            }
            Obj->cycle_gen[cycle]=false;
        }
    }
    else if(cycle==10){
        if(Obj->cycle_gen[cycle]){
            for(int  i=0;i<(Obj->enemy_num5);i++){
                Elements *pro;
                pro = New_Enemy5(Enemy5_L,(WIDTH/(Obj->enemy_num5))*i+ (WIDTH/((Obj->enemy_num5)*2))-64, -HEIGHT/12, 10,Obj->leave_time[cycle],turn);
                _Register_elements(scene, pro);
            }
            Obj->cycle_gen[cycle]=false;
        }
    }
}
void Enemy_gen_interact(Elements *self, Elements *tar) {}
void Enemy_gen_draw(Elements *self){}
void Enemy_gen_destory(Elements *self)
{
    Enemy_gen *Obj = ((Enemy_gen *)(self->pDerivedObj));
    free(Obj);
    free(self);
}
