#include "Test.hpp"


Test::Test() {
    
}

Test::~Test() {
    
}

void Test::Init() {
    container = Container({200, 200, 50, 100}, {200, 100, 200, 255});
}

void Test::Update() {

    if(keymap[SDLK_ESCAPE])
        Quit();

    if(container.Hover(mousePos) && mouseButton[SDL_BUTTON_LEFT])
        std::cout << mousePos.x << ", " << mousePos.y << std::endl;

    renderer.Clear({255, 255, 255, 0});

    container.Draw(renderer.GetRenderer());

    renderer.Present();
}

void Test::Shutdown() {
    
}
