#include "engine.h"
#include "objectgroup.h"


Engine::Engine(std::string title) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Engine::run() {
    int maxDelay = 1000 / 60;
    int frameStart = 0;
    int frameEnd = 0;
    bool running = true;
    SDL_Event event;

    std::ifstream spriteSheetStream("../resources/creatures/sprite_sheet.txt");
    SpriteSheet *spriteSheet = new SpriteSheet(spriteSheetStream, renderer);
    Sprite *sprite = new Sprite(spriteSheet, 64, 64);
    sprite->setFrameSkip(4);
    Player *player1 = new Player(sprite);
    player1->setKeys(SDLK_w, SDLK_s);
    drawables.push_back(player1);
    movables.push_back(player1);
    eventListeners.push_back(player1);

    std::ifstream spriteSheetStreamBall("../resources/creatures/sprite_sheet_ball.txt");
    SpriteSheet *spriteSheetBall = new SpriteSheet(spriteSheetStreamBall, renderer);
    Sprite *spriteBall = new Sprite(spriteSheetBall, 16, 16);
    spriteBall->setState(Sprite::BALL);
    spriteBall->setFrameSkip(1);
    Ball *ball = new Ball(spriteBall);
    drawables.push_back(ball);
    movables.push_back(ball);

    ObjectGroup *objgorup;

    ball->move(630,rand() % 470);

    int score = 0;

//    std::cout << "Dosao do ovde" << std::endl;

    while (running) {
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else {
                for (size_t i = 0; i < eventListeners.size(); i++) {
                    eventListeners[i]->listen(event);
                }
            }
        }

        for (int i = 0; i < movables.size(); ++i) {
            movables[i]->move();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        drawScore(score, renderer);
//
//        int playerx = sprite->getSpriteX();
//        int playery = sprite->getSpriteY();
//
//        int ballx = spriteBall->getSpriteX();
//        int bally = spriteBall->getSpriteY();
//
//        for(int i = 0; i< sprite->getSpriteH(); i++){
//            for(int j = 0; j< spriteBall->getSpriteH(); j++){
//                if ((playerx + i) == (ballx + j) && (playery + i) == (bally + j)){
//                    ball->positionReset(650, spriteBall->getSpriteY());
//                    score++;
//                    std::cout << score << std::endl;
//                }
//            }
//        }

        int scoreRez = objgorup->objectCollider(sprite, spriteBall);

        if (scoreRez == 1) {
            score++;
            spriteBall->setSpeed(spriteBall->getSpeed() - 1);

            std::cout << "SCORE: " << score << std::endl;

            int speedDisplay =  abs(spriteBall->getSpeed());

            std::cout << "NEW SPEED: " << speedDisplay << std::endl;
            ball->positionReset(650, spriteBall->getSpriteY());

        }



        int failRez = ball->goalCollide();
        if (failRez == 1) {
            score = 0;
            spriteBall->setSpeed(-1);

            std::cout << "SCORE: " << score << std::endl;

            int speedDisplay =  abs(spriteBall->getSpeed());

            std::cout << "NEW SPEED: " << speedDisplay << std::endl;
            ball->positionReset(650, spriteBall->getSpriteY());
        }

        player1->frameCollide();


        for (int i = 0; i < drawables.size(); ++i) {
            drawables[i]->draw(renderer);
        }


        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if (frameEnd - frameStart < maxDelay) {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Engine::drawScore(int score, SDL_Renderer* renderer){
    TTF_Font* font = TTF_OpenFont("font/comicbd.ttf", 12);
    SDL_Color white = {255, 255, 255};
    std::stringstream sStream;
    sStream << "SCORE: " << score;
    SDL_Surface* msg_surface = TTF_RenderText_Solid(font, sStream.str().c_str(), white);
    SDL_Texture* msg = SDL_CreateTextureFromSurface(renderer, msg_surface);
    SDL_Rect msg_box;
    msg_box.x = 100;
    msg_box.y = 100;
    msg_box.w = 100;
    msg_box.h = 50;
    SDL_RenderCopy(renderer, msg, NULL, &msg_box);
}





