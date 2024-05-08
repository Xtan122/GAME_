#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "defs.h"
#include "character.h"

#define BULLET_SPEED 20
struct Bullet {
    int posX, posY;
    int B_SPEED;
    int B_WIDTH;
    int B_HEIGHT;
    bool isMove;
    bool isHit;
    int B_NUMBER;

    std::vector<Bullet> bullets;
    Bullet() {
        posX = SCREEN_WIDTH - 700;
        posY = GROUND;
        B_SPEED = 10;
        B_WIDTH = 0;
        B_HEIGHT = 0;
        isMove = false;
        isHit = false;
        B_NUMBER = 5;
    }

    Bullet(int x, int y, int speed, int width, int height) {
        posX = x;
        posY = y;
        B_SPEED = speed;
        B_WIDTH = width;
        B_HEIGHT = height;
        isMove = false;
        isHit = false;

    }

    void HandleEvent(SDL_Event& e, Character& character) {
        if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
            switch (e.key.keysym.scancode) {
                case SDL_SCANCODE_RIGHT:
                    if ( B_NUMBER > 0) {
                        B_NUMBER--;
                        bullets.push_back(Bullet(character.posX, character.posY, B_SPEED, B_WIDTH, B_HEIGHT));
                    }
                    break;
            }
        }
    }
    void IncreaseBullets() {
         B_NUMBER++;
    }

    void Move() {
        for (auto& bullet : bullets) {
            bullet.posX += bullet.B_SPEED;
        }
    }
    void SetHit(bool hit) {
        isHit = hit;
    }
    bool IsHit() {
        return isHit;
    }
    int GetPosX()
    {
        return posX;
    }

    int GetPosY()
    {
        return posY;
    }
};

#endif // BULLET_H_INCLUDED
