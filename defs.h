#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

const int SCREEN_WIDTH = 928;
const int SCREEN_HEIGHT = 522;
const char* WINDOW_TITLE = "Jump";

#define GROUND 450
#define MAX_HEIGHT 250

#define IN_AIR_ENEMY 1
#define ON_GROUND_ENEMY 0

#define GROUND_SPEED 5
#define ENEMY_SPEED 10
#define MAX_ENEMY_WIDTH 100

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

#endif // DEFS_H_INCLUDED
