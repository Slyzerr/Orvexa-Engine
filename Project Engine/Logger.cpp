#include "Logger.h"

#include <chrono>
#include <ctime>
#include <iomanip>

namespace engine::core
{
    namespace
    {
        constexpr std::string_view RESET = "\033[0m";
        constexpr std::string_view GRAY = "\033[90m";
        constexpr std::string_view GREEN = "\033[32m";
        constexpr std::string_view YELLOW = "\033[33m";
        constexpr std::string_view RED = "\033[31m";
    }

    void Logger::LogMessage(
        LogLevel level,
        std::string_view message
    )
    {
        const auto now = std::chrono::system_clock::now();
        const auto time = std::chrono::system_clock::to_time_t(now);

        std::tm local_time{};
        localtime_s(&local_time, &time);

        std::cout << '['
            << std::put_time(&local_time, "%H:%M:%S")
            << "] ";

        switch (level)
        {
        case LogLevel::Trace:
            std::cout << GRAY << "[TRACE]   ";
            break;

        case LogLevel::Info:
            std::cout << GREEN << "[INFO]    ";
            break;

        case LogLevel::Warning:
            std::cout << YELLOW << "[WARNING] ";
            break;

        case LogLevel::Error:
            std::cout << RED << "[ERROR]   ";
            break;
        }

        std::cout << message
            << RESET
            << '\n';
    }

}
