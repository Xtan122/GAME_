#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <SDL_image.h>
#include "defs.h"
#include "grp.h"
#include "enemy.h"
#include "logic.h"
#include <iostream>

#define JUMP 1
#define FALL 2
#define RUN 0


struct Character
{
    static const int JUMP_SPEED = 15;
    static const int FALL_SPEED = 15;
    static const int MOVE_SPEED = 5;

    int posX;
    int posY;
    int status;

    SDL_Texture* texture;
    SDL_Rect* rect;
    Character()
    {
        posX = SCREEN_WIDTH - 700;
        posY = GROUND;
        status = 0;

        texture = nullptr;

    }
//    Character(int posX, int posY) {
//        rect.x = posX;
//        rect.y = posY;
//        rect.h = 32;
//        rect.w = 32;
//    }

    bool OnGround()
    {
        return posY == GROUND;
    }

   void HandleEvent(SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        switch (e.key.keysym.scancode)
        {
            case SDL_SCANCODE_SPACE :
            {
                if (OnGround())
                {
                    status = JUMP;
                }

            }

        }
    }
}


    void Jump()
    {
        if (status == JUMP && posY >= MAX_HEIGHT)
        {
            posY -= JUMP_SPEED;
        }
        if (posY <= MAX_HEIGHT)
        {
            status = FALL;
        }
        if (status == FALL && posY < GROUND)
        {
            posY += FALL_SPEED;
        }
    }
    void MoveRight()
    {
        if(status == RUN) posX += MOVE_SPEED;
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

bool CheckCollision(Character& character, SDL_Rect& char_clip, Enemy& enemy, SDL_Rect& enemy_clip)
{
    bool collide = false;

    int left_a = character.GetPosX();
    int right_a = character.GetPosX() + char_clip.w;
    int top_a = character.GetPosY();
    int bottom_a = character.GetPosY() + char_clip.h;

    if (enemy.GetType() == ON_GROUND_ENEMY)
    {
        const int TRASH_PIXEL_1 = 25;
        const int TRASH_PIXEL_2 = 30;

        int left_b = enemy.GetPosX();
        int right_b = enemy.GetPosX() + enemy.GetWidth();
        int top_b = enemy.GetPosY();
        int bottom_b = enemy.GetPosY() + enemy.GetHeight();

        if (right_a - TRASH_PIXEL_1 >= left_b && left_a + TRASH_PIXEL_1 <= right_b)
        {
            if (bottom_a - TRASH_PIXEL_2 >= top_b)
            {
                collide = true;
            }
        }
    }
    else
    {
        const int TRASH_PIXEL_1 = 22;
        const int TRASH_PIXEL_2 = 18;

        int left_b = enemy.GetPosX() + TRASH_PIXEL_1;
        int right_b = enemy.GetPosX() + enemy_clip.w - TRASH_PIXEL_1;
        int top_b = enemy.GetPosY();
        int bottom_b = enemy.GetPosY() + enemy_clip.h - TRASH_PIXEL_2;

        if (right_a >= left_b && left_a <= right_b)
        {
            if (top_a <= bottom_b && top_a >= top_b)
            {
                collide = true;
            }

            if (bottom_a >= bottom_b && bottom_a <= top_b)
            {
                collide = true;
            }
        }
    }

    return collide;
}

#endif // CHARACTER_H_INCLUDED
