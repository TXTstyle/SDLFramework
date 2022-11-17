#pragma once

#include <SDL2/SDL.h>

class Surface
{
protected:
    SDL_Rect rect;
    SDL_Color color;
public:
    Surface() {}
    virtual void Draw(SDL_Renderer* renderer) = 0;
};