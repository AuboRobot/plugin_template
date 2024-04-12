#include "test2child2_program_node_service.h"
#include "test2child2_program_node_view.h"

test2Child2ProgramNodeService::test2Child2ProgramNodeService()
{
}

test2Child2ProgramNodeService::~test2Child2ProgramNodeService()
{
}

std::string test2Child2ProgramNodeService::getId()
{
    return "test2Child2";
}

std::string test2Child2ProgramNodeService::getTitle()
{
    return "test2Child2";
}

std::string test2Child2ProgramNodeService::getIcon()
{
    return "img:node-comment.png";
}

void test2Child2ProgramNodeService::configureContribution(
    ProgramContributionConfigurationPtr configuration)
{
    configuration->setUserInsertable(false);
}

ProgramNodeViewPtr test2Child2ProgramNodeService::createView(
    ViewApiProviderPtr api_provider)
{
    // 新建一个view类,避免关闭scope时,插件和scope对该view析构两次
    return std::shared_ptr<test2Child2ProgramNodeView>(
        new test2Child2ProgramNodeView(api_provider),[](auto) {});
}

ProgramNodeContributionPtr test2Child2ProgramNodeService::createNode(
    ProgramApiProviderPtr api_provider, ProgramNodeViewPtr view,
    DataModelPtr model, ProgramCreationContextPtr context)
{
    return std::make_shared<test2Child2ProgramNodeContribution>(
        api_provider, std::dynamic_pointer_cast<test2Child2ProgramNodeView>(view),
        model, context);
}
