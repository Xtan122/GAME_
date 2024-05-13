#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "defs.h"
#include "character.h"

#define BULLET_SPEED 50
#define MAX_BULLETS 6

struct Bullet {
    int posX, posY;
    int B_SPEED;
    int B_WIDTH;
    int B_HEIGHT;
    bool isMove;
    bool isHit;
    int currentBullets;

    std::vector<Bullet> bullets;

    Bullet() {
        posX = SCREEN_WIDTH - 700;
        posY = GROUND;
        B_SPEED = 20;
        B_WIDTH = 0;
        B_HEIGHT = 0;
        isMove = false;
        isHit = false;
        currentBullets = 6;
    }

    Bullet(int x, int y, int speed, int width, int height) {
        posX = x;
        posY = y;
        B_SPEED = speed;
        B_WIDTH = width;
        B_HEIGHT = height;
        isMove = false;
        isHit = false;
        currentBullets = 0;
    }

    void HandleEvent(SDL_Event& e, Character& character) {
        if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
            switch (e.key.keysym.sym) {
                case SDLK_RIGHT:
                    if (currentBullets > 0 && currentBullets <= MAX_BULLETS) {
                        currentBullets--;
                        bullets.push_back(Bullet(character.posX, character.posY + 8, B_SPEED, B_WIDTH, B_HEIGHT));
                    }
                    break;
            }
        }
    }

    void IncreaseBullets() {
        if (currentBullets < MAX_BULLETS) {
            currentBullets++;
        }
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

    int GetPosX() {
        return posX;
    }

    int GetPosY() {
        return posY;
    }
    void Reset() {
        currentBullets = 6;
        bullets.clear();
    }
};

#endif // BULLET_H_INCLUDED
