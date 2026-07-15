#pragma once

#include <SDL3/SDL_render.h>
#include "UIComponents.h"

class UIRenderer {
    private:
        void drawButton(SDL_Renderer *r, const Button& b);

    public:
        UIRenderer();
        void clean(SDL_Renderer *r);
        void render(SDL_Renderer *r, const UIComponents &uc);
};