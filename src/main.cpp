#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

#define HEIGHT 720
#define WIDTH 1270

bool init();
void kill();
bool loop();

SDL_Surface *winSurface = NULL;
SDL_Window *window = NULL;
// You must include the command line parameters for your main function to be
// recognized by SDL
int main(int argc, char **args) {
    int rc = 0;

    // Initialize SDL. SDL_Init will return -1 if it fails.
    if (!init()) {
        printf("init failed\n");
        return 1;
    }

    // Fill the window with a white rectangle
    SDL_FillSurfaceRect(
        winSurface, NULL,
        SDL_MapRGB(SDL_GetPixelFormatDetails(winSurface->format), NULL, 255, 0,
                   0));

    // Update the window display
    SDL_UpdateWindowSurface(window);

    // Wait
    getchar();

    // Destroy the window. This will also destroy the surface
    SDL_DestroyWindow(window);

    // Quit SDL
    SDL_Quit();

    // End the program
    return 0;
}

bool loop() { return true; }

bool init() {

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        // End the program
        return false;
    }

    // Create our window
    window = SDL_CreateWindow("Example", WIDTH, HEIGHT, 0);

    // Make sure creating the window succeeded
    if (!window) {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        // End the program
        return false;
    }

    // Get the surface from the window
    winSurface = SDL_GetWindowSurface(window);

    // Make sure getting the surface succeeded
    if (!winSurface) {
        std::cout << "Error getting surface: " << SDL_GetError() << std::endl;
        // End the program
        return false;
    }
    return true;
}
