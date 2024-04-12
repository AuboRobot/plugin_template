#ifndef TEST_INSTALLATION_NODE_H
#define TEST_INSTALLATION_NODE_H

#include <aubo_caps/contribution/installation/installation_node_contribution.h>
#include <aubo_caps/contribution/installation/installation_creation_context.h>
#include <aubo_caps/contribution/installation/installation_api_provider.h>
#include <aubo_caps/domain/installation/installation_api.h>
#include <aubo_caps/domain/data/data_model.h>
#include <aubo_caps++/meta_types.h>

using namespace arcs::aubo_scope;
ARCS_CLASS_FORWARD(testInstallationNodeView);

class testInstallationNode : public InstallationNodeContribution
{
public:
    testInstallationNode(InstallationApiProviderPtr api_provider,
                         testInstallationNodeViewPtr view, DataModelPtr model,
                         InstallationCreationContextPtr context);

    /// 当用户点击安装节点进入节点界面时，将调用 openView() 。
    void openView() override;

    /// 当用户离开节点界面时，将调用 closeView() 。
    void closeView() override;

    /// 运行或保存程序时将调用方法 generateScript() 生成 aubo_control 的可执行脚本。
    void generateScript(ScriptWriterPtr script_writer) override;

private:
    InstallationApiProviderPtr api_provider_{nullptr};
    testInstallationNodeViewPtr view_{nullptr};
    DataModelPtr model_{nullptr};
    InstallationCreationContextPtr context_{nullptr};

    DECLARE_ATTR(num1,double,0);
    DECLARE_ATTR(num2,double,0);
};

#endif // TEST_INSTALLATION_NODE_H
