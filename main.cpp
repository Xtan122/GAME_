#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <algorithm>
#include <fstream>



#include "defs.h"
#include "grp.h"
#include "character.h"
#include "enemy.h"
#include "logic.h"
#include "menu.h"
#include "fruit.h"
#include "bullet.h"
#include "chest.h"
#include "button.h"



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
void saveHighscore(int highscore) {
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        file << highscore;
        file.close();
    }
}

int loadHighscore() {
    int highscore = 0;
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highscore;
        file.close();
    }
    return highscore;
}



int main(int argc, char *argv[])
{
    srand(time(NULL));
    int time = 0;
    int score = 0;
    int highscore = loadHighscore();
    int acceleration = 0;
    int energy = 0;

    Graphics graphics;
    graphics.init();
    Mix_Music *gMusic = graphics.loadMusic("asset\\nen.mp3");
    graphics.play(gMusic);
    Mix_Chunk *gJump = graphics.loadSound("asset\\jump.mp3");
    Mix_Chunk *gDead = graphics.loadSound("asset\\death.wav");
    Mix_Chunk *gShoot = graphics.loadSound("asset\\bandan.mp3");
    Mix_Chunk *gEat = graphics.loadSound("asset\\eat.mp3");


    ScrollingGround ground; ground.setTexture(graphics.loadTexture("imgs/ground.png"));
    ScrollingBackground layer1, layer2, layer3, layer4, layer5, layer6, layer7, layer8;
    layer1.setTexture(graphics.loadTexture(LAYER1_FILE));
    layer2.setTexture(graphics.loadTexture(LAYER2_FILE));
    layer3.setTexture(graphics.loadTexture(LAYER3_FILE));
    layer4.setTexture(graphics.loadTexture(LAYER4_FILE));
    layer5.setTexture(graphics.loadTexture(LAYER5_FILE));
    layer6.setTexture(graphics.loadTexture(LAYER6_FILE));
    layer7.setTexture(graphics.loadTexture(LAYER7_FILE));
    layer8.setTexture(graphics.loadTexture(LAYER8_FILE));

    SDL_Texture* battery0 = graphics.loadTexture(BATTERY_0);
    SDL_Texture* battery1 = graphics.loadTexture(BATTERY_1);
    SDL_Texture* battery2 = graphics.loadTexture(BATTERY_2);
    SDL_Texture* battery3 = graphics.loadTexture(BATTERY_3);
    SDL_Texture* battery4 = graphics.loadTexture(BATTERY_4);
    SDL_Texture* battery5 = graphics.loadTexture(BATTERY_5);
    SDL_Texture* battery6 = graphics.loadTexture(BATTERY_6);

    Character character;
    Sprite frog;
    SDL_Texture* frogTexture = graphics.loadTexture(FROG_SPRITE_FILE);
    frog.init(frogTexture, FROG_FRAMES, FROG_CLIPS);

    Bullet bullet;

    Sprite lazer;
    SDL_Texture* lazerTexture = graphics.loadTexture(LAZER_SPRITE_FILE);
    lazer.init(lazerTexture, LAZER_FRAMES, LAZER_CLIPS);

    Enemy enemy1(ON_GROUND_ENEMY);
    Enemy enemy2(IN_AIR_ENEMY);
    Enemy enemy3(ON_GROUND_ENEMY);
    Enemy enemy4(ON_GROUND_ENEMY);


    Sprite chameleon;
    SDL_Texture* chameleonTexture = graphics.loadTexture(CHAMELEON_SPRITE_FILE);
    chameleon.init(chameleonTexture, CHAMELEON_FRAMES, CHAMELEON_CLIPS);

    Sprite bat;
    SDL_Texture* batTexture = graphics.loadTexture(BAT_SPRITE_FILE);
    bat.init(batTexture, BAT_FRAMES, BAT_CLIPS);

    Sprite slime;
    SDL_Texture* slimeTexture = graphics.loadTexture(SLIME_SPRITE_FILE);
    slime.init(slimeTexture, SLIME_FRAMES, SLIME_CLIPS);

    Sprite bunny;
    SDL_Texture* bunnyTexture = graphics.loadTexture(BUNNY_SPRITE_FILE);
    bunny.init(bunnyTexture, BUNNY_FRAMES, BUNNY_CLIPS);

    Fruit fruit1(IN_AIR_FRUIT);
    Fruit fruit2(ON_GROUND_FRUIT);

    Sprite banana;
    SDL_Texture* bananaTexture = graphics.loadTexture(BANANA_SPRITE_FILE);
    banana.init(bananaTexture, BANANA_FRAMES, BANANA_CLIPS);

    Sprite pineapple;
    SDL_Texture* pineappleTexture = graphics.loadTexture(PINEAPPLE_SPRITE_FILE);
    pineapple.init(pineappleTexture, PINEAPPLE_FRAMES, PINEAPPLE_CLIPS);

    Chest chest;
    Sprite box;
    SDL_Texture* boxTexture = graphics.loadTexture(BOX_SPRITE_FILE);
    box.init(boxTexture, BOX_FRAMES, BOX_CLIPS);


    TTF_Font* font = graphics.loadFont("asset/Roboto-Black.ttf", 26);
    SDL_Color color = {255, 255, 0, 0};
    SDL_Texture* scoreText = graphics.renderText(to_string(score).c_str(), font, color);
    SDL_Texture* SCOREText = graphics.renderText("SCORE", font, color);

    SDL_Texture* energyText = graphics.renderText(to_string(bullet.currentBullets).c_str(), font, color);
    SDL_Texture* highscoreText = graphics.renderText(to_string(score).c_str(), font, color);
    SDL_Texture* HightscoreText = graphics.renderText("HIGHSCORE", font, color);



    bool quit = false;
    bool gameOver = false;
    bool isEaten = false;
    //bool delay = false;
    int Game_State = 0;
    bool die = false;

    SDL_Texture* menuTexture = graphics.loadTexture(MENU_TEXTURE_FILE);
    SDL_Texture* endTexture = graphics.loadTexture(END_TEXTURE_FILE);
//    Button startButton;
//    Button volumnButton;
//
//    SDL_Texture* startTexture = graphics.loadTexture("imgs/menu/start.png");
//    SDL_Texture* volumnOnTexture = graphics.loadTexture("imgs/menu/volumn_on.png");
//    SDL_Texture* volumnOffTexture = graphics.loadTexture("imgs/menu/volumn_off.png");

    SDL_Event event;
    while (!quit) {

        if (Game_State == 0) {
            graphics.prepareScene(menuTexture);
            //graphics.renderTexture(startTexture, 200, 200);

            SDL_Event e;
            while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_SPACE) {
                    Game_State = 1;
                    break;
                } else if (e.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                }
            }
        }

        graphics.presentScene();
        }

        else if (Game_State == 1 && !die) {
            int staticks = SDL_GetTicks64();
            int fps  = 30;
            UpdateGameTimeAndScore(time, acceleration, score);
            while (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_QUIT){
                    quit = true;
                }
                character.HandleEvent(event);
                bullet.HandleEvent(event, character);
                const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
                if (currentKeyStates[SDL_SCANCODE_SPACE]) graphics.play(gJump);
                if (currentKeyStates[SDL_SCANCODE_RIGHT] && bullet.currentBullets > 0) graphics.play(gShoot);
            }
            //graphics.prepareScene();

            frog.tick(); lazer.tick();
            chameleon.tick(); bat.tick(); slime.tick(); bunny.tick();
            banana.tick(); pineapple.tick();
            box.tick();

            layer1.scroll(LAYER_1_SPEED); graphics.render(layer1);
            layer2.scroll(LAYER_2_SPEED); graphics.render(layer2);
            layer3.scroll(LAYER_3_SPEED); graphics.render(layer3);
            layer4.scroll(LAYER_4_SPEED); graphics.render(layer4);
            layer5.scroll(LAYER_5_SPEED); graphics.render(layer5);
            layer6.scroll(LAYER_6_SPEED); graphics.render(layer6);
            layer7.scroll(LAYER_7_SPEED); graphics.render(layer7);
            layer8.scroll(LAYER_8_SPEED); graphics.render(layer8);


            ground.scroll(10);
            graphics.render(ground);

            SDL_Rect* character_rect = frog.getCurrentClip();
            SDL_Rect characterRect = {character.GetPosX(), character.GetPosY(), character_rect->w, character_rect->h};

            SDL_Rect* enemy1_rect = chameleon.getCurrentClip();
            SDL_Rect enemy1Rect = {enemy1.GetPosX() + 60, enemy1.GetPosY() + 10, enemy1_rect->w - 80, enemy1_rect->h };

            SDL_Rect* enemy2_rect = bat.getCurrentClip();
            SDL_Rect enemy2Rect = {enemy2.GetPosX() + 20, enemy2.GetPosY() - 20, enemy2_rect->w - 20, enemy2_rect->h - 8};

            SDL_Rect* enemy3_rect = slime.getCurrentClip();
            SDL_Rect enemy3Rect = {enemy3.GetPosX() + 30, enemy3.GetPosY() + 15, enemy3_rect->w - 50, enemy3_rect->h + 15};

            SDL_Rect* enemy4_rect = bunny.getCurrentClip();
            SDL_Rect enemy4Rect = {enemy4.GetPosX(), enemy4.GetPosY() + 10, enemy4_rect->w , enemy4_rect->h };

            SDL_Rect* fruit1_rect = banana.getCurrentClip();
            SDL_Rect fruit1Rect = {fruit1.GetPosX(), fruit1.GetPosY() - 20, fruit1_rect->w - 6, fruit1_rect->h - 8};

            SDL_Rect* fruit2_rect = pineapple.getCurrentClip();
            SDL_Rect fruit2Rect = {fruit2.GetPosX() , fruit2.GetPosY(), fruit2_rect->w, fruit2_rect->h};


            SDL_Rect* chest_rect = box.getCurrentClip();
            SDL_Rect chestRect = {chest.GetPosX() + 30, chest.GetPosY() + 15, chest_rect->w - 50, chest_rect->h + 15};


            character.Jump();
            graphics.render(character.posX, character.posY, frog);
            if(score >= 50)  { enemy1.Move(acceleration + 2); graphics.render(enemy1.posX, enemy1.posY, chameleon);}
            if(score >= 300) { enemy2.Move(acceleration + 4); graphics.render(enemy2.posX, enemy2.posY, bat);}
            if(score >= 1000){ enemy3.Move(acceleration);     graphics.render(enemy3.posX, enemy3.posY + 10, slime);} // đẩy chân slime cho chạm đất
            if(score >= 1500){ enemy4.Move(acceleration + 6); graphics.render(enemy4.posX, enemy4.posY, bunny);}



            if (fruit1.IsEaten()) { fruit1 = Fruit(IN_AIR_FRUIT);    fruit1.SetEaten(false);}
            if (fruit2.IsEaten()) { fruit2 = Fruit(ON_GROUND_FRUIT); fruit2.SetEaten(false);}
            if(score >= 700) { fruit1.Move(0); graphics.render(fruit1.posX, fruit1.posY, banana);}
            if(score >= 1200){ fruit2.Move(0); graphics.render(fruit2.posX, fruit2.posY + 8, pineapple);}

            if(chest.IsOpen()) {
                chest = Chest();
                chest.SetOpen(false);
            }
            if(enemy1.IsDie()){ enemy1 = Enemy(ON_GROUND_ENEMY); enemy1.SetDie(false);}
            if(enemy2.IsDie()){ enemy2 = Enemy(IN_AIR_ENEMY);    enemy2.SetDie(false);}
            if(enemy3.IsDie()){ enemy3 = Enemy(ON_GROUND_ENEMY); enemy3.SetDie(false);}
            if(enemy4.IsDie()){ enemy4 = Enemy(ON_GROUND_ENEMY); enemy4.SetDie(false);}


            for (auto& bullet : bullet.bullets){
                    if(bullet.IsHit()){ bullet.SetHit(false);}
            }
            bullet.Move();
            for (auto& bullet : bullet.bullets) { graphics.render(bullet.posX, bullet.posY, lazer);} // Vẽ đạn

            //if(score >= 0){ chest.Move(acceleration);      graphics.render(chest.posX, chest.posY + 10, box);}
            if(checkCollision(characterRect, enemy1Rect) || checkCollision(characterRect, enemy2Rect) || checkCollision(characterRect, enemy3Rect) || checkCollision(characterRect, enemy4Rect)){
                graphics.play(gDead);
                die = true;
                Game_State = 2;
                //delay = true;

            }
