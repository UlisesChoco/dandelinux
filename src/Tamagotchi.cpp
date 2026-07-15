#include "Tamagotchi.h"

Tamagotchi::Tamagotchi() : m_hunger {10}, m_sleep {10}, m_state {TamagotchiState::IDLE} { }

void Tamagotchi::feed() {
    m_hunger += 1;
    m_state = TamagotchiState::IDLE;
}

void Tamagotchi::sleep() {
    if (m_state == TamagotchiState::RESTING) return;

    m_sleep += 1;
    m_state = TamagotchiState::RESTING;
}

void Tamagotchi::updateState() {
    switch (m_state) {
        case TamagotchiState::IDLE: {
            m_hunger = (m_hunger > 0) ? m_hunger - 1 : m_hunger;
            m_sleep = (m_sleep > 0) ? m_sleep - 1 : m_sleep;
            break;
        }
        case TamagotchiState::RESTING: {
            m_hunger = (m_hunger > 0) ? m_hunger - 1 : m_hunger;
            m_sleep += 1;
            break;
        }
    }
    
}

int Tamagotchi::hunger() const { return m_hunger; }

int Tamagotchi::sleep() const { return m_sleep; }

TamagotchiState Tamagotchi::state() const { return m_state; }