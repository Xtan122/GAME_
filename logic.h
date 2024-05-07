#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED


#include "character.h"
#include "enemy.h"

bool checkCollision(SDL_Rect rect1, const SDL_Rect rect2)
{
    // Kiểm tra xem hai hình chữ nhật có giao nhau không

    if (rect1.x + rect1.w >= rect2.x   && rect2.x + rect2.w >= rect1.x &&
        rect1.y + rect1.h >= rect2.y && rect2.y + rect2.h >= rect1.y)
    {
        return true; // Có va chạm
    }
    return false; // Không có va chạm
}



//
//bool checkCollision(SDL_Rect* rect1, SDL_Rect* rect2)
//{
//    // Kiểm tra xem hai hình chữ nhật có giao nhau không
//
//
//    if (rect1->x + rect1->w >= rect2->x && rect2->x + rect2->w >= rect1->x &&
//        rect1->y + rect1->h >= rect2->y && rect2->y + rect2->h >= rect1->y)
//    {
//        return true; // Có va chạm
//    }
//    return false; // Không có va chạm
//}

#endif // LOGIC_H_INCLUDED
