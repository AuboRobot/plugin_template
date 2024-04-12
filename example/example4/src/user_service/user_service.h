#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include "test.h"

class UserService : public Test
{
public:
    UserService();

    int testFunction() override;
};

using UserServicePtr = std::shared_ptr<UserService>;

#endif // USER_SERVICE_H
