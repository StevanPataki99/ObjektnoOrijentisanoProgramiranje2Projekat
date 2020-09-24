#pragma once

#include <vector>
#include "ball.h"
#include "player.h"
#include "sprite.h"

class ObjectGroup {
public:
    ObjectGroup();
    int objectCollider(Sprite *plyerSprite, Sprite *ballSprite);
};

