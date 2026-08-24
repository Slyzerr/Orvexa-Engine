#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <cstddef>

namespace engine::core
{
    enum class Key
    {
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L, 
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,

        UP_ARROW,
        DOWN_ARROW,
        LEFT_ARROW,
        RIGHT_ARROW,

        ONE,
		TWO,
		THREE,
        FOUR,
		FIVE,
        SIX,
		SEVEN,
		EIGHT,
		NINE,
        ZERO,



        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,

        TAB,
        CAPS_LOCK,
        SHIFT,
        CTRL,
        ALT,

        BACKSPACE,
        ENTER,
        SPACE,
        ESCAPE,
        

        COUNT

    };

    enum class MouseButton
    {
        LEFT,
        RIGHT,
        MIDDLE,
        X1,
        X2,

        COUNT
    };

    enum class MouseWheel
    {
        VERTICAL,
        HORIZONTAL
    };

    struct MousePosition
    {
        int x = 0;
        int y = 0;
    };

    class Input
    {
    public:
        Input();
        ~Input();

        void ProcessEvent(const sf::Event& event);
        void Update();

        bool IsKeyDown(Key key) const;
        bool IsKeyPressed(Key key) const;
        bool IsKeyReleased(Key key) const;

        bool IsMouseButtonDown(MouseButton button) const;
        bool IsMouseButtonPressed(MouseButton button) const;
        bool IsMouseButtonReleased(MouseButton button) const;

        float GetMouseWheelDelta(MouseWheel wheel) const;
        MousePosition GetMousePosition() const;

    private:
        static constexpr std::size_t KEY_COUNT =
            static_cast<std::size_t>(Key::COUNT);

        static constexpr std::size_t MOUSE_BUTTON_COUNT =
            static_cast<std::size_t>(MouseButton::COUNT);

        bool m_current_keys[KEY_COUNT];
        bool m_previous_keys[KEY_COUNT];

        bool m_current_mouse_buttons[MOUSE_BUTTON_COUNT];
        bool m_previous_mouse_buttons[MOUSE_BUTTON_COUNT];

        float m_vertical_wheel_delta = 0.0f;
        float m_horizontal_wheel_delta = 0.0f;

        MousePosition m_mouse_position;
    };
}