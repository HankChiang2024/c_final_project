#include "global.h"
#include "shapes/Shape.h"
#include <stdbool.h>
// variables for global usage
bool run = true;
const double FPS = 60.0;
const int WIDTH = 1679;
const int HEIGHT = 1000;
int window = 0;
int SCORE = 0;
int cycle=0;
int turn=0;
double HP=100;
double sound_volumn=1.0;
bool super_mode=false;
int enemy_number=0;
int enemy2_number=0;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT event;
ALLEGRO_TIMER *fps = NULL;
bool key_state[ALLEGRO_KEY_MAX] = {false};
bool mouse_state[ALLEGRO_MOUSE_MAX_EXTRA_AXES] = {false};
Point mouse;
bool debug_mode = true;
