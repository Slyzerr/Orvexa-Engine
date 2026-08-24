#include "JsonParser.h"

#include <fstream>

#include "Logger.h"

namespace engine::parser
{
	bool JsonParser::Load(
		const std::filesystem::path& path,
		nlohmann::json& output)
	{
		std::ifstream file(path);

		if (!file.is_open())
		{
			LOG_ERROR("Failed to open JSON file: {}", path.string());
			return false;
		}

		try
		{
			file >> output;
		}
		catch (const nlohmann::json::parse_error& error)
		{
			LOG_ERROR(
				"Failed to parse JSON file '{}': {}",
				path.string(),
				error.what()
			);

			return false;
		}

		LOG_INFO("JSON file loaded: {}", path.string());

		return true;
	}

	bool JsonParser::Save(
		const std::filesystem::path& path,
		const nlohmann::json& data)
	{
		std::ofstream file(path);

		if (!file.is_open())
		{
			LOG_ERROR("Failed to create JSON file: {}", path.string());
			return false;
		}

		file << data.dump(4);

		if (!file.good())
		{
			LOG_ERROR("Failed to write JSON file: {}", path.string());
			return false;
		}

		LOG_INFO("JSON file saved: {}", path.string());

		return true;
	}
}