#include "App.hpp"

App::App() {

}

App::~App() {
    
}

void App::Run() {
    Init();

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;

			case SDL_KEYDOWN:
                keymap[event.key.keysym.sym] = true;
				break;
            case SDL_KEYUP:
                keymap[event.key.keysym.sym] = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                mouseButton[event.button.button] = true;
                break;
            
            case SDL_MOUSEBUTTONUP:
                mouseButton[event.button.button] = false;
                break;

            case SDL_MOUSEMOTION:
                mousePos = {event.button.x, event.button.y};
                break;
			}
		}
        
        Update();
    }

    Shutdown();
}