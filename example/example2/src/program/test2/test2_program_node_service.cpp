#include "test2_program_node_service.h"
#include "test2_program_node_view.h"

test2ProgramNodeService::test2ProgramNodeService()
{
}

test2ProgramNodeService::~test2ProgramNodeService()
{
}

std::string test2ProgramNodeService::getId()
{
    return "test2";
}

std::string test2ProgramNodeService::getTitle()
{
    return "test2";
}

std::string test2ProgramNodeService::getIcon()
{
    return "img:node-comment.png";
}

void test2ProgramNodeService::configureContribution(
    ProgramContributionConfigurationPtr configuration)
{
    configuration->setChildrenAllowed(false);
    configuration->setChildrenAllowedOnly(std::vector<std::string>{ "" });
}

ProgramNodeViewPtr test2ProgramNodeService::createView(
    ViewApiProviderPtr api_provider)
{
    // 新建一个view类,避免关闭scope时,插件和scope对该view析构两次
    return std::shared_ptr<test2ProgramNodeView>(
        new test2ProgramNodeView(api_provider), [](auto) {});
}

ProgramNodeContributionPtr test2ProgramNodeService::createNode(
    ProgramApiProviderPtr api_provider, ProgramNodeViewPtr view,
    DataModelPtr model, ProgramCreationContextPtr context)
{
    return std::make_shared<test2ProgramNodeContribution>(
        api_provider, std::dynamic_pointer_cast<test2ProgramNodeView>(view),
        model, context);
}
