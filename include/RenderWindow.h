#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


class RenderWindow
{
public:

        RenderWindow(const char* p_title, int p_w, int p_h);
        void cleanUp();
        SDL_Renderer* getRenderer();
        void clear();                
        void display();
private:
        SDL_Window* window;
        SDL_Renderer* renderer;



};