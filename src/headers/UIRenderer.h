#pragma once

#include <SDL3/SDL_render.h>
#include "UIComponents.h"
#include "Tamagotchi.h"

#define WINDOW_TITLE  "Hello, SDL3!"
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 640

class UIRenderer {
    private:
        SDL_Texture m_idleImage;

        void drawButton(SDL_Renderer *r, const Button& b);
        void drawTamagotchi(SDL_Renderer *r, const Tamagotchi& t);

    public:
        UIRenderer();
        void clean(SDL_Renderer *r);
        void render(SDL_Renderer *r, const UIComponents &uc, const Tamagotchi &t);

        SDL_Texture idleImage() const;
};