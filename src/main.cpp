#include <iostream>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

#define WINDOW_TITLE  "Hello, SDL3!"
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 640

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "SDL_Init failed!\n";
        exit(1);
    }

    SDL_Window   *window;
    SDL_Renderer *renderer;

    if (!SDL_CreateWindowAndRenderer(
        WINDOW_TITLE,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        0,
        &window, &renderer
    )) {
        std::cout << "SDL_CreateWindowAndRenderer failed!\n";
        exit(1);
    }

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_KEY_DOWN) {
                switch (event.key.key) {
                    case SDLK_ESCAPE: running = false; break;
                }
            }
        }

        SDL_SetRenderDrawColor(
            renderer,
            0, 0, 0, SDL_ALPHA_OPAQUE
        );
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}