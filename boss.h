#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED

#include "defs.h"
#include <cstdlib>
#include <ctime>

#define BOSS_POSITION_RANGE 250

struct Boss {
    int posX;
    int posY;
    int BOSS_WIDTH;
    int BOSS_HEIGHT;
    int hitCounter;
    bool isDie;

    Boss() {
        posX = rand() % (SCREEN_WIDTH + BOSS_POSITION_RANGE) + SCREEN_WIDTH;
        posY = GROUND - 8;
        BOSS_WIDTH = 0;
        BOSS_HEIGHT = 0;
        hitCounter = 0;
        isDie = false;
        //BossTexture = nullptr; // Uncomment and initialize if using textures
    }

    void Move(const int &acceleration) {
        posX += -(BOSS_SPEED + acceleration);
        if (posX + MAX_ENEMY_WIDTH < 0) {
            posX = rand() % (SCREEN_WIDTH + BOSS_POSITION_RANGE) + SCREEN_WIDTH;
        }
    }

    int GetSpeed(const int &acceleration) const {
        return BOSS_SPEED + acceleration;
    }

    int GetPosX() const {
        return posX;
    }

    int GetPosY() const {
        return posY;
    }

    int GetWidth() const {
        return BOSS_WIDTH;
    }

    int GetHeight() const {
        return BOSS_HEIGHT;
    }

    void Hit() {
        if (!isDie) {
            hitCounter++;
            if (hitCounter >= 3) {
                isDie = true;
            }
        }
    }
    void SetDie(bool die) {
        isDie = die;
    }
    bool IsDie(){
        return isDie;
    }

    void Reset() {
        isDie = false;
        hitCounter = 0;
        posX = rand() % (SCREEN_WIDTH + BOSS_POSITION_RANGE) + SCREEN_WIDTH;
        posY = GROUND - 8;
    }
};

#endif // BOSS_H_INCLUDED
