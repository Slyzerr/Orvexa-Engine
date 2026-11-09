#include "Inputs.h"

namespace engine::core
{
	// Constructor for the Input class, initializes key and mouse button states
	Input::Input()
	{
		// Initialize the current and previous key states to false
		for (std::size_t i = 0; i < KEY_COUNT; ++i)
		{
			m_current_keys[i] = false;
			m_previous_keys[i] = false;
		}
		//	Initialize the current and previous mouse button states to false
		for (std::size_t i = 0; i < MOUSE_BUTTON_COUNT; ++i)
		{
			m_current_mouse_buttons[i] = false;
			m_previous_mouse_buttons[i] = false;
		}
	}

	Input::~Input()
	{
	}
	// Updates the input state for the current frame
	void Input::Update()
	{
		// Update the previous state of keys and mouse buttons
		for (std::size_t i = 0; i < KEY_COUNT; ++i)
		{
			m_previous_keys[i] = m_current_keys[i];
		}

		// Update the previous state of mouse buttons
		for (std::size_t i = 0; i < MOUSE_BUTTON_COUNT; ++i)
		{
			m_previous_mouse_buttons[i] =
				m_current_mouse_buttons[i];
		}

		m_vertical_wheel_delta = 0.0f;
		m_horizontal_wheel_delta = 0.0f;
	}

