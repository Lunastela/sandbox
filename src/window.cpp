#include "window.hpp"
#include <iostream>
#include <cmath>

namespace Sandbox {
    Window::Window(int width, int height, std::string title) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) 
            return;

        windowPtr = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
        SDL_GLContext context = SDL_GL_CreateContext(windowPtr);

        // Initialize GLEW
        glewExperimental = GL_TRUE; // Enable GLEW experimental features
        glewInit();

        Init();
        while (!destroyWindow) {
            SDL_Event event;
            while (SDL_PollEvent(&event))
                HandleEvent(event);
            Update();
            Draw();
        }

        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(windowPtr);
        SDL_Quit();
    };
}