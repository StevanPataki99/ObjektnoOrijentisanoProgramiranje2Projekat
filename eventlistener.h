#pragma once

#include <SDL.h>

class EventListener {
public:
    virtual void listen(SDL_Event &event) = 0;
};