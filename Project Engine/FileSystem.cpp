#include "FileSystem.h"

#include <fstream>
#include <sstream>

namespace engine::core
{
	bool FileSystem::Exists(const std::filesystem::path& path)
	{
		return std::filesystem::exists(path);
	}

	bool FileSystem::IsFile(const std::filesystem::path& path)
	{
		return std::filesystem::is_regular_file(path);
	}

	bool FileSystem::IsDirectory(const std::filesystem::path& path)
	{
		return std::filesystem::is_directory(path);
	}

	bool FileSystem::CreateDirectory(
		const std::filesystem::path& path)
	{
		return std::filesystem::create_directories(path);
	}

	std::string FileSystem::ReadText(
		const std::filesystem::path& path)
	{
		std::ifstream file(path);

		if (!file.is_open())
			return {};

		std::stringstream buffer;
		buffer << file.rdbuf();

		return buffer.str();
	}

	bool FileSystem::WriteText(
		const std::filesystem::path& path,
		const std::string& content)
	{
		std::ofstream file(path);

		if (!file.is_open())
			return false;

		file << content;

		return file.good();
	}
}