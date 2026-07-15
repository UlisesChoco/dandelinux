#pragma once

enum class TamagotchiState {
    IDLE,
    RESTING
};

class Tamagotchi {
    private:
        int m_hunger;
        int m_sleep;
        TamagotchiState m_state;

    public:
        Tamagotchi();
        void feed();
        void sleep();
        void updateState();

        int hunger() const;
        int sleep() const;
        TamagotchiState state() const;
};