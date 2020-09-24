//
// Created by Stevan Pataki on 9/5/20.
//

#include "spritesheet.h"

SpriteSheet::SpriteSheet(std::istream &inputStream, SDL_Renderer *renderer) {
    std::string path;
    std::string animation;
    int totalFrames;
    inputStream >> path;

    SDL_Surface *surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    while (!inputStream.eof()) {
        inputStream >> animation;
        animations[animation] = Frames();

        inputStream >> totalFrames;
        for (int i = 0; i < totalFrames; i++) {
            auto *frame = new Frame();
            inputStream >> frame->x >> frame->y >> frame->w >> frame->h;
            animations[animation].push_back(frame);
        }
    }
}

void SpriteSheet::drawFrame(std::string animation, int frame, SDL_Rect *dest, SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, texture, animations[animation][frame], dest);
}
