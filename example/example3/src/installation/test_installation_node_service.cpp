#include "test_installation_node_service.h"
#include "test_installation_node.h"
#include "test_installation_node_view.h"

testInstallationNodeService::testInstallationNodeService()
{
}

std::string testInstallationNodeService::getTitle()
{
    return "test";
}

std::string testInstallationNodeService::getIcon()
{
    return "icon:node-planes.png";
}

void testInstallationNodeService::configureContribution(
        InstallationContributionConfigurationPtr configuration)
{
}

InstallationNodeViewPtr testInstallationNodeService::createView(
        ViewApiProviderPtr api_provider)
{
    // 新建一个view类,避免关闭scope时,插件和scope对该view析构两次
    return std::shared_ptr<testInstallationNodeView>(
                new testInstallationNodeView(api_provider),[](auto) {});
}

InstallationNodeContributionPtr
testInstallationNodeService::createInstallationNode(
        InstallationApiProviderPtr api_provider, InstallationNodeViewPtr view,
        DataModelPtr model, InstallationCreationContextPtr context)
{
    return std::make_shared<testInstallationNode>(
                api_provider, std::dynamic_pointer_cast<testInstallationNodeView>(view),
                model, context);
}
