#pragma once

#include <SDL.h>
#include "movable.h"
#include "drawable.h"
#include "sprite.h"

class Ball: public Movable, public Drawable {
public:
    Ball(Sprite *sprite);
    virtual void draw(SDL_Renderer *renderer);
    virtual void move();
    virtual void move(int dx, int dy);

    virtual int goalCollide();
    virtual void positionReset(int x, int y);

private:
    Sprite *sprite;
};
