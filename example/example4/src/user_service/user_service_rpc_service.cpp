#include "user_service_rpc_service.h"

UserServiceRpcService::UserServiceRpcService(int port)
{
    // 设置用户服务系统服务端的ip以及端口号，这部分设置完成之后会在 aubo_scope
    // 脚本中连接该服务端
    connector_ = std::shared_ptr<CppHttpLibServerConnector>(
        new CppHttpLibServerConnector(*this, port));

    // 实例化一个 UserService ,用于将 UserService
    // 里面需要的接口添加到此rpc服务中去
    user_service_ = std::make_shared<UserService>();

    // 由 UserService 提供的服务
    Add("testFunction",
        jsonrpccxx::GetHandle(&UserService::testFunction, *user_service_), {});
}

UserServiceRpcService::~UserServiceRpcService()
{
}

bool UserServiceRpcService::startListening()
{
    std::cout << "start startListening" << std::endl;
    connector_->StartListening();
}

void UserServiceRpcService::join()
{
    connector_->join();
}
