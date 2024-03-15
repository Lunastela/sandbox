#include <iostream>
#define SDL_MAIN_HANDLED
#include "window.cpp"

using namespace Sandbox;

void Window::Init() {};
void Window::Update(float dt) {};
void Window::Render() {
    glClearColor( 0.0f, 0.25f, 0.0f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT);
    
    SDL_GL_SwapWindow(windowPtr);
};

int main(int argv, char** argc) {
    std::cout << "hello worldx";
    Window window {1280, 720, "Hello World™"};
    // return 0;
}
