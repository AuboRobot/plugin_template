#include "test2child1_program_node_service.h"
#include "test2child1_program_node_view.h"

test2Child1ProgramNodeService::test2Child1ProgramNodeService()
{
}

test2Child1ProgramNodeService::~test2Child1ProgramNodeService()
{
}

std::string test2Child1ProgramNodeService::getId()
{
    return "test2Child1";
}

std::string test2Child1ProgramNodeService::getTitle()
{
    return "test2Child1";
}

std::string test2Child1ProgramNodeService::getIcon()
{
    return "img:node-comment.png";
}

void test2Child1ProgramNodeService::configureContribution(
    ProgramContributionConfigurationPtr configuration)
{
    // 设置在编程界面用户不可以通过点击左下角节点来添加节点(在该处不显示)
    configuration->setUserInsertable(false);
    configuration->setChildrenAllowed(false);
    // 设置该节点的子节点不可添加其他节点
    configuration->setChildrenAllowedOnly(std::vector<std::string>{ "" });
}

ProgramNodeViewPtr test2Child1ProgramNodeService::createView(
    ViewApiProviderPtr api_provider)
{
    // 新建一个view类,避免关闭scope时,插件和scope对该view析构两次
    return std::shared_ptr<test2Child1ProgramNodeView>(
        new test2Child1ProgramNodeView(api_provider), [](auto) {});
}

ProgramNodeContributionPtr test2Child1ProgramNodeService::createNode(
    ProgramApiProviderPtr api_provider, ProgramNodeViewPtr view,
    DataModelPtr model, ProgramCreationContextPtr context)
{
    return std::make_shared<test2Child1ProgramNodeContribution>(
        api_provider,
        std::dynamic_pointer_cast<test2Child1ProgramNodeView>(view), model,
        context);
}
