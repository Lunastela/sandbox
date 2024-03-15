#include "window.hpp"
#include <iostream>

namespace Sandbox {
    Window::Window(int width, int height, std::string title) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) 
            return;

        windowPtr = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
        SDL_GLContext context = SDL_GL_CreateContext(windowPtr);

        // SDL Settings
        // SDL_SetRelativeMouseMode(SDL_TRUE);
        SDL_GL_SetSwapInterval(1);

        // Initialize GLEW
        glewExperimental = GL_TRUE; // Enable GLEW experimental features
        glewInit();

        glEnable(GL_MULTISAMPLE);
        glCullFace(GL_BACK);
        glEnable(GL_DEPTH_TEST);

        this->Init();
        uint64_t ticks = SDL_GetTicks64();
        while (!destroyWindow) {
            SDL_Event event;
            while (SDL_PollEvent(&event))
                this->HandleEvent(event);
            this->Update((float)(ticks - SDL_GetTicks64() / 1000));
            ticks = SDL_GetTicks64();
            this->Render();
        }

        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(windowPtr);
        SDL_Quit();
    };
}