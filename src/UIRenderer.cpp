#include <SDL3/SDL_render.h>
#include "UIRenderer.h"

UIRenderer::UIRenderer() { }

void UIRenderer::clean(SDL_Renderer *r) {
    SDL_SetRenderDrawColor(r, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(r);
}

void UIRenderer::render(SDL_Renderer *r, const UIComponents& uc, const Tamagotchi& t) {
    drawTamagotchi(r, t);

    const std::vector<Button>& buttons = uc.buttons();
    for (const Button& current : buttons) {
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
    SDL_RenderDebugText(
        r,
        b.x() + b.w() / 4, b.y() + b.h() / 2,
        b.title().c_str()
    );
}

void UIRenderer::drawTamagotchi(SDL_Renderer *r, const Tamagotchi& t) {
    SDL_SetRenderDrawColor(r, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDebugTextFormat(
        r,
        0, 0,
        "Hunger: %d", t.hunger()
    );
    SDL_RenderDebugTextFormat(
        r,
        0, 10,
        "Sleep: %d", t.sleep()
    );
    SDL_RenderDebugTextFormat(
        r,
        WINDOW_WIDTH / 2, 0,
        "Current State: %d", t.state()
    );
}