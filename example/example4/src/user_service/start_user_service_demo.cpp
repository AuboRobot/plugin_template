#include "user_service_rpc_service.h"

int main(int argc, char *argv[])
{
    // TODO: 解析参数，可以通过参数指定端口
    UserServiceRpcService server(8988);

    server.startListening();
    server.join();

    return 0;
}
