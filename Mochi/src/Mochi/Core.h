#pragma once

#ifdef MOCHI_PLATFORM_WINDOWS
#ifdef MOCHI_BUILD_DLL
#define MOCHI_API __declspec(dllexport)
#else
#define MOCHI_API __declspec(dllimport)
#endif
#else
#error Mochi only supports Windows! 
#endif

#define BIT(x) (1 << x)