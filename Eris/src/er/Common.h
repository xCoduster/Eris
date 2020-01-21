#pragma once

// Common defines
#define BIT(x) (1 << x)
#define ER_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#ifdef ER_DEBUG
	#define ER_ENABLE_ASSERTS
#endif

#ifdef ER_ENABLE_ASSERTS
	#define ER_ASSERT(x, ...)	{ if (!(x)) { ER__ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ER_CORE_ASSERT(x, ...)	{ if (!(x)) { ER_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ER_ASSERT(x, ...)
	#define ER_CORE_ASSERT(x, ...)
#endif