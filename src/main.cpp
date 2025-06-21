#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.h"
#include "Entity.h"

int main(int argc, char* args[])
{
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std :: cout << "SDL INITIALISATION FAILED!: " << SDL_GetError() << std::endl;
    }
    if(!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG INITIALISATION FAILED!: " << SDL_GetError() << std::endl;
    }

    RenderWindow window("SICI", 600, 600);
    
    SDL_Texture* testGround = window.loadTexture("res/gfx/TestGroundTile.png");

    Entity platform0(30, 30, testGround);

    bool gamerunning = true;

    SDL_Event event;

    while (gamerunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gamerunning = false;
            }
        }
        
        window.clear();
        window.render(platform0);
        window.display();
    }


    window.cleanUp();
    SDL_Quit();



    return 0;

}