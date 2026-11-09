#pragma once

#include <string>
#include <optional>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

namespace engine::core
{
    class Window
    {
    public:
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
