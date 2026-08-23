#include "runtime.h"
#include <iostream>

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
		if (!m_window.Create(1280, 720, "My Engine"))
			return false;

		m_is_running = true;

		return true;
	}

	void Runtime::Run()
	{
		if (!m_is_running)
			return;

		while (m_is_running)
		{
			ProcessEvents();

			m_time.Update();

			Update();
			Render();

			m_input.Update();
		}
	}

	void Runtime::Shutdown()
	{
		if (!m_is_running)
			return;

		m_window.Close();

		m_is_running = false;
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
				m_is_running = false;
				continue;
			}

			m_input.ProcessEvent(*event);
		}
	}

	void Runtime::Update()
	{
		/*if (m_input.IsKeyDown(Key::F1))
			std::cout
			<< "FPS: " << m_time.GetFPS()
			<< " | Delta: " << m_time.GetDeltaTime()
			<< " | Elapsed: " << m_time.GetElapsedTime()
			<< '\n';

		if (m_input.IsKeyPressed(Key::W))
			std::cout << "W PRESSED\n";

		if (m_input.IsKeyDown(Key::W))
			std::cout << "W DOWN\n";

		if (m_input.IsKeyReleased(Key::W))
			std::cout << "W RELEASED\n";*/
	}

	void Runtime::Render()
	{
	}
}