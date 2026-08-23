#pragma once

#include "Window.h"
#include "Inputs.h"
#include "Time.h"

namespace engine::core
{
    class Runtime
    {
    public:
        Runtime();
        ~Runtime();

        bool Initialize();
        void Run();
        void Shutdown();

        bool IsRunning() const;

    private:
        void ProcessEvents();
        void Update();
        void Render();

    private:
        Window m_window;
        Input m_input;
		Time m_time;

        bool m_is_running = false;
    };
}