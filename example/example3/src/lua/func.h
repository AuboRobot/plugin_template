#pragma

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <sol/sol.hpp>
#define ARCS_HAVE_VISIBILITY_ATTRIBUTE

#if defined(ARCS_PLATFORM_WINDOWS)
#define ARCS_ABI_EXPORT __declspec(dllexport)
#define ARCS_ABI_IMPORT __declspec(dllimport)
#define ARCS_ABI_LOCAL
#elif defined(ARCS_HAVE_VISIBILITY_ATTRIBUTE)
#define ARCS_ABI_EXPORT __attribute__((visibility("default")))
#define ARCS_ABI_IMPORT __attribute__((visibility("default")))
#define ARCS_ABI_LOCAL  __attribute__((visibility("hidden")))
#else
#define ARCS_ABI_EXPORT
#define ARCS_ABI_IMPORT
#define ARCS_ABI_LOCAL
#endif

extern "C" {
int ARCS_ABI_EXPORT luaopen_algorithm(lua_State *state);
}

class Algorithm
{
public:
    Algorithm();
    int add(int value_a, int value_b);
    int sub(int value_a, int value_b);
    int mul(int value_a, int value_b);
    int div(int value_a, int value_b);
};
using AlgorithmPtr = std::shared_ptr<Algorithm>;
