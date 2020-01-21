#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace er {

	class Log
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

// Core log macros
#define ER_CORE_TRACE(...)    ::er::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ER_CORE_INFO(...)     ::er::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ER_CORE_WARN(...)     ::er::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ER_CORE_ERROR(...)    ::er::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ER_CORE_FATAL(...)    ::er::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ER_TRACE(...)	      ::er::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ER_INFO(...)	      ::er::Log::GetClientLogger()->info(__VA_ARGS__)
#define ER_WARN(...)	      ::er::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ER_ERROR(...)	      ::er::Log::GetClientLogger()->error(__VA_ARGS__)
#define ER_FATAL(...)	      ::er::Log::GetClientLogger()->critical(__VA_ARGS__)