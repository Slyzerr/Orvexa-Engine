#pragma once

#include <string>
#include <filesystem>
#include "json.hpp"

namespace engine::parser
{
	class JsonParser
	{
	public:
		static bool Load(
			const std::filesystem::path& path,
			nlohmann::json& output
		);

		static bool Save(
			const std::filesystem::path& path,
			const nlohmann::json& data
		);
	};
}