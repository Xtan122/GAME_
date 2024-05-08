#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 522;
const char* WINDOW_TITLE = "Jump";

#define TIME_MAX 1000
#define GROUND 450
#define MAX_HEIGHT 300

#define IN_AIR_ENEMY 1
#define ON_GROUND_ENEMY 0

#define GROUND_SPEED 5
#define ENEMY_SPEED 10
#define MAX_ENEMY_WIDTH 100

#define FRUIT_SPEED 7
#define MAX_FRUIT_WIDTH 100

const char* FROG_SPRITE_FILE = "imgs\\runn.png";
const int FROG_CLIPS[][4] = {
    {0, 0, 32, 32},
    {32, 0, 32, 32},
    {64, 0, 32, 32},
    {96, 0, 32, 32},
    {128, 0, 32, 32},
    {160, 0, 32, 32},
    {192, 0, 32, 32},
    {224, 0, 32, 32},
    {256, 0, 32, 32},
    {288, 0, 32, 32},
    {320, 0, 32, 32},
    {352, 0, 32, 32},
};
const int FROG_FRAMES = sizeof(FROG_CLIPS)/sizeof(int)/4;

const char* CHAMELEON_SPRITE_FILE = "imgs\\groundenemy.png";
const int CHAMELEON_CLIPS[][4] = {
    {0, 0, 84, 38},
    {84, 0, 84, 38},
    {168, 0, 84, 38},
    {252, 0, 84, 38},
    {336, 0, 84, 38},
    {420, 0, 84, 38},
    {504, 0, 84, 38},
    {588, 0, 84, 38},
};
const int CHAMELEON_FRAMES = sizeof(CHAMELEON_CLIPS)/sizeof(int)/4;

const char* BAT_SPRITE_FILE = "imgs\\airenemy.png";
const int BAT_CLIPS[][4] = {
    {0, 0, 46, 32},
    {46, 0, 46, 32},
    {92, 0, 46, 32},
    {138, 0, 46, 32},
    {184, 0, 46, 32},
    {230, 0, 46, 32},
    {276, 0, 46, 32},
};
const int BAT_FRAMES = sizeof(BAT_CLIPS)/sizeof(int)/4;

const char* SLIME_SPRITE_FILE = "imgs\\slime.png";
const int SLIME_CLIPS[][4] = {
    {0, 0, 44, 30},
    {44, 0, 44, 30},
    {88, 0, 44, 30},
    {132, 0, 44, 30},
    {176, 0, 44, 30},
    {220, 0, 44, 30},
    {264, 0, 44, 30},
    {308, 0, 44, 30},
    {352, 0, 44, 30},
    {396, 0, 44, 30},

};
const int SLIME_FRAMES = sizeof(SLIME_CLIPS)/sizeof(int)/4;

const char* BANANA_SPRITE_FILE = "imgs\\banana.png";
const int BANANA_CLIPS[][4] = {
    {0, 0, 32, 32},
    {32, 0, 32, 32},
    {64, 0, 32, 32},
    {96, 0, 32, 32},
    {128, 0, 32, 32},
    {160, 0, 32, 32},
    {192, 0, 32, 32},
    {224, 0, 32, 32},
    {256, 0, 32, 32},
    {288, 0, 32, 32},
    {320, 0, 32, 32},
    {352, 0, 32, 32},
    {384, 0, 32, 32},
    {416, 0, 32, 32},
    {448, 0, 32, 32},
    {480, 0, 32, 32},
    {512, 0, 32, 32},
};
const int BANANA_FRAMES = sizeof(BANANA_CLIPS) / sizeof(int) / 4;



const char* LAYER1_FILE = "imgs/background/1.png";
const char* LAYER2_FILE = "imgs/background/2.png";
const char* LAYER3_FILE = "imgs/background/3.png";
const char* LAYER4_FILE = "imgs/background/4.png";
const char* LAYER5_FILE = "imgs/background/5.png";
const char* LAYER6_FILE = "imgs/background/6.png";
const char* LAYER7_FILE = "imgs/background/7.png";
const char* LAYER8_FILE = "imgs/background/8.png";


const double LAYER_1_SPEED = 0.0;
const double LAYER_2_SPEED = 0.25;
const double LAYER_3_SPEED = 0.5;
const double LAYER_4_SPEED = 0.75;
const double LAYER_5_SPEED = 1.0;
const double LAYER_6_SPEED = 1.25;
const double LAYER_7_SPEED = 1.5;
const double LAYER_8_SPEED = 1.75;


#define SPEED_INCREASEMENT 2
#define SCORE_INCREASEMENT 1
#define TIME_INCREASEMENT 1
#define FRAME_INCREASEMENT 1

#endif // DEFS_H_INCLUDED
