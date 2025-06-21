#pragma once
 
class Entity
{
    public:
        Entity(double p_x, double p_y, SDL_Texture* p_tex);

    private:
        double x, y;
        SDL_Rect currentFrame;
        SDL_Texture* tex;
};