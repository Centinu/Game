#include "Core.hpp"

using namespace std;
Core* game = new Core;


int main(int argc, char* argv[])
{
    game->init();
    game->loadMedia();

    while(game->isRunning)
    {
        game->handleEvent();
        game->update();
        game->render();
    }

    game->close();
    return 0;
}






