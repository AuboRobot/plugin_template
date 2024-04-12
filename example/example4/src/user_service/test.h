#ifndef TEST_H
#define TEST_H

#include <string>
#include <vector>
#include <map>
#include <memory>

// 用户服务抽象接口，针对一种型号做一次实现
class Test
{
public:
    virtual ~Test() = default;

    virtual int testFunction() = 0;
};
using TestPtr = std::shared_ptr<Test>;

#endif // TEST_H
