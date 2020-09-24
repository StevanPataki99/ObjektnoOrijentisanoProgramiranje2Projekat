#pragma once

#include <SDL.h>

#include "eventlistener.h"

class KeyboardEventListener : public EventListener {
    virtual void listen(SDL_Event &event);
    virtual void listen(SDL_KeyboardEvent &event) = 0;
};
