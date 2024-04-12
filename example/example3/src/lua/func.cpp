#include "func.h"
#include "iostream"
int luaopen_algorithm(lua_State *state)
{
    auto retval = sol::stack::call_lua(state, 1, [](sol::this_state L) {
        sol::state_view lua(L);
        sol::table module = lua.create_table();

        sol::automagic_enrollments enrollments;
        enrollments.default_constructor = false; // 不生成构造函数
        enrollments.destructor = false;
        auto u = module.new_usertype<Algorithm>(
            "Algorithm", sol::constructors<Algorithm()>());

        u.set_function("add", &Algorithm::add);
        u.set_function("sub", &Algorithm::sub);
        u.set_function("mul", &Algorithm::mul);
        u.set_function("div", &Algorithm::div);

        return module;
    });

    return retval;
}

Algorithm::Algorithm()
{
}

int Algorithm::add(int value_a, int value_b)
{
    return value_a + value_b;
}

int Algorithm::sub(int value_a, int value_b)
{
    return value_a - value_b;
}

int Algorithm::mul(int value_a, int value_b)
{
    return value_a * value_b;
}

int Algorithm::div(int value_a, int value_b)
{
    return value_a / value_b;
}