	// Processes an SFML event and updates the input state accordingly
	void Input::ProcessEvent(const sf::Event& event)
	{
		// Handle focus lost event
		if (event.is<sf::Event::FocusLost>())
		{
			for (std::size_t i = 0; i < KEY_COUNT; ++i)
				m_current_keys[i] = false;

			for (std::size_t i = 0; i < MOUSE_BUTTON_COUNT; ++i)
				m_current_mouse_buttons[i] = false;

			return;
		}

		// Handle key press events
		if (const auto* key_pressed =
			event.getIf<sf::Event::KeyPressed>())
		{
			switch (key_pressed->scancode)
			{
				// A to Z keys
			case sf::Keyboard::Scancode::A:
				m_current_keys[static_cast<std::size_t>(Key::A)] = true;
				break;

			case sf::Keyboard::Scancode::B:
				m_current_keys[static_cast<std::size_t>(Key::B)] = true;
				break;

			case sf::Keyboard::Scancode::C:
				m_current_keys[static_cast<std::size_t>(Key::C)] = true;
				break;
			case sf::Keyboard::Scancode::D:
				m_current_keys[static_cast<std::size_t>(Key::D)] = true;
				break;

			case sf::Keyboard::Scancode::E:
				m_current_keys[static_cast<std::size_t>(Key::E)] = true;
				break;

			case sf::Keyboard::Scancode::F:
				m_current_keys[static_cast<std::size_t>(Key::F)] = true;
				break;

			case sf::Keyboard::Scancode::G:
				m_current_keys[static_cast<std::size_t>(Key::G)] = true;
				break;

			case sf::Keyboard::Scancode::H:
				m_current_keys[static_cast<std::size_t>(Key::H)] = true;
				break;

			case sf::Keyboard::Scancode::I:
				m_current_keys[static_cast<std::size_t>(Key::I)] = true;
				break;

			case sf::Keyboard::Scancode::J:
				m_current_keys[static_cast<std::size_t>(Key::J)] = true;
				break;

			case sf::Keyboard::Scancode::K:
				m_current_keys[static_cast<std::size_t>(Key::K)] = true;
				break;
			case sf::Keyboard::Scancode::L:
				m_current_keys[static_cast<std::size_t>(Key::L)] = true;
				break;
			case sf::Keyboard::Scancode::M:
				m_current_keys[static_cast<std::size_t>(Key::M)] = true;
				break;
			case sf::Keyboard::Scancode::N:
				m_current_keys[static_cast<std::size_t>(Key::N)] = true;
				break;
			case sf::Keyboard::Scancode::O:
				m_current_keys[static_cast<std::size_t>(Key::O)] = true;
				break;
			case sf::Keyboard::Scancode::P:
				m_current_keys[static_cast<std::size_t>(Key::P)] = true;
				break;
			case sf::Keyboard::Scancode::Q:
				m_current_keys[static_cast<std::size_t>(Key::Q)] = true;
				break;
			case sf::Keyboard::Scancode::R:
				m_current_keys[static_cast<std::size_t>(Key::R)] = true;
				break;
			case sf::Keyboard::Scancode::S:
				m_current_keys[static_cast<std::size_t>(Key::S)] = true;
				break;
			case sf::Keyboard::Scancode::T:
				m_current_keys[static_cast<std::size_t>(Key::T)] = true;
				break;
			case sf::Keyboard::Scancode::U:
				m_current_keys[static_cast<std::size_t>(Key::U)] = true;
				break;
			case sf::Keyboard::Scancode::V:
				m_current_keys[static_cast<std::size_t>(Key::V)] = true;
				break;
			case sf::Keyboard::Scancode::W:
				m_current_keys[static_cast<std::size_t>(Key::W)] = true;
				break;
			case sf::Keyboard::Scancode::X:
				m_current_keys[static_cast<std::size_t>(Key::X)] = true;
				break;
			case sf::Keyboard::Scancode::Y:
				m_current_keys[static_cast<std::size_t>(Key::Y)] = true;
				break;
			case sf::Keyboard::Scancode::Z:
				m_current_keys[static_cast<std::size_t>(Key::Z)] = true;
				break;

				// Arrow keys
			case sf::Keyboard::Scancode::Up:
				m_current_keys[static_cast<std::size_t>(Key::UP_ARROW)] = true;
				break;
			case sf::Keyboard::Scancode::Down:
				m_current_keys[static_cast<std::size_t>(Key::DOWN_ARROW)] = true;
				break;
			case sf::Keyboard::Scancode::Left:
				m_current_keys[static_cast<std::size_t>(Key::LEFT_ARROW)] = true;
				break;
			case sf::Keyboard::Scancode::Right:
				m_current_keys[static_cast<std::size_t>(Key::RIGHT_ARROW)] = true;
				break;

				// Function keys
			case sf::Keyboard::Scancode::F1:
				m_current_keys[static_cast<std::size_t>(Key::F1)] = true;
				break;
			case sf::Keyboard::Scancode::F2:
				m_current_keys[static_cast<std::size_t>(Key::F2)] = true;
				break;
			case sf::Keyboard::Scancode::F3:
				m_current_keys[static_cast<std::size_t>(Key::F3)] = true;
				break;
			case sf::Keyboard::Scancode::F4:
				m_current_keys[static_cast<std::size_t>(Key::F4)] = true;
				break;
			case sf::Keyboard::Scancode::F5:
				m_current_keys[static_cast<std::size_t>(Key::F5)] = true;
				break;
			case sf::Keyboard::Scancode::F6:
				m_current_keys[static_cast<std::size_t>(Key::F6)] = true;
				break;
			case sf::Keyboard::Scancode::F7:
				m_current_keys[static_cast<std::size_t>(Key::F7)] = true;
				break;
			case sf::Keyboard::Scancode::F8:
				m_current_keys[static_cast<std::size_t>(Key::F8)] = true;
				break;
			case sf::Keyboard::Scancode::F9:
				m_current_keys[static_cast<std::size_t>(Key::F9)] = true;
				break;
			case sf::Keyboard::Scancode::F10:
				m_current_keys[static_cast<std::size_t>(Key::F10)] = true;
				break;
			case sf::Keyboard::Scancode::F11:
				m_current_keys[static_cast<std::size_t>(Key::F11)] = true;
				break;
			case sf::Keyboard::Scancode::F12:
				m_current_keys[static_cast<std::size_t>(Key::F12)] = true;
				break;
			case sf::Keyboard::Scancode::Tab:
				m_current_keys[static_cast<std::size_t>(Key::TAB)] = true;
				break;

				// Modifier keys
			case sf::Keyboard::Scancode::CapsLock:
				m_current_keys[static_cast<std::size_t>(Key::CAPS_LOCK)] = true;
				break;
			case sf::Keyboard::Scancode::LShift:
			case sf::Keyboard::Scancode::RShift:
				m_current_keys[static_cast<std::size_t>(Key::SHIFT)] = true;
				break;
			case sf::Keyboard::Scancode::LControl:
				m_current_keys[static_cast<std::size_t>(Key::CTRL)] = true;
				break;
			case sf::Keyboard::Scancode::LAlt:
				m_current_keys[static_cast<std::size_t>(Key::ALT)] = true;
				break;
			case sf::Keyboard::Scancode::Backspace:
				m_current_keys[static_cast<std::size_t>(Key::BACKSPACE)] = true;
				break;
			case sf::Keyboard::Scancode::Enter:
				m_current_keys[static_cast<std::size_t>(Key::ENTER)] = true;
				break;
			case sf::Keyboard::Scancode::Space:
				m_current_keys[static_cast<std::size_t>(Key::SPACE)] = true;
				break;
			case sf::Keyboard::Scancode::Escape:
				m_current_keys[static_cast<std::size_t>(Key::ESCAPE)] = true;
				break;

				// Number keys
			case sf::Keyboard::Scancode::Num1:
				m_current_keys[static_cast<std::size_t>(Key::ONE)] = true;
				break;
			case sf::Keyboard::Scancode::Num2:
				m_current_keys[static_cast<std::size_t>(Key::TWO)] = true;
				break;
			case sf::Keyboard::Scancode::Num3:
				m_current_keys[static_cast<std::size_t>(Key::THREE)] = true;
				break;
			case sf::Keyboard::Scancode::Num4:
				m_current_keys[static_cast<std::size_t>(Key::FOUR)] = true;
				break;
			case sf::Keyboard::Scancode::Num5:
				m_current_keys[static_cast<std::size_t>(Key::FIVE)] = true;
				break;
			case sf::Keyboard::Scancode::Num6:
				m_current_keys[static_cast<std::size_t>(Key::SIX)] = true;
				break;
			case sf::Keyboard::Scancode::Num7:
				m_current_keys[static_cast<std::size_t>(Key::SEVEN)] = true;
				break;
			case sf::Keyboard::Scancode::Num8:
				m_current_keys[static_cast<std::size_t>(Key::EIGHT)] = true;
				break;
			case sf::Keyboard::Scancode::Num9:
				m_current_keys[static_cast<std::size_t>(Key::NINE)] = true;
				break;
			case sf::Keyboard::Scancode::Num0:
				m_current_keys[static_cast<std::size_t>(Key::ZERO)] = true;
				break;

			default:
				break;
			}
		}

		// Handle key released events
		if (const auto* key_released =
			event.getIf<sf::Event::KeyReleased>())
		{
			switch (key_released->scancode)
			{
				// A to Z keys
			case sf::Keyboard::Scancode::A:
				m_current_keys[static_cast<std::size_t>(Key::A)] = false;
				break;

			case sf::Keyboard::Scancode::B:
				m_current_keys[static_cast<std::size_t>(Key::B)] = false;
				break;

			case sf::Keyboard::Scancode::C:
				m_current_keys[static_cast<std::size_t>(Key::C)] = false;
				break;

			case sf::Keyboard::Scancode::D:
				m_current_keys[static_cast<std::size_t>(Key::D)] = false;
				break;

			case sf::Keyboard::Scancode::E:
				m_current_keys[static_cast<std::size_t>(Key::E)] = false;
				break;

			case sf::Keyboard::Scancode::F:
				m_current_keys[static_cast<std::size_t>(Key::F)] = false;
				break;

			case sf::Keyboard::Scancode::G:
				m_current_keys[static_cast<std::size_t>(Key::G)] = false;
				break;

			case sf::Keyboard::Scancode::H:
				m_current_keys[static_cast<std::size_t>(Key::H)] = false;
				break;

			case sf::Keyboard::Scancode::I:
				m_current_keys[static_cast<std::size_t>(Key::I)] = false;
				break;

			case sf::Keyboard::Scancode::J:
				m_current_keys[static_cast<std::size_t>(Key::J)] = false;
				break;

			case sf::Keyboard::Scancode::K:
				m_current_keys[static_cast<std::size_t>(Key::K)] = false;
				break;

			case sf::Keyboard::Scancode::L:
				m_current_keys[static_cast<std::size_t>(Key::L)] = false;
				break;

			case sf::Keyboard::Scancode::M:
				m_current_keys[static_cast<std::size_t>(Key::M)] = false;
				break;

			case sf::Keyboard::Scancode::N:
				m_current_keys[static_cast<std::size_t>(Key::N)] = false;
				break;

			case sf::Keyboard::Scancode::O:
				m_current_keys[static_cast<std::size_t>(Key::O)] = false;
				break;

			case sf::Keyboard::Scancode::P:
				m_current_keys[static_cast<std::size_t>(Key::P)] = false;
				break;

			case sf::Keyboard::Scancode::Q:
				m_current_keys[static_cast<std::size_t>(Key::Q)] = false;
				break;

			case sf::Keyboard::Scancode::R:
				m_current_keys[static_cast<std::size_t>(Key::R)] = false;
				break;

			case sf::Keyboard::Scancode::S:
				m_current_keys[static_cast<std::size_t>(Key::S)] = false;
				break;

			case sf::Keyboard::Scancode::T:
				m_current_keys[static_cast<std::size_t>(Key::T)] = false;
				break;

			case sf::Keyboard::Scancode::U:
				m_current_keys[static_cast<std::size_t>(Key::U)] = false;
				break;

			case sf::Keyboard::Scancode::V:
				m_current_keys[static_cast<std::size_t>(Key::V)] = false;
				break;

			case sf::Keyboard::Scancode::W:
				m_current_keys[static_cast<std::size_t>(Key::W)] = false;
				break;

			case sf::Keyboard::Scancode::X:
				m_current_keys[static_cast<std::size_t>(Key::X)] = false;
				break;

			case sf::Keyboard::Scancode::Y:
				m_current_keys[static_cast<std::size_t>(Key::Y)] = false;
				break;
			case sf::Keyboard::Scancode::Z:
				m_current_keys[static_cast<std::size_t>(Key::Z)] = false;
				break;

				// Arrow keys
			case sf::Keyboard::Scancode::Up:
				m_current_keys[static_cast<std::size_t>(Key::UP_ARROW)] = false;
				break;

			case sf::Keyboard::Scancode::Down:
				m_current_keys[static_cast<std::size_t>(Key::DOWN_ARROW)] = false;
				break;

			case sf::Keyboard::Scancode::Left:
				m_current_keys[static_cast<std::size_t>(Key::LEFT_ARROW)] = false;
				break;

			case sf::Keyboard::Scancode::Right:
				m_current_keys[static_cast<std::size_t>(Key::RIGHT_ARROW)] = false;
				break;

				// Function keys
			case sf::Keyboard::Scancode::F1:
				m_current_keys[static_cast<std::size_t>(Key::F1)] = false;
				break;

			case sf::Keyboard::Scancode::F2:
				m_current_keys[static_cast<std::size_t>(Key::F2)] = false;
				break;

			case sf::Keyboard::Scancode::F3:
				m_current_keys[static_cast<std::size_t>(Key::F3)] = false;
				break;

			case sf::Keyboard::Scancode::F4:
				m_current_keys[static_cast<std::size_t>(Key::F4)] = false;
				break;

			case sf::Keyboard::Scancode::F5:
				m_current_keys[static_cast<std::size_t>(Key::F5)] = false;
				break;

			case sf::Keyboard::Scancode::F6:
				m_current_keys[static_cast<std::size_t>(Key::F6)] = false;
				break;

			case sf::Keyboard::Scancode::F7:
				m_current_keys[static_cast<std::size_t>(Key::F7)] = false;
				break;

			case sf::Keyboard::Scancode::F8:
				m_current_keys[static_cast<std::size_t>(Key::F8)] = false;
				break;
			case sf::Keyboard::Scancode::F9:
				m_current_keys[static_cast<std::size_t>(Key::F9)] = false;
				break;

			case sf::Keyboard::Scancode::F10:
				m_current_keys[static_cast<std::size_t>(Key::F10)] = false;
				break;

			case sf::Keyboard::Scancode::F11:
				m_current_keys[static_cast<std::size_t>(Key::F11)] = false;
				break;

			case sf::Keyboard::Scancode::F12:
				m_current_keys[static_cast<std::size_t>(Key::F12)] = false;
				break;

				// Modifier keys
			case sf::Keyboard::Scancode::Tab:
				m_current_keys[static_cast<std::size_t>(Key::TAB)] = false;
				break;

			case sf::Keyboard::Scancode::CapsLock:
				m_current_keys[static_cast<std::size_t>(Key::CAPS_LOCK)] = false;
				break;

			case sf::Keyboard::Scancode::RShift:
			case sf::Keyboard::Scancode::LShift:
				m_current_keys[static_cast<std::size_t>(Key::SHIFT)] = false;
				break;

			case sf::Keyboard::Scancode::LControl:
				m_current_keys[static_cast<std::size_t>(Key::CTRL)] = false;
				break;

			case sf::Keyboard::Scancode::LAlt:
				m_current_keys[static_cast<std::size_t>(Key::ALT)] = false;
				break;

			case sf::Keyboard::Scancode::Backspace:
				m_current_keys[static_cast<std::size_t>(Key::BACKSPACE)] = false;
				break;

			case sf::Keyboard::Scancode::Enter:
				m_current_keys[static_cast<std::size_t>(Key::ENTER)] = false;
				break;

			case sf::Keyboard::Scancode::Space:
				m_current_keys[static_cast<std::size_t>(Key::SPACE)] = false;
				break;

			case sf::Keyboard::Scancode::Escape:
				m_current_keys[static_cast<std::size_t>(Key::ESCAPE)] = false;
				break;
				// Number keys
			case sf::Keyboard::Scancode::Num1:
				m_current_keys[static_cast<std::size_t>(Key::ONE)] = false;
				break;

			case sf::Keyboard::Scancode::Num2:
				m_current_keys[static_cast<std::size_t>(Key::TWO)] = false;
				break;

			case sf::Keyboard::Scancode::Num3:
				m_current_keys[static_cast<std::size_t>(Key::THREE)] = false;
				break;

			case sf::Keyboard::Scancode::Num4:
				m_current_keys[static_cast<std::size_t>(Key::FOUR)] = false;
				break;

			case sf::Keyboard::Scancode::Num5:
				m_current_keys[static_cast<std::size_t>(Key::FIVE)] = false;
				break;

			case sf::Keyboard::Scancode::Num6:
				m_current_keys[static_cast<std::size_t>(Key::SIX)] = false;
				break;

			case sf::Keyboard::Scancode::Num7:
				m_current_keys[static_cast<std::size_t>(Key::SEVEN)] = false;
				break;

			case sf::Keyboard::Scancode::Num8:
				m_current_keys[static_cast<std::size_t>(Key::EIGHT)] = false;
				break;

			case sf::Keyboard::Scancode::Num9:
				m_current_keys[static_cast<std::size_t>(Key::NINE)] = false;
				break;

			case sf::Keyboard::Scancode::Num0:
				m_current_keys[static_cast<std::size_t>(Key::ZERO)] = false;
				break;

			default:
				break;
			}
		}

		// Handle mouse button pressed events
		if (const auto* mouse_pressed =
			event.getIf<sf::Event::MouseButtonPressed>())
		{
			// Handle mouse button pressed events
			switch (mouse_pressed->button)
			{
			case sf::Mouse::Button::Left:
				m_current_mouse_buttons[static_cast<std::size_t>(MouseButton::LEFT)] = true;
				break;
			case sf::Mouse::Button::Right:
				m_current_mouse_buttons[static_cast<std::size_t>(MouseButton::RIGHT)] = true;
				break;
			case sf::Mouse::Button::Middle:
				m_current_mouse_buttons[static_cast<std::size_t>(MouseButton::MIDDLE)] = true;
				break;
			case sf::Mouse::Button::Extra1:
				m_current_mouse_buttons[static_cast<std::size_t>(MouseButton::X1)] = true;
				break;
			case sf::Mouse::Button::Extra2:
				m_current_mouse_buttons[static_cast<std::size_t>(MouseButton::X2)] = true;
				break;
			default:
				break;
			}
		}
		// Handle mouse button released events
		if (const auto* mouse_released =
			event.getIf<sf::Event::MouseButtonReleased>())
		{
			switch (mouse_released->button)
			{
			case sf::Mouse::Button::Left:
				m_current_mouse_buttons[static_cast<std::size_t>(MouseButton::LEFT)] = false;
				break;
			case sf::Mouse::Button::Right:
				m_current_mouse_buttons[static_cast<std::size_t>(MouseButton::RIGHT)] = false;
				break;
			case sf::Mouse::Button::Middle:
				m_current_mouse_buttons[static_cast<std::size_t>(MouseButton::MIDDLE)] = false;
				break;
			case sf::Mouse::Button::Extra1:
				m_current_mouse_buttons[static_cast<std::size_t>(MouseButton::X1)] = false;
				break;
			case sf::Mouse::Button::Extra2:
				m_current_mouse_buttons[static_cast<std::size_t>(MouseButton::X2)] = false;
				break;
			default:
				break;
			}
		}

		// Handle mouse wheel scrolled events
		if (const auto* mouse_wheel =
			event.getIf<sf::Event::MouseWheelScrolled>())
		{

			if (mouse_wheel->wheel ==
				sf::Mouse::Wheel::Vertical)
			{
				m_vertical_wheel_delta += mouse_wheel->delta;
			}
			else if (mouse_wheel->wheel ==
				sf::Mouse::Wheel::Horizontal)
			{
				m_horizontal_wheel_delta += mouse_wheel->delta;
			}
		}

		// Handle mouse moved events
		if (const auto* mouse_moved =
			event.getIf<sf::Event::MouseMoved>())
		{
			m_mouse_position.x = mouse_moved->position.x;
			m_mouse_position.y = mouse_moved->position.y;
		}
	}
	// Checks if a specific key is currently down
	bool Input::IsKeyDown(Key key) const
	{
		return m_current_keys[
			static_cast<std::size_t>(key)
		];
	}

