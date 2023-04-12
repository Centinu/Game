#ifndef CORE_H
#define CORE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <vector>

using namespace std;

class SpaceShip;
class Fire;

class Core
{
public:
    Core();
    ~Core();
    void init();
    void loadMedia();
    void handleEvent();
    void update();
    void render();
    void close();

    static SDL_Renderer* gRenderer;
    static SDL_Window* gWindow;
    static SDL_Event e;
    static TTF_Font* gFont;
    static Mix_Music* Music;

    static SpaceShip* player;
    static vector<Fire*> fires;
    bool isRunning = true;
private:
    void RandomObjectOutsideScreen(int _random);
    void normalize_vector(float &a, float &b);
};

#endif // CORE_H
