#include <iostream>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include "Game.h"

Game::Game()
    : m_uc(
        std::vector<Button> {
            Button(
                WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,
                100, 100,
                []() { std::cout<<"Clicked 1st button!\n"; }
            ),
            Button(
                125 + WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,
                100, 100,
                []() { std::cout<<"Clicked 2nd button!\n"; }
            )
        }
      ),
      m_ur() { }

void Game::run() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        std::cout << "SDL_Init failed!\n";
        exit(1);
    }

    SDL_Window   *window;
    SDL_Renderer *renderer;

    if (!SDL_CreateWindowAndRenderer(
        WINDOW_TITLE,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_RESIZABLE,
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
                if (event.key.key == SDLK_ESCAPE) {
                    running = false;
                }
            }
            m_uc.fireEvents(&event);
        }
        
        m_ur.clean(renderer);
        m_ur.render(renderer, m_uc);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}