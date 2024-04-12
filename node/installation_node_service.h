#ifndef %{UPPER_NAME}_INSTALLATION_NODE_SERVICE_H
#define %{UPPER_NAME}_INSTALLATION_NODE_SERVICE_H

#include <aubo_caps/contribution/installation/installation_node_service.h>

using namespace arcs::aubo_scope;

class %{NodeName}InstallationNodeService : public InstallationNodeService
{
public:
    %{NodeName}InstallationNodeService();

    /// 安装节点栏中显示的节点标题。
    std::string getTitle() override;

    /// 安装节点的图标。
    /// 法一: 通过资源文件 qrc 加载。
    /// 法二: 通过指定相对路径加载。
    std::string getIcon() override;

    /// 配置其允许的父/子节点的集合。
    void configureContribution(
        InstallationContributionConfigurationPtr configuration) override;

    /// 创建节点 view 类实例。
    InstallationNodeViewPtr createView(
        ViewApiProviderPtr api_provider) override;

    /// 创建节点 contribution 类实例。
    InstallationNodeContributionPtr createInstallationNode(
        InstallationApiProviderPtr api_provider, InstallationNodeViewPtr view,
        DataModelPtr model, InstallationCreationContextPtr context) override;

private:
};

#endif // %{UPPER_NAME}_INSTALLATION_NODE_SERVICE_H
