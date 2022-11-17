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
			}
		}
        
        Update();
    }

    Shutdown();
}