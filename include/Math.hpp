#pragma once

#include <SDL2/SDL.h>

struct vec2i
{
    int x, y;

    inline vec2i() { this->x = 0; this->y = 0; } 
    inline vec2i(int x, int y) { this->x = x; this->y = y; } 
};

bool PointRectCollision(vec2i& point, SDL_Rect& rect);

