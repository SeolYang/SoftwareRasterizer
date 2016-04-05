#pragma once

#define WIN32_MEAN_AND_LEAN
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <memory>

#ifdef _MSC_VER
#define MS_ALIGN(N) __declspec(align(N))
#endif

