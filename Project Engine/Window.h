#pragma once

#include <string>
#include <optional>

#include <SFML/Graphics.hpp>

namespace engine::core
{
    class Window
    {
    public:
        Window();
        ~Window();

        bool Create(
            unsigned int width,
            unsigned int height,
            const std::string& title
        );

        void Close();

        bool IsOpen() const;

        std::optional<sf::Event> PollEvent();

    private:
        sf::RenderWindow m_window;
    };
}