//
// Created by Stevan Pataki on 9/5/20.
//

#include <iostream>
#include "player.h"

Player::Player(Sprite *sprite) : Drawable(), Movable(), KeyboardEventListener() {
    this->sprite = sprite;
}

void Player::draw(SDL_Renderer *renderer) {
    sprite->draw(renderer);
}

void Player::move() {
    sprite->move();
}

void Player::move(int dx, int dy) {
    sprite->move(dx, dy);
}

void Player::listen(SDL_KeyboardEvent &event) {
    if (event.type == SDL_KEYDOWN) {
        if (event.keysym.sym == upKey) {
            sprite->setState(Sprite::UP);
        } else if (event.keysym.sym == downKey) {
            sprite->setState(Sprite::DOWN);
        }
    } else if (event.type == SDL_KEYUP) {
        sprite->setState(Sprite::STOP);
    }
//    if (event.type == SDL_KEYDOWN && event.keysym.sym == SDLK_UP) {
//        sprite->setState(Sprite::UP);
//
//        std::cout << "Moving" << std::endl;
//    } else if (event.type == SDL_KEYUP && event.keysym.sym == SDLK_UP) {
//        sprite->setState(Sprite::STOP);
//        std::cout << "Stop moving" << std::endl;
//    }
}

void Player::setKeys(SDL_Keycode up, SDL_Keycode down) {
    this->upKey = up;
    this->downKey = down;
}

void Player::frameCollide() {
    if (sprite->getSpriteY() >= 420) {
        sprite->setSpriteY(419);
    } else if (sprite->getSpriteY() <= 0) {
        sprite->setSpriteY(1);
    }
}