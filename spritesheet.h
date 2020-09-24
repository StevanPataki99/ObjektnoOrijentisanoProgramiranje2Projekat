#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>
#include <vector>
#include <istream>

typedef SDL_Rect Frame;
typedef std::vector<Frame *> Frames;

class SpriteSheet {
public:
    SpriteSheet(std::istream &inputSteram, SDL_Renderer *renderer);
    void drawFrame(std::string animation, int frame, Frame *dest, SDL_Renderer *renderer);

private:
    SDL_Texture *texture;
    std::map<std::string, std::vector<SDL_Rect*>> animations;
};
