#include "UIComponents.h"

UIComponents::UIComponents(const std::vector<Button>& buttons)
    : m_buttons(std::move(buttons)) { }

void UIComponents::fireEvents(SDL_Event *e) {
    for (int i = 0 ; i < m_buttons.size() ; i++) {
        Button& current = m_buttons[i];

        if (e->type == SDL_EVENT_MOUSE_BUTTON_UP) {
            float mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            switch (e->button.button) {
                case SDL_BUTTON_LEFT:
                    current.onMouseClick(mouseX, mouseY);
                    break;
            }
        }
    }
}

const std::vector<Button>& UIComponents::buttons() const { return m_buttons; }
