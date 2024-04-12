#include "jsonrpctest_program_node_service.h"
#include "jsonrpctest_program_node_view.h"

JsonRpcTestProgramNodeService::JsonRpcTestProgramNodeService()
{
}

JsonRpcTestProgramNodeService::~JsonRpcTestProgramNodeService()
{
}

std::string JsonRpcTestProgramNodeService::getId()
{
    return "JsonRpcTest";
}

std::string JsonRpcTestProgramNodeService::getTitle()
{
    return "JsonRpcTest";
}

std::string JsonRpcTestProgramNodeService::getIcon()
{
    return "img:node-comment.png";
}

void JsonRpcTestProgramNodeService::configureContribution(
        ProgramContributionConfigurationPtr configuration)
{
}

ProgramNodeViewPtr JsonRpcTestProgramNodeService::createView(
        ViewApiProviderPtr api_provider)
{
    return std::make_shared<JsonRpcTestProgramNodeView>(api_provider);
}

ProgramNodeContributionPtr JsonRpcTestProgramNodeService::createNode(
        ProgramApiProviderPtr api_provider, ProgramNodeViewPtr view,
        DataModelPtr model, ProgramCreationContextPtr context)
{
    return std::make_shared<JsonRpcTestProgramNodeContribution>(
                api_provider, std::dynamic_pointer_cast<JsonRpcTestProgramNodeView>(view),
                model, context);
}
