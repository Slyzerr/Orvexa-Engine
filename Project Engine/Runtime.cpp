
#include "Runtime.h"
#include "Logger.h"
#include "FileSystem.h"
#include "JsonParser.h"

namespace engine::core
{
	// Constructor for the engine runtime
    Runtime::Runtime()
    {
        LOG_TRACE("Runtime constructor called");
    }

	// Destructor for the engine runtime
    Runtime::~Runtime()
    {
        LOG_TRACE("Runtime destructor called");
        Shutdown();
    }

	// Initialize the engine runtime
    bool Runtime::Initialize()
    {
		// Initialize the logger
        LOG_INFO("Initializing Orvexa Engine...");

		// Create the engine window
        if (!m_window.Create(1280, 720, "Orvexa Engine"))
        {
            LOG_ERROR("Failed to create engine window");
            return false;
        }

        LOG_INFO("Window created: {}x{}", 1280, 720);

		// Initialize the input system
        m_is_running = true;

		// Initialize the time system
        LOG_INFO("Orvexa Engine initialized");
        LOG_TRACE("Trace message");
        LOG_INFO("Hello Orvexa Engine!");
        LOG_WARNING("This is a warning");
        LOG_ERROR("This is an error");

        LOG_INFO("Integer: {}", 42);
        LOG_INFO("Float: {:.2f}", 3.14159f);
        LOG_INFO("Resolution: {}x{}", 1920, 1080);

        const std::filesystem::path asset_path = "assets";

        if (FileSystem::Exists(asset_path))
        {
            LOG_INFO("Assets directory exists");
        }
        else
        {
            LOG_WARNING("Assets directory does not exist");
        }

        nlohmann::json config;

        if (engine::parser::JsonParser::Load("../config/test.json", config))
        {
            LOG_INFO("Engine: {}", config["engine"].get<std::string>());
            LOG_INFO("Version: {}", config["version"].get<int>());
            LOG_INFO(
                "Resolution: {}x{}",
                config["resolution"]["width"].get<int>(),
                config["resolution"]["height"].get<int>()
            );
        }

        m_is_initialized = true;
        return true;
    }

	// Run the engine runtime
    void Runtime::Run()
    {
		// Check if the engine is running
        if (!m_is_running)
        {
            LOG_WARNING("Runtime::Run() called while engine is not running");
            return;
        }
        m_time.Reset();
        LOG_INFO("Engine loop started");
		// Main engine loop
        while (m_is_running)
        {
            ProcessEvents();

            m_time.Update();

            Update();
            Render();

            m_input.Update();
        }

        LOG_INFO("Engine loop stopped");
    }

	// Shutdown the engine runtime
    void Runtime::Shutdown()
    {
        if(!m_is_initialized)
            return;

        LOG_INFO("Shutting down Orvexa Engine...");
        m_window.Close();
        m_is_running = false;
        m_is_initialized = false;
        LOG_INFO("Orvexa Engine shutdown complete");
    }

	// Check if the engine is running
    bool Runtime::IsRunning() const
    {
        return m_is_running;
    }

	// Process events from the engine window
    void Runtime::ProcessEvents()
    {
		// Poll events from the window and process them
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

	// Update the engine runtime
    void Runtime::Update()
    {
		// Update the engine runtime
        if (m_input.IsKeyDown(Key::F1))
        {
            LOG_INFO(
                "FPS: {} | Delta: {} | Elapsed: {}",
                m_time.GetFPS(),
                m_time.GetDeltaTime(),
                m_time.GetElapsedTime()
            );
        }

		// Check for key events
        if (m_input.IsKeyPressed(Key::W))
        {
            LOG_INFO("W pressed");
        }

        if (m_input.IsKeyDown(Key::W))
        {
            LOG_TRACE("W down");
        }

        if (m_input.IsKeyReleased(Key::W))
        {
            LOG_INFO("W released");
        }
    }

    void Runtime::Render()
    {
    }
}