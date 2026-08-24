#pragma once

#include <format>
#include <iostream>
#include <string_view>

namespace engine::core
{
    enum class LogLevel
    {
        Trace,
        Info,
        Warning,
        Error
    };

    class Logger
    {
    public:
        template<typename... Args>
        static void Trace(std::format_string<Args...> format, Args&&... args)
        {
            LogMessage(
                LogLevel::Trace,
                std::format(format, std::forward<Args>(args)...)
            );
        }

        template<typename... Args>
        static void Info(std::format_string<Args...> format, Args&&... args)
        {
            LogMessage(
                LogLevel::Info,
                std::format(format, std::forward<Args>(args)...)
            );
        }

        template<typename... Args>
        static void Warning(std::format_string<Args...> format, Args&&... args)
        {
            LogMessage(
                LogLevel::Warning,
                std::format(format, std::forward<Args>(args)...)
            );
        }

        template<typename... Args>
        static void Error(std::format_string<Args...> format, Args&&... args)
        {
            LogMessage(
                LogLevel::Error,
                std::format(format, std::forward<Args>(args)...)
            );
        }

    private:
        static void LogMessage(
            LogLevel level,
            std::string_view message
        );
    };
}   
#define LOG_TRACE(...) engine::core::Logger::Trace(__VA_ARGS__)
#define LOG_INFO(...) engine::core::Logger::Info(__VA_ARGS__)
#define LOG_WARNING(...) engine::core::Logger::Warning(__VA_ARGS__)
#define LOG_ERROR(...) engine::core::Logger::Error(__VA_ARGS__)