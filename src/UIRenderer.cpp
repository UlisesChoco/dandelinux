#include <SDL3/SDL_render.h>
#include "UIRenderer.h"

UIRenderer::UIRenderer() { }

void UIRenderer::clean(SDL_Renderer *r) {
    SDL_SetRenderDrawColor(r, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(r);
}

void UIRenderer::render(SDL_Renderer *r, const UIComponents& uc) {
    const std::vector<Button>& buttons = uc.buttons();
    int buttons_quantity = buttons.size();
    for (int i = 0 ; i < buttons_quantity ; i++) {
        const Button& current = buttons[i];
        drawButton(r, current);
    }
    SDL_RenderPresent(r);
}

void UIRenderer::drawButton(SDL_Renderer *r, const Button& b) {
    SDL_SetRenderDrawColor(r, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_FRect rect = {
        .x = b.x(),
        .y = b.y(),
        .w = b.w(),
        .h = b.h()
    };
    SDL_RenderRect(r, &rect);
}