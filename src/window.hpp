#pragma once

#include <SDL2/SDL.h>

#include <GL/glew.h>
#include <string>

namespace Sandbox {
    class Window {
        private:
            SDL_Window* windowPtr = nullptr;

        public:
            bool destroyWindow = false;

            Window(int width, int height, std::string title);

            void Init();
            void HandleEvent(SDL_Event event) {
                if(event.type == SDL_QUIT)
                    destroyWindow = true;
            }
            void Update();
            void Draw();
    };
}

