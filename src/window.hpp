#pragma once
#include <SDL2/SDL.h>

#include <GL/glew.h>
#include <string>
#include "object.hpp"

namespace Sandbox {
    /**
     * Static windowing class
    */
    class Window : public Object {
        private:
            SDL_Window* windowPtr = nullptr;

        public:
            bool destroyWindow = false;

            Window(int width, int height, std::string title);

            void HandleEvent(SDL_Event event) {
                if(event.type == SDL_QUIT)
                    destroyWindow = true;
            }

            void Init();
            void Update(float dt);
            void Render();
    };
}

