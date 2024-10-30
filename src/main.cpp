#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

#define HEIGHT 720
#define WIDTH 1280

bool init();
void kill();
bool loop();
bool process_event(bool *drawing, int *x1, int *y1, int *x2, int *y2);

SDL_Surface *winSurface = NULL;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;
SDL_Surface *surface;
SDL_Texture *texture;
// You must include the command line parameters for your main function to be
// recognized by SDL
int main(int argc, char *args[]) {
    int rc = 0;

    // Initialize SDL. SDL_Init will return -1 if it fails.
    if (!init()) {
        printf("init failed\n");
        return 1;
    }

    surface = SDL_LoadBMP("../src/1280-720-sample.bmp");
    if (!surface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create surface from image: %s", SDL_GetError());
        return 3;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create texture from surface: %s",
                     SDL_GetError());
        return 3;
    }
    SDL_DestroySurface(surface);

    if (!loop()) {
        std::cout << "Loop exited with error" << SDL_GetError() << std::endl;
    }

    // Destroy the window. This will also destroy the surface
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    // Quit SDL
    SDL_Quit();

    // End the program
    return 0;
}

bool loop() {
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    bool drawing = false;

    while (1) {
        SDL_Delay(10);

        if (process_event(&drawing, &x1, &y1, &x2, &y2))
            return true;

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        if (drawing)
            SDL_RenderLine(renderer, x1, y1, x2, y2);
        SDL_RenderPresent(renderer);
    }
    return true;
}

bool init() {

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        // End the program
        return false;
    }

    // Create our window
    if (!SDL_CreateWindowAndRenderer("Hello SDL!", WIDTH, HEIGHT, 0, &window,
                                     &renderer)) {
        std::cout << "Error initializing Renderer and Window: "
                  << SDL_GetError() << std::endl;
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

bool process_event(bool *drawing, int *x1, int *y1, int *x2, int *y2) {
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_EVENT_QUIT:
        break;
    case SDL_EVENT_KEY_DOWN:
        if (event.key.key == SDLK_RETURN)
            return true;
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
        switch (event.button.button) {
        case SDL_BUTTON_LEFT:
            *drawing = true;
            *x1 = event.motion.x;
            *y1 = event.motion.y;
            *x2 = event.motion.x;
            *y2 = event.motion.y;
            break;
        }
        break;
    case SDL_EVENT_MOUSE_MOTION:
        if (*drawing) {
            *x2 = event.motion.x;
            *y2 = event.motion.y;
        }
        break;
    case SDL_EVENT_MOUSE_BUTTON_UP:
        *drawing = false;
        break;
    }
    return false;
}
