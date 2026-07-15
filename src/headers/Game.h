#pragma once

#include "Tamagotchi.h"
#include "UIComponents.h"
#include "UIRenderer.h"

class Game {
    private:
        Tamagotchi m_t;
        UIComponents m_uc;
        UIRenderer m_ur;

    public:
        Game();
        void run();
};