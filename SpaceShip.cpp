#include "SpaceShip.hpp"

SpaceShip::SpaceShip(std::string path)
{
    mPosX = SCREEN_WIDTH/2-40;
    mPosY = SCREEN_HEIGHT/2-60;

    mVelX = 0;
    mVelY = 0;

    shipTex.loadFromFile(path);
}

SpaceShip::~SpaceShip()
{
    shipTex.free();
}

void SpaceShip::handleEvent(SDL_Event &e)
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: case SDLK_w: mVelY -= SHIP_VEL; break;
            case SDLK_DOWN: case SDLK_s: mVelY += SHIP_VEL; break;
            case SDLK_LEFT: case SDLK_a: mVelX -= SHIP_VEL; break;
            case SDLK_RIGHT: case SDLK_d: mVelX += SHIP_VEL; break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: case SDLK_w: mVelY += SHIP_VEL; break;
            case SDLK_DOWN: case SDLK_s: mVelY -= SHIP_VEL; break;
            case SDLK_LEFT: case SDLK_a: mVelX += SHIP_VEL; break;
            case SDLK_RIGHT: case SDLK_d: mVelX -= SHIP_VEL; break;
        }
    }
}

void SpaceShip::move()
{
    mPosX += mVelX;

    if( ( mPosX < 0 ) || ( mPosX + shipTex.getWidth() > SCREEN_WIDTH ) )
    {
        mPosX -= mVelX;
    }
    mPosY += mVelY;
    
    if( ( mPosY < 0 ) || ( mPosY + shipTex.getHeight() > SCREEN_HEIGHT ) )
    {
        mPosY -= mVelY;
    }
}

void SpaceShip::render()
{
    SDL_Rect srcRect = {0,0,shipTex.getWidth(), shipTex.getHeight()};
    SDL_Rect destRect = {mPosX, mPosY, srcRect.w, srcRect.h};
    SDL_RenderCopy(Core::gRenderer, shipTex.getTexture(), &srcRect, &destRect);
}

int SpaceShip::getXPos()
{
    return mPosX;
}
int SpaceShip::getYPos()
{
    return mPosY;
}

