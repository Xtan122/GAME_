#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 522;
const char* WINDOW_TITLE = "Jump";

#define TIME_MAX 800
#define GROUND 450
#define MAX_HEIGHT 300

#define IN_AIR_ENEMY 1
#define ON_GROUND_ENEMY 0

#define IN_AIR_FRUIT 1
#define ON_GROUND_FRUIT 0

#define GROUND_SPEED 5
#define ENEMY_SPEED 10
#define MAX_ENEMY_WIDTH 100

#define BOSS_SPEED 2
#define MAX_BOSS_WIDTH 100

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

const char* BUNNY_SPRITE_FILE = "imgs\\bunny.png";
const int BUNNY_CLIPS[][4] = {
    {0, 0, 34, 44},
    {34, 0, 34, 44},
    {68, 0, 34, 44},
    {102, 0, 34, 44},
    {136, 0, 34, 44},
    {170, 0, 34, 44},
    {204, 0, 34, 44},
    {238, 0, 34, 44},
    {272, 0, 34, 44},
    {306, 0, 34, 44},
    {340, 0, 34, 44},
    {374, 0, 34, 44},
};
const int BUNNY_FRAMES = sizeof(BUNNY_CLIPS) / sizeof(int) / 4;

const char* GUARDIAN_SPRITE_FILE = "imgs\\guardian.png";
const int GUARDIAN_CLIPS[][4] = {
    {0, 0, 192, 128},
    {192, 0, 192, 128},
    {384, 0, 192, 128},
    {576, 0, 192, 128},
    {768, 0, 192, 128},
    {960, 0, 192, 128},
    {1152, 0, 192, 128},
    {1344, 0, 192, 128},
    {1536, 0, 192, 128},
    {1728, 0, 192, 128}
};
const int GUARDIAN_FRAMES = sizeof(GUARDIAN_CLIPS) / sizeof(GUARDIAN_CLIPS[0]);

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

const char* PINEAPPLE_SPRITE_FILE = "imgs\\pineapple.png";

const int PINEAPPLE_CLIPS[][4] = {
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

const int PINEAPPLE_FRAMES = sizeof(PINEAPPLE_CLIPS) / sizeof(int) / 4;


const char* LAZER_SPRITE_FILE = "imgs\\kunai.png";
const int LAZER_CLIPS[][4] = {
    {0, 0, 50, 16},
};
const int LAZER_FRAMES = sizeof(LAZER_CLIPS) / sizeof(LAZER_CLIPS[0]);





const char* LAYER1_FILE = "imgs/background/background1/1.png";
const char* LAYER2_FILE = "imgs/background/background1/2.png";
const char* LAYER3_FILE = "imgs/background/background1/3.png";
const char* LAYER4_FILE = "imgs/background/background1/4.png";
const char* LAYER5_FILE = "imgs/background/background1/5.png";
const char* LAYER6_FILE = "imgs/background/background1/6.png";
const char* LAYER7_FILE = "imgs/background/background1/7.png";
const char* LAYER8_FILE = "imgs/background/background1/8.png";
const char* LAYER9_FILE = "imgs/background/background1/9.png";
const char* LAYER10_FILE = "imgs/background/background1/10.png";
const char* LAYER11_FILE = "imgs/background/background1/11.png";
const char* LAYER12_FILE = "imgs/background/background1/12.png";
const char* LAYER13_FILE = "imgs/background/background1/13.png";



const double LAYER_1_SPEED = 0.0;
const double LAYER_2_SPEED = 0.25;
const double LAYER_3_SPEED = 0.5;
const double LAYER_4_SPEED = 0.75;
const double LAYER_5_SPEED = 1.0;
const double LAYER_6_SPEED = 1.25;
const double LAYER_7_SPEED = 1.5;
const double LAYER_8_SPEED = 1.75;
const double LAYER_9_SPEED = 2.0;
const double LAYER_10_SPEED = 2.25;
const double LAYER_11_SPEED = 2.5;
const double LAYER_12_SPEED = 2.75;
const double LAYER_13_SPEED = 3.0;

#define SPEED_INCREASEMENT 5
#define SCORE_INCREASEMENT 6
#define TIME_INCREASEMENT 1
#define FRAME_INCREASEMENT 1


const char* BATTERY_0 = "imgs/bullet/0.png";
const char* BATTERY_1 = "imgs/bullet/1.png";
const char* BATTERY_2 = "imgs/bullet/2.png";
const char* BATTERY_3 = "imgs/bullet/3.png";
const char* BATTERY_4 = "imgs/bullet/4.png";
const char* BATTERY_5 = "imgs/bullet/5.png";
const char* BATTERY_6 = "imgs/bullet/6.png";
const char* BATTERY_7 = "imgs/bullet/7.png";
const char* BATTERY_8 = "imgs/bullet/8.png";



#endif // DEFS_H_INCLUDED
