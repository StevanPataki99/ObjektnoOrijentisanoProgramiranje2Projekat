#pragma once

#include <SDL.h>
#include "movable.h"
#include "drawable.h"
#include "keyboardeventlistener.h"
#include "sprite.h"

class Player: public Drawable, public Movable, public KeyboardEventListener {
public:
    Player(Sprite *sprite);
    virtual void draw(SDL_Renderer *renderer);
    virtual void move();
    virtual void move(int dx, int dy);
    virtual void listen(SDL_KeyboardEvent &event);
    virtual void frameCollide();

    void setKeys(SDL_Keycode up, SDL_Keycode down);
private:
    Sprite *sprite;

    SDL_Keycode upKey = SDL_KeyCode::SDLK_UP;
    SDL_Keycode downKey = SDL_KeyCode::SDLK_DOWN;
};
