#include "Fire.hpp"

Fire::Fire()
{
    fireTex.loadFromFile("/Users/raiju/Downloads/Galaxy-Glide-main 2/Picture/fire.png");
    int r=rand()%3;
            if (r == 0) {
           xPos = rand() % 1200;
           yPos = -50;
       } else if (r == 1) {
           xPos = -50;
           yPos = rand() % 800;
       } else {
           xPos = 1280 + 50;
           yPos = rand() % 720;
       }
           double u = Core::player-> getXPos() - xPos;
           double v = Core::player-> getYPos() - yPos;
           double t = std::max(abs(u),abs(v));

           velocityX= double(u)/t * 5;
           velocityY= double(v)/t * 5;
           destRect.x=xPos;
           destRect.y=yPos;
}

Fire::~Fire()
{
    fireTex.free();
}

void Fire::Update()
{
    xPos += 2* velocityX;
    yPos += 2* velocityY;
    srcRect = {0,0,50,50};
    destRect = {(int)xPos, (int) yPos, 50,50};
}
void Fire::Render()
{
    SDL_RenderCopy(Core::gRenderer, fireTex.getTexture(), &srcRect, &destRect);
}
