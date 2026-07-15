#pragma once

#include "UIComponents.h"
#include "UIRenderer.h"

#define WINDOW_TITLE  "Hello, SDL3!"
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 640

class Game {
    private:
        UIComponents m_uc;
        UIRenderer m_ur;

    public:
        Game();
        void run();
};