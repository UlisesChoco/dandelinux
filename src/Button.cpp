#include "Button.h"
#include <iostream>

Button::Button(std::string title, float x, float y, float w, float h, std::function<void()> callback)
    : m_title{title}, m_x{x}, m_y{y}, m_w{w}, m_h{h}, m_onClick{std::move(callback)} { }

void Button::onMouseEnter(float mouseX, float mouseY) {
    if (m_x <= mouseX && mouseX <= m_x + m_w
        &&
        m_y <= mouseY && mouseY <= m_y + m_h
    ) {
        std::cout << "OnMouseEnter\n";
    }
}

void Button::onMouseClick(float mouseX, float mouseY) {
    if (m_x <= mouseX && mouseX <= m_x + m_w
        &&
        m_y <= mouseY && mouseY <= m_y + m_h
    ) {
        m_onClick();
    }
}

std::string Button::title() const { return m_title; }

float Button::x() const { return m_x; }

float Button::y() const { return m_y; }

float Button::w() const { return m_w; }

float Button::h() const { return m_h; }