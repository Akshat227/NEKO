#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Entity.h"

class RenderWindow
{
public:
        RenderWindow(const char *p_title, int p_w, int p_h);
        void cleanUp();
        SDL_Renderer *getRenderer();
        SDL_Texture *loadTexture(const char *p_filepath);
        void clear();
        void display();
        void render(Entity &p_entity);

private:
        SDL_Window *window;
        SDL_Renderer *renderer;
};