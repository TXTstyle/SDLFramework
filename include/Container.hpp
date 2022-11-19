#pragma once

#include "Surface.hpp"
#include "Math.hpp"

class Container: public Surface
{
private:
    void Init(SDL_Rect rect, SDL_Color color);
    SDL_Color baseColor;
public:
    Container();
    Container(SDL_Rect rect, SDL_Color color);
    Container(int x, int y, int width, int height, SDL_Color color);
    Container(int x, int y, int width, int height, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    ~Container();

    bool Hover(vec2i& pos);
    virtual void Draw(SDL_Renderer* renderer) override;
};

/*
    int x, y;
    int w, h;
*/

/*
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
*/