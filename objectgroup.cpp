#include "objectgroup.h"

ObjectGroup::ObjectGroup() {}


int ObjectGroup::objectCollider(Sprite *playerSprite, Sprite *ballSprite) {
    int xPlayer = playerSprite->getSpriteX();
    int xBall = ballSprite->getSpriteX();
    int yPlayer = playerSprite->getSpriteY();
    int yBall = ballSprite->getSpriteY();

    int x = xPlayer -xBall;
    int y = yPlayer - yBall;
    int distance = sqrt(x*x + y*y);

    if (distance < 32+16){
        return 1;
    } else {
        return 0;
    }
}
