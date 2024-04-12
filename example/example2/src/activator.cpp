#include "cppmicroservices/Bundle.h"
#include "cppmicroservices/BundleActivator.h"
#include "cppmicroservices/BundleImport.h"
#include "cppmicroservices/BundleContext.h"
#include "cppmicroservices/BundleResource.h"
#include "cppmicroservices/BundleResourceStream.h"
#include "cppmicroservices/Constants.h"
#include "cppmicroservices/ServiceEvent.h"
#include "program/test2/test2_program_node_service.h"
#include "program/test2Child1/test2child1_program_node_service.h"
#include "program/test2Child2/test2child2_program_node_service.h"

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

        props["VendorName"] = std::string("MyCompany");
        props["Version"] = 0;

        // 当节点服务类 (...NodeService) 的定义完成时，需要在激活器 (Activator) 中注册此服务。
        // 只有当节点服务类被成功注册, aubo_scope 才能加载该节点。

        // 安装节点服务类的注册方法如下
//        props["Name"] = std::string(typeid(这里需要替换为安装节点node类的类名).name());
//        context.RegisterService<arcs::aubo_scope::InstallationNodeService>(
//            std::make_shared<...InstallationNodeService>(), props);

        // 程序节点服务类的注册方法如下
        props["Name"] = std::string(typeid(test2ProgramNodeService).name());
        context.RegisterService<arcs::aubo_scope::ProgramNodeService>(
            std::make_shared<test2ProgramNodeService>(), props);

        props["Name"] = std::string(typeid(test2Child1ProgramNodeService).name());
        context.RegisterService<arcs::aubo_scope::ProgramNodeService>(
            std::make_shared<test2Child1ProgramNodeService>(), props);

        props["Name"] = std::string(typeid(test2Child2ProgramNodeService).name());
        context.RegisterService<arcs::aubo_scope::ProgramNodeService>(
            std::make_shared<test2Child2ProgramNodeService>(), props);

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
