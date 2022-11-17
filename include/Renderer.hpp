#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_log.h>
#include <string>
#include <array>

#include "Surface.hpp"

class Renderer
{
private:
    SDL_Renderer* renderer;
    SDL_Window* window;

    void Init();
    void Window(std::string p_title, int p_w, int p_h, uint32_t p_flags);
    void RendererInit();
public:
    Renderer();
    Renderer(std::string title, int width, int height);
    Renderer(std::string title, int width, int height, uint32_t flags);
    ~Renderer();

    void Clear(SDL_Color color);
    void Present();

    inline SDL_Renderer* GetRenderer() { return renderer; };
};