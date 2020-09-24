#include <iostream>
#include "sprite.h"

Sprite::Sprite(SpriteSheet *spriteSheet, int width, int height) {
    state = State::STOP;
    sheet = spriteSheet;
    currentFrame = 0;
    frameCounter = 0;
    frameSkip = 1;

    spriteRect = new SDL_Rect();
    spriteRect->x = 0;
    spriteRect->y = 0;
    spriteRect->w = width;
    spriteRect->h = height;
}

int Sprite::getFrameSkip() const {
    return frameSkip;
}

void Sprite::setFrameSkip(int frameSkip) {
    this->frameSkip = frameSkip;
}

short int Sprite::getState() {
    return state;
}

void Sprite::setState(short state) {
    this->state = state;
}

void Sprite::draw(SDL_Renderer *renderer) {
    if (state == State::UP) {
        sheet->drawFrame("walk_up", currentFrame, spriteRect, renderer);
    } else if (state == State::DOWN) {
        sheet->drawFrame("walk_down", currentFrame, spriteRect, renderer);
    } else if (state == State::STOP) {
        sheet->drawFrame("walk_up", 0, spriteRect, renderer);
    } else if (state == State::BALL) {
//        std::cout << "USAO" << std::endl;
        sheet->drawFrame("ball", 0, spriteRect, renderer);
    }


    frameCounter++;
    if (frameCounter % frameSkip == 0) {
        currentFrame++;
        if (currentFrame >= 9) {
            currentFrame = 0;
        }
        frameCounter = 0;
    }
}

void Sprite::move() {
    if (state == State::STOP) return;

    if (state == State::UP) {
        move(0, -5);
    } else if (state == State::DOWN) {
        move(0, 5);
    } else if (state == State::BALL) {
        move(speed, 0);
    }


}

void Sprite::move(int dx, int dy) {
    spriteRect->x += dx;
    spriteRect->y += dy;
}



