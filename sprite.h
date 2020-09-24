#pragma once

#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "drawable.h"
#include "movable.h"

#include "spritesheet.h"

class Sprite: public Drawable, public Movable {
public:
    Sprite(SpriteSheet *spriteSheet, int width, int height);
    int getFrameSkip() const;
    void setFrameSkip(int frameSkip);
    short int getState();
    void setState(short int state);

    void draw(SDL_Renderer *renderer);
    void move();
    void move(int dx, int dy);

    int getSpriteH() {return spriteRect->h;}
    int getSpriteW() {return spriteRect->w;}
    int getSpriteY() {return spriteRect->y;}
    int getSpriteX() {return spriteRect->x;}
    int getSpeed() {return speed;}

    void setSpeed(int newSpeed) { speed = newSpeed;}
    void setSpriteY(int y) { spriteRect->y = y;}
    void setSpriteX(int x) { spriteRect->x = x;}

    enum State { STOP, UP, DOWN, BALL };

private:
    int speed = -1;
    short int state;
    SDL_Rect *spriteRect;
    SpriteSheet *sheet;
    int currentFrame;
    int frameCounter;
    int frameSkip;
};