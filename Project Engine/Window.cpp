
#include "Window.h"

namespace engine::core
{
    bool Window::Create(
        unsigned int width,
        unsigned int height,
        const std::string& title
    )
    {
        if (width == 0 || height == 0)
            return false;

        m_window.create(
            sf::VideoMode({ width, height }),
            title
        );

        return m_window.isOpen();
    }

    void Window::Close()
    {
        if (m_window.isOpen())
            m_window.close();
    }

    bool Window::IsOpen() const
    {
        return m_window.isOpen();
    }

    std::optional<sf::Event> Window::PollEvent()
    {
        if (!m_window.isOpen())
            return std::nullopt;

        return m_window.pollEvent();
    }
}
