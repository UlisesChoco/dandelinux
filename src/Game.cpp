#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include "Game.h"

Game::Game()
    : m_uc(
        std::vector<Button> {
            Button(
                "Feed!",
                0.0f, 25.0f,
                100, 50,
                [this]() { m_t.feed(); }
            ),
            Button(
                "Rest!",
                0.0f, 75,
                100, 50,
                [this]() { m_t.sleep(); }
            )
        }
      ),
      m_ur(),
      m_t(Tamagotchi()) { }

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

    Uint64 timeElapsed = 1;
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

        switch (m_t.state()) {
            case TamagotchiState::IDLE: {
                std::cout << "Idling!\n";
                break;
            }
            case TamagotchiState::RESTING: {
                std::cout << "Resting!\n";
                break;
            }
        }

        Uint64 currentTimeInSeconds = SDL_GetTicks() / 1000.0f;
        //debugging purposes ! ! ! ! 0-0
        //std::cout << "currentTimeInSeconds = " << currentTimeInSeconds << "\n";
        //std::cout << "timeElapsed = " << timeElapsed << "\n";

        if (currentTimeInSeconds >= timeElapsed) {
            m_t.updateState();
            timeElapsed++;
        }
        
        m_ur.clean(renderer);
        m_ur.render(renderer, m_uc, m_t);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}