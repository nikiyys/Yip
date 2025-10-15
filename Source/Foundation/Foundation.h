#pragma once

#ifdef _WIN32
	#ifdef FOUNDATION_EXPORTS
		#define FOUNDATION_API __declspec(dllexport)
	#else
		#define FOUNDATION_API __declspec(dllimport)
	#endif
#else
	#define FOUNDATION_API
#endif
