#include <iostream>
#include <SDL.h>
#include <string>
#include "engine.h"

int main() {
    Engine *engine = new Engine("Pong");
    engine->run();
    delete engine;
    return 0;
}
