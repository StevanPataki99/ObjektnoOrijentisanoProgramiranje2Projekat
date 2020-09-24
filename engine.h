#pragma once

#include <SDL.h>
#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include "eventlistener.h"
#include "drawable.h"
#include "movable.h"
#include "player.h"
#include "ball.h"


enum class GameState {
    START,
    RUNNING,
    FINISHED

};

class Engine {
public:
    Engine(std::string title);
    void run();
    virtual  ~Engine();

    void drawScore(int rezultat, SDL_Renderer* renderer);

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    int frameCap = 60;

    std::vector<EventListener*> eventListeners;
    std::vector<Drawable*> drawables;
    std::vector<Movable*> movables;
};

//void drawScore(int score, SDL_Renderer* renderer);