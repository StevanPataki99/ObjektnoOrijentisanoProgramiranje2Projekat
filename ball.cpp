#include "ball.h"
#include <iostream>

Ball::Ball(Sprite *sprite) : Drawable(), Movable() {
    this->sprite = sprite;
}


void Ball::draw(SDL_Renderer *renderer) {
    sprite->draw(renderer);
}

void Ball::move() {
    sprite->move();
}

void Ball::move(int dx, int dy) {
    sprite->move(dx, dy);
}

int Ball::goalCollide() {
    if (sprite->getSpriteX() <= -15) {
        this->positionReset(650, sprite->getSpriteY());
        return 1;
    }
    return 0;
}

void Ball::positionReset(int x, int y) {
    int newY = rand() % (480 - y);
    sprite->setSpriteY(newY);
    sprite->setSpriteX(x);
}