//            if(delay){
//                SDL_Delay(10000);
//            }

            if (checkCollision(characterRect, fruit1Rect)) {
                graphics.play(gEat);
                fruit1.SetEaten(true);
                energy ++;
                bullet.IncreaseBullets();

            }
            switch(bullet.currentBullets){
                    case 0: graphics.renderTexture(battery0, 20, 20); break;
                    case 1: graphics.renderTexture(battery1, 20, 20); break;
                    case 2: graphics.renderTexture(battery2, 20, 20); break;
                    case 3: graphics.renderTexture(battery3, 20, 20); break;
                    case 4: graphics.renderTexture(battery4, 20, 20); break;
                    case 5: graphics.renderTexture(battery5, 20, 20); break;
                    case 6: graphics.renderTexture(battery6, 20, 20); break;
                    default: break;
                }
            if (checkCollision(characterRect, fruit2Rect)) {
                graphics.play(gEat);
                fruit2.SetEaten(true);
                if(acceleration >= 3){ acceleration--;}
            }

            for (auto& bullet : bullet.bullets) {
                SDL_Rect* bullet_rect = lazer.getCurrentClip();
                SDL_Rect bulletRect = {bullet.GetPosX(), bullet.GetPosY(), bullet_rect->w , bullet_rect->h};
                if(checkCollision(enemy1Rect, bulletRect)){ enemy1.SetDie(true); bullet.SetHit(true);}
                if(checkCollision(enemy2Rect, bulletRect)){ enemy2.SetDie(true); bullet.SetHit(true);}
                if(checkCollision(enemy3Rect, bulletRect)){ enemy3.SetDie(true); bullet.SetHit(true);}
                if(checkCollision(enemy4Rect, bulletRect)){ enemy4.SetDie(true); bullet.SetHit(true);}
            }

            bullet.bullets.erase(std::remove_if(bullet.bullets.begin(), bullet.bullets.end(), [](Bullet& b) { return b.IsHit(); }), bullet.bullets.end());
            if (score > highscore) { highscore = score; saveHighscore(highscore);}
            updateScoreText(graphics, font, score, color, scoreText);
            graphics.renderTexture(scoreText, 890, 20);

            updateScoreText(graphics, font, highscore, color, scoreText);
            graphics.renderTexture(scoreText, 890, 60);

            updateScoreText(graphics, font, bullet.currentBullets, color, scoreText);
            graphics.renderTexture(scoreText, 20, 20);

            graphics.presentScene();
            int frame_stick = SDL_GetTicks64() - staticks;
            if(frame_stick < 1000/fps){
                SDL_Delay(1000/fps - frame_stick);
            }
        }
        else if (Game_State == 2) {
            graphics.prepareScene(endTexture);
            SDL_Event end_event;
            while (SDL_PollEvent(&end_event) != 0) {
                if (end_event.type == SDL_KEYDOWN) {
                    if (end_event.key.keysym.sym == SDLK_SPACE) {
                        score = 0;
                        acceleration = 0;
                        character.Reset();

                        enemy1.Reset();
                        enemy2.Reset();
                        enemy3.Reset();
                        enemy4.Reset();
                        bullet.Reset();
                        die = false;
                        Game_State = 1;

                        break;
                    } else if (end_event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                    }
                }
            }
        graphics.presentScene();
    }

}




    SDL_DestroyTexture( ground.texture    );
    SDL_DestroyTexture( character.texture );
    SDL_DestroyTexture( frogTexture       ); frogTexture = nullptr;
    SDL_DestroyTexture( chameleonTexture  ); chameleonTexture = nullptr;
    SDL_DestroyTexture( batTexture        ); batTexture = nullptr;
    SDL_DestroyTexture( slimeTexture      ); slimeTexture = nullptr;
    SDL_DestroyTexture( bunnyTexture      ); bunnyTexture = nullptr;
    SDL_DestroyTexture( bananaTexture     ); bananaTexture = nullptr;
    SDL_DestroyTexture( pineappleTexture  ); pineappleTexture = nullptr;

    graphics.quit();
    return 0;
}
