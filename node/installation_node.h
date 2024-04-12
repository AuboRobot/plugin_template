#ifndef %{UPPER_NAME}_INSTALLATION_NODE_H
#define %{UPPER_NAME}_INSTALLATION_NODE_H

#include <aubo_caps/contribution/installation/installation_node_contribution.h>
#include <aubo_caps/contribution/installation/installation_creation_context.h>
#include <aubo_caps/contribution/installation/installation_api_provider.h>
#include <aubo_caps/domain/installation/installation_api.h>
#include <aubo_caps/domain/data/data_model.h>

using namespace arcs::aubo_scope;
ARCS_CLASS_FORWARD(%{NodeName}InstallationNodeView);

class %{NodeName}InstallationNode : public InstallationNodeContribution
{
public:
    %{NodeName}InstallationNode(InstallationApiProviderPtr api_provider,
                        %{NodeName}InstallationNodeViewPtr view, DataModelPtr model,
                        InstallationCreationContextPtr context);

    /// 当用户点击安装节点进入节点界面时，将调用 openView() 。
    void openView() override;

    /// 当用户离开节点界面时，将调用 closeView() 。
    void closeView() override;

    /// 运行或保存程序时将调用方法 generateScript() 生成 aubo_control 的可执行脚本。
    void generateScript(ScriptWriterPtr script_writer) override;

private:
    InstallationApiProviderPtr api_provider_{nullptr};
    %{NodeName}InstallationNodeViewPtr view_{nullptr};
    DataModelPtr model_{nullptr};
    InstallationCreationContextPtr context_{nullptr};
};

#endif // %{UPPER_NAME}_INSTALLATION_NODE_H
