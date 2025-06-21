#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{

    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if(window == NULL)
    {

        std::cout << "WINDOW FAILED TO INITIALISE! : " << SDL_GetError() << std::endl;

    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}



SDL_Renderer* RenderWindow::getRenderer()
{
    return renderer;
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filepath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filepath);

    if (texture == NULL)
    {
        std :: cout << "Texture ERROR: " << SDL_GetError() << std::endl;
    }
   
    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

}
void RenderWindow::render(SDL_Texture* p_tex)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 100;
    src.h = 100;


    SDL_Rect dst;
    dst.x = 300;
    dst.y = 300;
    dst.w = 200;
    dst.h = 200;
    SDL_RenderCopy(renderer, p_tex, &src, &dst);
}
