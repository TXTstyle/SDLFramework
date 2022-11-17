#include "Container.hpp"


void Container::Init(SDL_Rect rect, SDL_Color color) {
    this->rect = rect;
    this->color = color;
}

Container::Container() {
    
}

Container::Container(SDL_Rect rect, SDL_Color color) {
    Init(rect, color);
}

Container::Container(int x, int y, int width, int height, SDL_Color color) {
    Init({x, y, width, height}, color);
}

Container::Container(int x, int y, int width, int height, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    Init({x, y, width, height}, {r, g, b, a});
}

Container::~Container() {
    
}

void Container::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}
