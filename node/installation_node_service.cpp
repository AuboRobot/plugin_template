#include "%{LOWER_NAME}_installation_node_service.h"
#include "%{LOWER_NAME}_installation_node.h"
#include "%{LOWER_NAME}_installation_node_view.h"

%{NodeName}InstallationNodeService::%{NodeName}InstallationNodeService()
{   
}

std::string %{NodeName}InstallationNodeService::getTitle()
{
    return "%{NodeName}";
}

std::string %{NodeName}InstallationNodeService::getIcon()
{
    return "icon:node-planes.png";
}

void %{NodeName}InstallationNodeService::configureContribution(
    InstallationContributionConfigurationPtr configuration)
{
}

InstallationNodeViewPtr %{NodeName}InstallationNodeService::createView(
    ViewApiProviderPtr api_provider)
{
    // 新建一个view类,避免关闭scope时,插件和scope对该view析构两次
    return std::shared_ptr<%{NodeName}InstallationNodeView>(
	new %{NodeName}InstallationNodeView(api_provider),[](auto) {});
}

InstallationNodeContributionPtr
%{NodeName}InstallationNodeService::createInstallationNode(
    InstallationApiProviderPtr api_provider, InstallationNodeViewPtr view,
    DataModelPtr model, InstallationCreationContextPtr context)
{
    return std::make_shared<%{NodeName}InstallationNode>(
        api_provider, std::dynamic_pointer_cast<%{NodeName}InstallationNodeView>(view),
        model, context);
}
