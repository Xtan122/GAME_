#ifndef FRUIT_H_INCLUDED
#define FRUIT_H_INCLUDED

#include "defs.h"

#include <cstdlib>
#include <ctime>

#define FRUIT_MAX_HEIGHT 300
#define FRUIT_MIN_HEIGHT 330
#define FRUIT_POSITION_RANGE 250

struct Fruit{
    int posX;
    int posY;
    int F_WIDTH;
    int F_HEIGHT;
    int type;
    bool isEaten;

    Fruit(int _type = 0) {
        posX = 0;
        posY = 0;
        F_WIDTH = 0;
        F_HEIGHT = 0;
        type = _type;
        isEaten = false;
        if (type == IN_AIR_FRUIT) {
            posX = rand() % (SCREEN_WIDTH + FRUIT_POSITION_RANGE) + SCREEN_WIDTH;
            posY = rand() % (FRUIT_MAX_HEIGHT - FRUIT_MIN_HEIGHT + 1) + FRUIT_MIN_HEIGHT;
        } else if (type == ON_GROUND_FRUIT) {
            posX = rand() % (SCREEN_WIDTH + FRUIT_POSITION_RANGE) + SCREEN_WIDTH;
            posY = GROUND - 8;
        }

    }
    void Move(const int &acceleration) {
        posX += -(FRUIT_SPEED + acceleration);
        if (posX + MAX_FRUIT_WIDTH < 0) {
            posX = rand() % (SCREEN_WIDTH + FRUIT_POSITION_RANGE) + SCREEN_WIDTH;
            if (type == IN_AIR_FRUIT) {
                    posY = rand() % (FRUIT_MAX_HEIGHT - FRUIT_MIN_HEIGHT + 1) + FRUIT_MIN_HEIGHT;
            }
        }
    }

    int GetSpeed(const int &acceleration) {
        return FRUIT_SPEED + acceleration;
    }

    int GetPosX() {
        return posX;
    }

    int GetPosY() {
        return posY;
    }

    int GetWidth() {
        return F_WIDTH;
    }

    int GetHeight() {
        return F_HEIGHT;
    }
    void SetEaten(bool eaten) {
        isEaten = eaten;
    }
    bool IsEaten() {
        return isEaten;
    }
};


#endif // FRUIT_H_INCLUDED
