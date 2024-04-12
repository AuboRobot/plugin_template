#ifndef USERSERVICERPCSERVICE_H
#define USERSERVICERPCSERVICE_H
#include "cpphttplibconnector.hpp"
#include "user_service.h"

class UserServiceRpcService : public jsonrpccxx::JsonRpc2Server
{
public:
    UserServiceRpcService(int port = 8988);
    ~UserServiceRpcService();
    bool startListening();

    void join();

private:
    CppHttpLibServerConnectorPtr connector_;
    UserServicePtr user_service_;
};

#endif // USERSERVICERPCSERVICE_H
