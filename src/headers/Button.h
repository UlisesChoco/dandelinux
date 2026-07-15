#pragma once

#include <functional>

class Button {
    private:
        float m_x;
        float m_y;
        float m_w;
        float m_h;

        std::function<void()> m_onClick;

    public:
        Button(float x, float y, float w, float h, std::function<void()> callback);

        void onMouseEnter(float mouseX, float mouseY);
        void onMouseClick(float mouseX, float mouseY);

        float x() const;
        float y() const;
        float w() const;
        float h() const;
};