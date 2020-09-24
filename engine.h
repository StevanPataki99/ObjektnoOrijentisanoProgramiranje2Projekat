#pragma once

#include <SDL.h>
#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
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

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    int frameCap = 60;

    std::vector<EventListener*> eventListeners;
    std::vector<Drawable*> drawables;
    std::vector<Movable*> movables;
};