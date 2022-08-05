#pragma once
#include "GameLoop.h"

int main(int argc, char const *argv[])
{
    GameLoop* game = new GameLoop();
    game->Start();

        return 0;
}
