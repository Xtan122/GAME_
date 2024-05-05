#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "grp.h"
#include "character.h"
#include "enemy.h"
#include "logic.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}


Character character;

int main(int argc, char *argv[])
{
    int acceleration = 0;

    Graphics graphics;
    graphics.init();



    ScrollingBackground ground;
    ground.setTexture(graphics.loadTexture("imgs/ground.png"));
    //character.texture = graphics.loadTexture("imgs/human64x91.png");

    Sprite frog;
    SDL_Texture* frogTexture = graphics.loadTexture(FROG_SPRITE_FILE);
    frog.init(frogTexture, FROG_FRAMES, FROG_CLIPS);

    Enemy enemy1(ON_GROUND_ENEMY);
    Enemy enemy2(IN_AIR_ENEMY);

    Sprite chameleon;
    SDL_Texture* chameleonTexture = graphics.loadTexture(CHAMELEON_SPRITE_FILE);
    chameleon.init(chameleonTexture, CHAMELEON_FRAMES, CHAMELEON_CLIPS);

    Sprite bat;
    SDL_Texture* batTexture = graphics.loadTexture(BAT_SPRITE_FILE);
    bat.init(batTexture, BAT_FRAMES, BAT_CLIPS);

    SDL_Rect* character_rect;
    SDL_Rect* enemy1_rect;

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        int staticks = SDL_GetTicks64();
        int fps  = 30;
         while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT){
                    quit = true;
            }
            character.HandleEvent(event);// Xử lý sự kiện bàn phím cho nhân vật

         }
         graphics.prepareScene();

         frog.tick();
         chameleon.tick();
         bat.tick();

         ground.scroll(10);

         character.Move();
         enemy1.Move(acceleration);
         enemy2.Move(acceleration);
         character_rect = frog.getCurrentClip();
         enemy1_rect = chameleon.getCurrentClip();



         graphics.render(ground);
         graphics.render(character.posX, character.posY, frog);
         graphics.render(enemy1.posX, enemy1.posY, chameleon);
         graphics.render(enemy2.posX, enemy2.posY, bat);


        if(CheckColission(character, character_rect, enemy1, enemy1_rect)){
           cout << "end";
        }


        graphics.presentScene();

        int frame_stick = SDL_GetTicks64() - staticks;
        if(frame_stick < 1000/fps){
            SDL_Delay(1000/fps - frame_stick);
        }

    }
    //graphics.presentScene();
    //waitUntilKeyPressed();
    SDL_DestroyTexture( ground.texture );
    SDL_DestroyTexture(character.texture);
    SDL_DestroyTexture( frogTexture ); frogTexture = nullptr;

    graphics.quit();
    return 0;
}
