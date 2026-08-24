#pragma once

#include <filesystem>
#include <string>

namespace engine::core
{
	class FileSystem
	{
	public:
		static bool Exists(const std::filesystem::path& path);

		static bool IsFile(const std::filesystem::path& path);
		static bool IsDirectory(const std::filesystem::path& path);

		static bool CreateDirectory(const std::filesystem::path& path);

		static std::string ReadText(const std::filesystem::path& path);
		static bool WriteText(
			const std::filesystem::path& path,
			const std::string& content
		);
	};
}