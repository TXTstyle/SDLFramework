#pragma once

#include <map>
#include <iostream>
#include "Renderer.hpp"
#include "Math.hpp"

class App
{
protected:
    Renderer renderer;
    bool isRunning = true;
    SDL_Event event;
    std::map<int, bool> keymap;
    std::map<int, bool> mouseButton;
    vec2i mousePos;

    inline void Quit() { isRunning = false; };
public:
    App();
    ~App();

    void Run();

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Shutdown() = 0;
};