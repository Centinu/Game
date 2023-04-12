#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <string>
#include "Core.hpp"
#include "LTexture.hpp"
#include "Config.hpp"
class SpaceShip
{
 public:

    static const int SHIP_WIDTH = 5;
    static const int SHIP_HEIGHT = 5;

    static const int SHIP_VEL = 10;

    SpaceShip(std::string path);
    ~SpaceShip();
    void handleEvent( SDL_Event& e );

    void move();

    void render();

    int getXPos();
    int getYPos();
private:
    
    int mPosX, mPosY;

    int mVelX, mVelY;

    LTexture shipTex;
};

#endif // SPACESHIP_H
