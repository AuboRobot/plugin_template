#ifndef JSONRPCTEST_INSTALLATION_NODE_H
#define JSONRPCTEST_INSTALLATION_NODE_H

#include <aubo_caps/contribution/installation/installation_node_contribution.h>
#include <aubo_caps/contribution/installation/installation_creation_context.h>
#include <aubo_caps/contribution/installation/installation_api_provider.h>
#include <aubo_caps/domain/installation/installation_api.h>
#include <aubo_caps/domain/data/data_model.h>
#include <QProcess>

using namespace arcs::aubo_scope;
ARCS_CLASS_FORWARD(JsonRpcTestInstallationNodeView);

class JsonRpcTestInstallationNode : public InstallationNodeContribution
{
public:
    JsonRpcTestInstallationNode(InstallationApiProviderPtr api_provider,
                                JsonRpcTestInstallationNodeViewPtr view,
                                DataModelPtr model,
                                InstallationCreationContextPtr context,
                                const std::string &location);

    /// 当用户点击安装节点进入节点界面时，将调用 openView() 。
    void openView() override;

    /// 当用户离开节点界面时，将调用 closeView() 。
    void closeView() override;

    /// 运行或保存程序时将调用方法 generateScript() 生成 aubo_control
    /// 的可执行脚本。
    void generateScript(ScriptWriterPtr script_writer) override;

private:
    InstallationApiProviderPtr api_provider_{ nullptr };
    JsonRpcTestInstallationNodeViewPtr view_{ nullptr };
    DataModelPtr model_{ nullptr };
    InstallationCreationContextPtr context_{ nullptr };
    QProcess *user_server_;
};

#endif // JSONRPCTEST_INSTALLATION_NODE_H
