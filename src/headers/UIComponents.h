#pragma once

#include <vector>
#include <SDL3/SDL_events.h>
#include "Button.h"

class UIComponents {
    private:
        std::vector<Button> m_buttons;

    public:
        UIComponents(const std::vector<Button>& buttons);
        void fireEvents(SDL_Event *e);
        const std::vector<Button>& buttons() const;
};