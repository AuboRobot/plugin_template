#include "%{LOWER_NAME}_program_node_service.h"
#include "%{LOWER_NAME}_program_node_view.h"

%{NodeName}ProgramNodeService::%{NodeName}ProgramNodeService()
{
}

%{NodeName}ProgramNodeService::~%{NodeName}ProgramNodeService()
{
}

std::string %{NodeName}ProgramNodeService::getId()
{
    return "%{NodeName}";
}

std::string %{NodeName}ProgramNodeService::getTitle()
{
    return "%{NodeName}";
}

std::string %{NodeName}ProgramNodeService::getIcon()
{
    return "img:node-comment.png";
}

void %{NodeName}ProgramNodeService::configureContribution(
    ProgramContributionConfigurationPtr configuration)
{
}

ProgramNodeViewPtr %{NodeName}ProgramNodeService::createView(
    ViewApiProviderPtr api_provider)
{
    // 新建一个view类,避免关闭scope时,插件和scope对该view析构两次
    return std::shared_ptr<%{NodeName}ProgramNodeView>(
	new %{NodeName}ProgramNodeView(api_provider),[](auto) {});
}

ProgramNodeContributionPtr %{NodeName}ProgramNodeService::createNode(
    ProgramApiProviderPtr api_provider, ProgramNodeViewPtr view,
    DataModelPtr model, ProgramCreationContextPtr context)
{
    return std::make_shared<%{NodeName}ProgramNodeContribution>(
        api_provider, std::dynamic_pointer_cast<%{NodeName}ProgramNodeView>(view),
        model, context);
}
