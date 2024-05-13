#ifndef CHEST_H_INCLUDED
#define CHEST_H_INCLUDED

#include "defs.h"

#include <cstdlib>
#include <ctime>

#define CHEST_MAX_HEIGHT 300
#define CHEST_MIN_HEIGHT 330
#define CHEST_POSITION_RANGE 250
#define CHEST1_RANGE 100
#define CHEST2_RANGE 250
#define CHEST3_RANGE 500

struct Chest{
    int posX;
    int posY;
    int C_WIDTH;
    int C_HEIGHT;
    bool isOpen; // set trung dan

    Chest() {
        posX = 0;
        posY = 0;
        C_WIDTH = 0;
        C_HEIGHT = 0;

        isOpen = false;
        posX = rand() % (SCREEN_WIDTH + CHEST_POSITION_RANGE) + SCREEN_WIDTH;
        posY = GROUND - 8;

    }
    void Move(const int &acceleration) {
        posX += -(CHEST_SPEED + acceleration); //Cập nhật vị trí theo hướng ngược lại của tốc độ di chuyển của hòm.
        if (posX + MAX_CHEST_WIDTH < 0) {
            posX = rand() % (SCREEN_WIDTH + CHEST_POSITION_RANGE) + SCREEN_WIDTH; //đảm bảo hòm xuất hiện bên phải màn hình ngoài màn hình

        }
    }


    int GetSpeed(const int &acceleration) {
        return CHEST_SPEED + acceleration;
    }

    int GetPosX() {
        return posX;
    }

    int GetPosY() {
        return posY;
    }
    int GetWidth(){
        return C_WIDTH;
    }
    int GetHeight(){
        return C_HEIGHT;
    }
    void SetOpen(bool open) {
        isOpen = open;
    }
    bool IsOpen(){
        return isOpen;
    }
};

#endif // CHEST_H_INCLUDED
