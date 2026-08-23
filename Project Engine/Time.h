#pragma once

#include <chrono>

namespace engine::core
{
    class Time
    {
    public:
        Time();
        ~Time();

        void Update();

        float GetDeltaTime() const;
        float GetElapsedTime() const;
        float GetFPS() const;

    private:
        float m_delta_time = 0.0f;
        float m_elapsed_time = 0.0f;
        float m_fps = 0.0f;

        std::chrono::steady_clock::time_point m_last_time;
    };
}   