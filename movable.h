#pragma once

#include <SDL.h>

class Movable {
public:
    virtual void move() = 0;
    virtual void move(int dx, int dy) = 0;
};