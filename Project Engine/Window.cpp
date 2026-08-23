#include "window.h"

namespace engine::core
{
    Window::Window()
    {
    }

    Window::~Window()
    {
        Close();
    }

    bool Window::Create(unsigned int width, unsigned int height, const std::string& title)
    {
        m_window.create(
            sf::VideoMode({ width, height }),
            title
        );

        return m_window.isOpen();
    }

    void Window::Close()
    {
        if (m_window.isOpen())
        {
            m_window.close();
        }
    }

    bool Window::IsOpen() const
    {
        return m_window.isOpen();
    }

    std::optional<sf::Event> Window::PollEvent()
    {
        return m_window.pollEvent();
    }
}