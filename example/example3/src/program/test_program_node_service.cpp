#include "test_program_node_service.h"
#include "test_program_node_view.h"

testProgramNodeService::testProgramNodeService()
{
}

testProgramNodeService::~testProgramNodeService()
{
}

std::string testProgramNodeService::getId()
{
    return "test";
}

std::string testProgramNodeService::getTitle()
{
    return "test";
}

std::string testProgramNodeService::getIcon()
{
    return "img:node-comment.png";
}

void testProgramNodeService::configureContribution(
        ProgramContributionConfigurationPtr configuration)
{
}

ProgramNodeViewPtr testProgramNodeService::createView(
        ViewApiProviderPtr api_provider)
{
    // 新建一个view类,避免关闭scope时,插件和scope对该view析构两次
    return std::shared_ptr<testProgramNodeView>(
                new testProgramNodeView(api_provider),[](auto) {});
}

ProgramNodeContributionPtr testProgramNodeService::createNode(
        ProgramApiProviderPtr api_provider, ProgramNodeViewPtr view,
        DataModelPtr model, ProgramCreationContextPtr context)
{
    return std::make_shared<testProgramNodeContribution>(
                api_provider, std::dynamic_pointer_cast<testProgramNodeView>(view),
                model, context);
}
