#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "defs.h"

#include <cstdlib>
#include <ctime>

#define ENEMY_MAX_HEIGHT 300
#define ENEMY_MIN_HEIGHT 330
#define ENEMY_POSITION_RANGE 250


struct Enemy{
    int posX;
    int posY;
    int E_WIDTH;
    int E_HEIGHT;
    int type;
    SDL_Rect* rect;

    bool isDie;

    Enemy(int _type = 0) {
        posX = 0;
        posY = 0;
        E_WIDTH = 0;
        E_HEIGHT = 0;
        type = _type;
        isDie = false;
        srand(time(NULL));
        if (type == IN_AIR_ENEMY) {

            posX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;
            posY = rand() % (ENEMY_MAX_HEIGHT - ENEMY_MIN_HEIGHT + 1) + ENEMY_MIN_HEIGHT;
        } else if (type == ON_GROUND_ENEMY) {
            posX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;
            posY = GROUND - 8;
        }

    }
    void Move(const int &acceleration) {
        posX += -(ENEMY_SPEED + acceleration);
        if (posX + MAX_ENEMY_WIDTH < 0) {
            posX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;
            if (type == IN_AIR_ENEMY) {
                posY = rand() % (ENEMY_MAX_HEIGHT - ENEMY_MIN_HEIGHT + 1) + ENEMY_MIN_HEIGHT;
            }
        }
    }

    int GetType() {
        if (type == IN_AIR_ENEMY) {
            return IN_AIR_ENEMY;
        } else {
            return ON_GROUND_ENEMY;
        }
    }

    int GetSpeed(const int &acceleration) {
        return ENEMY_SPEED + acceleration;
    }

    int GetPosX() {
        return posX;
    }

    int GetPosY() {
        return posY;
    }
    int GetWidth(){
        return E_WIDTH;
    }
    int GetHeight(){
        return E_HEIGHT;
    }
    void SetDie(bool die) {
        isDie = die;
    }
    bool IsDie() {
        return isDie;
    }

    void Reset() {
        isDie = false;
        if (type == IN_AIR_ENEMY) {
            posX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;
            posY = rand() % (ENEMY_MAX_HEIGHT - ENEMY_MIN_HEIGHT + 1) + ENEMY_MIN_HEIGHT;
        } else if (type == ON_GROUND_ENEMY) {
            posX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;
            posY = GROUND - 8;
        }
    }
};

#endif // ENEMY_H_INCLUDED
