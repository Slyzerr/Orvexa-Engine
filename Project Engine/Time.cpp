#include "Time.h"

namespace engine::core
{
	Time::Time()
		: m_last_time(std::chrono::steady_clock::now())
	{
	}

	Time::~Time()
	{
	}
	void Time::Update()
	{
		const auto current_time = std::chrono::steady_clock::now();

		const std::chrono::duration<float> delta_time = current_time - m_last_time;

		m_delta_time = delta_time.count();
		m_elapsed_time += m_delta_time;

		m_fps = (m_delta_time > 0.0f) ? 1.0f / m_delta_time : 0.0f;

		m_last_time = current_time;
	}

	void Time::Reset()
	{
		m_last_time = std::chrono::steady_clock::now();
		m_delta_time = 0.0f;
		m_elapsed_time = 0.0f;
		m_fps = 0.0f;
	}

	float Time::GetDeltaTime() const
	{
		return m_delta_time;
	}

	float Time::GetElapsedTime() const
	{
		return m_elapsed_time;
	}

	float Time::GetFPS() const
	{
		return m_fps;
	}
}

