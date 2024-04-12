#include "cppmicroservices/Bundle.h"
#include "cppmicroservices/BundleActivator.h"
#include "cppmicroservices/BundleImport.h"
#include "cppmicroservices/BundleContext.h"
#include "cppmicroservices/BundleResource.h"
#include "cppmicroservices/BundleResourceStream.h"
#include "cppmicroservices/Constants.h"
#include "cppmicroservices/ServiceEvent.h"
#include "installation/jsonrpctest_installation_node_service.h"
#include "program/jsonrpctest_program_node_service.h"

using namespace cppmicroservices;

/**
 * This class implements a simple bundle that utilizes the CppMicroServices's
 * event mechanism to listen for service events. Upon receiving a service event,
 * it prints out the event's details.
 */
class Activator : public BundleActivator
{
private:
    /**
     * Implements BundleActivator::Start(). Prints a message and adds a member
     * function to the bundle context as a service listener.
     *
     * @param context the framework context for the bundle.
     */
    void Start(BundleContext context)
    {
        auto bundle = context.GetBundle();
        auto headers = bundle.GetHeaders();

        cppmicroservices::ServiceProperties props;

        props["VendorName"] = std::string("aubo-robotics");
        props["Version"] = 0;

        // 当节点服务类 (...NodeService) 的定义完成时，需要在激活器 (Activator)
        // 中注册此服务。 只有当节点服务类被成功注册, aubo_scope
        // 才能加载该节点。

        // 安装节点服务类的注册方法如下
        props["Name"] =
            std::string(typeid(JsonRpcTestInstallationNodeService).name());
        context.RegisterService<arcs::aubo_scope::InstallationNodeService>(
            std::make_shared<JsonRpcTestInstallationNodeService>(
                bundle.GetLocation()),
            props);

        // 程序节点服务类的注册方法如下
        props["Name"] =
            std::string(typeid(JsonRpcTestProgramNodeService).name());
        context.RegisterService<arcs::aubo_scope::ProgramNodeService>(
            std::make_shared<JsonRpcTestProgramNodeService>(), props);
    }

    /**
     * Implements BundleActivator::Stop(). Prints a message and removes the
     * member function from the bundle context as a service listener.
     *
     * @param context the framework context for the bundle.
     */
    void Stop(BundleContext /*context*/) {}
};

CPPMICROSERVICES_EXPORT_BUNDLE_ACTIVATOR(Activator)
