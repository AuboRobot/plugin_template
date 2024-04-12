#include "jsonrpctest_installation_node_service.h"
#include "jsonrpctest_installation_node.h"
#include "jsonrpctest_installation_node_view.h"

JsonRpcTestInstallationNodeService::JsonRpcTestInstallationNodeService(
    const std::string &location)
    : location_(location)
{
}

std::string JsonRpcTestInstallationNodeService::getTitle()
{
    return "JsonRpcTest";
}

std::string JsonRpcTestInstallationNodeService::getIcon()
{
    return "icon:node-planes.png";
}

void JsonRpcTestInstallationNodeService::configureContribution(
    InstallationContributionConfigurationPtr configuration)
{
}

InstallationNodeViewPtr JsonRpcTestInstallationNodeService::createView(
    ViewApiProviderPtr api_provider)
{
    return std::make_shared<JsonRpcTestInstallationNodeView>(api_provider);
}

InstallationNodeContributionPtr
JsonRpcTestInstallationNodeService::createInstallationNode(
    InstallationApiProviderPtr api_provider, InstallationNodeViewPtr view,
    DataModelPtr model, InstallationCreationContextPtr context)
{
    return std::make_shared<JsonRpcTestInstallationNode>(
        api_provider,
        std::dynamic_pointer_cast<JsonRpcTestInstallationNodeView>(view), model,
        context, location_);
}
