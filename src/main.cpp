#include <iostream>
#include "window.cpp"

using namespace Sandbox;

void Window::Init() {};
void Window::Update(float dt) {};
void Window::Render() {
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT);
    
    SDL_GL_SwapWindow(windowPtr);
};

int main(int, char**) {
    Window window {1280, 720, "Hello World™"};
}
