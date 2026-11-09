
#include "Runtime.h"
#include "Logger.h"

namespace engine::core
{
    Runtime::Runtime()
    {
    }

    Runtime::~Runtime()
    {
        Shutdown();
    }

    bool Runtime::Initialize()
    {
        LOG_INFO("Initializing Orvexa Engine...");

        if (!m_window.Create(1280, 720, "Orvexa Engine"))
        {
            LOG_ERROR("Failed to create engine window");
            return false;
        }

        m_is_initialized = true;
        m_is_running = true;

        LOG_INFO("Orvexa Engine initialized");

        return true;
    }

    void Runtime::Run()
    {
        if (!m_is_initialized || !m_is_running)
        {
            LOG_WARNING("Runtime::Run() called while engine is not initialized or running");
            return;
        }

        m_time.Reset();

        LOG_INFO("Engine loop started");

        while (m_is_running)
        {
            ProcessEvents();

            if (!m_is_running)
                break;

            m_time.Update();

            Update();
            Render();

            m_input.Update();
        }

        LOG_INFO("Engine loop stopped");
    }

    void Runtime::Shutdown()
    {
        if (!m_is_initialized)
            return;

        LOG_INFO("Shutting down Orvexa Engine...");

        m_is_running = false;
        m_window.Close();

        m_is_initialized = false;

        LOG_INFO("Orvexa Engine shutdown complete");
    }

    bool Runtime::IsRunning() const
    {
        return m_is_running;
    }

    void Runtime::ProcessEvents()
    {
        while (const auto event = m_window.PollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                LOG_INFO("Window close event received");
                m_is_running = false;
                continue;
            }

            m_input.ProcessEvent(*event);
        }
    }

    void Runtime::Update()
    {
        for (int i = 0; i < static_cast<int>(Key::COUNT); ++i)
        {
            const Key key = static_cast<Key>(i);

            if (m_input.IsKeyPressed(key))
            {
                LOG_INFO("Key pressed: {}", i);
            }
        }

        for (int i = 0; i < static_cast<int>(MouseButton::COUNT); ++i)
        {
            const MouseButton button = static_cast<MouseButton>(i);

            if (m_input.IsMouseButtonPressed(button))
            {
                LOG_INFO("Mouse button pressed: {}", i);
            }
        }
    }

    void Runtime::Render()
    {
    }
}
