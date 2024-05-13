#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "defs.h"
#include "grp.h"

struct Button {
    int posX, posY;
    int bWIDTH, bHEIGHT;

    Button(){
        posX = 0;
        posY = 0;
        bWIDTH = 0;
        bHEIGHT = 0;
    }

    bool IsInside(int x, int y) const {
        return (x >= posX && x <= posX + bWIDTH && y >= posY && y <= posY + bHEIGHT);
    }
};

#endif // BUTTON_H_INCLUDED
