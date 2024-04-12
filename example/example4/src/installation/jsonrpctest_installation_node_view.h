#ifndef JSONRPCTEST_INSTALLATION_NODE_VIEW_H
#define JSONRPCTEST_INSTALLATION_NODE_VIEW_H

#include <QWidget>

#include <aubo_caps/contribution/installation/installation_node_view.h>
#include <aubo_caps/contribution/view_api_provider.h>

ARCS_CLASS_FORWARD(JsonRpcTestInstallationNode);
namespace Ui {
class JsonRpcTestInstallationNodeView;
}

using namespace arcs::aubo_scope;
class QTreeWidgetItem;

class JsonRpcTestInstallationNodeView : public QWidget, public InstallationNodeView
{
    Q_OBJECT

public:
    JsonRpcTestInstallationNodeView(ViewApiProviderPtr api_provider,
                                    QWidget *parent = 0);
    ~JsonRpcTestInstallationNodeView();

    /// 构建界面 UI。
    void buildUi(WidgetHandle parent,
                 InstallationNodeContributionPtr contribution) override;

private slots:

private:
    Ui::JsonRpcTestInstallationNodeView *ui{ nullptr };
    ViewApiProviderPtr view_api_{ nullptr };
    JsonRpcTestInstallationNodePtr node_{ nullptr };
};

#endif // JSONRPCTEST_INSTALLATION_NODE_VIEW_H
