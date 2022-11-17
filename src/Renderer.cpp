#include "Renderer.hpp"


void Renderer::RendererInit() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

Renderer::Renderer() {
    Init();
    Window("Application", 800, 600, 0);
    RendererInit();
}

Renderer::Renderer(std::string title, int width, int height) {
    Init();
    Window(title, width, height, 0);
    RendererInit();
}

Renderer::Renderer(std::string title, int width, int height, uint32_t flags) {
    Init();
    Window(title, width, height, flags);
    RendererInit();
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    SDL_Quit();
}

void Renderer::Init() {
    int init = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    if(init != 0) {
        SDL_Log("Unable to init SDL: %s", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
}

void Renderer::Window(std::string p_title, int p_w, int p_h, uint32_t p_flags) {
    window = SDL_CreateWindow(p_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, p_flags);
    if(window == NULL) {
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_Quit();
        exit(2);
    }
}


void Renderer::Clear(SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_RenderClear(renderer);
}

void Renderer::Present() {
    SDL_RenderPresent(renderer);
}