	// Checks if a specific key was pressed in the current frame
	bool Input::IsKeyPressed(Key key) const
	{
		const std::size_t index =
			static_cast<std::size_t>(key);

		return m_current_keys[index] &&
			!m_previous_keys[index];
	}

	// Checks if a specific key was released in the current frame
	bool Input::IsKeyReleased(Key key) const
	{
		const std::size_t index =
			static_cast<std::size_t>(key);

		return !m_current_keys[index] &&
			m_previous_keys[index];
	}

	// Checks if a specific mouse button is currently down
	bool Input::IsMouseButtonDown(MouseButton button) const
	{
		return m_current_mouse_buttons[
			static_cast<std::size_t>(button)
		];
	}

	// Checks if a specific mouse button was pressed in the current frame
	bool Input::IsMouseButtonPressed(MouseButton button) const
	{
		const std::size_t index =
			static_cast<std::size_t>(button);

		return m_current_mouse_buttons[index] &&
			!m_previous_mouse_buttons[index];
	}

	// Checks if a specific mouse button was released in the current frame
	bool Input::IsMouseButtonReleased(MouseButton button) const
	{
		const std::size_t index =
			static_cast<std::size_t>(button);

		return !m_current_mouse_buttons[index] &&
			m_previous_mouse_buttons[index];
	}

	// Returns the amount of mouse wheel movement for the specified wheel
	float Input::GetMouseWheelDelta(MouseWheel wheel) const
	{
		if (wheel == MouseWheel::VERTICAL)
			return m_vertical_wheel_delta;

		return m_horizontal_wheel_delta;
	}

	// Returns the current mouse position
	MousePosition Input::GetMousePosition() const
	{
		return m_mouse_position;
	}
}