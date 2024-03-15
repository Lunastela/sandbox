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
            void HandleEvent(SDL_Event event) {
                if(event.type == SDL_QUIT)
                    destroyWindow = true;
            }

            void Update() {}
            void Draw() {
                glClearColor( float(rand())/RAND_MAX, float(rand())/RAND_MAX, float(rand())/RAND_MAX, 1.0f );
                glClear(GL_COLOR_BUFFER_BIT);
            }
    };
}

