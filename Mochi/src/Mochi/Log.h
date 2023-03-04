#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Mochi
{
	class MOCHI_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Core log macros
#define MOCHI_CORE_ERROR(...) ::Mochi::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MOCHI_CORE_WARN(...) ::Mochi::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MOCHI_CORE_INFO(...) ::Mochi::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MOCHI_CORE_TRACE(...) ::Mochi::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MOCHI_CORE_FATAL(...) ::Mochi::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros 
#define MOCHI_ERROR(...) ::Mochi::Log::GetClientLogger()->error(__VA_ARGS__)
#define MOCHI_WARN(...) ::Mochi::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MOCHI_INFO(...) ::Mochi::Log::GetClientLogger()->info(__VA_ARGS__)
#define MOCHI_TRACE(...) ::Mochi::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MOCHI_FATAL(...) ::Mochi::Log::GetClientLogger()->critical(__VA_ARGS__)

