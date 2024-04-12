#ifndef %{UPPER_NAME}_INSTALLATION_NODE_VIEW_H
#define %{UPPER_NAME}_INSTALLATION_NODE_VIEW_H

#include <QWidget>

#include <aubo_caps/contribution/installation/installation_node_view.h>
#include <aubo_caps/contribution/view_api_provider.h>

ARCS_CLASS_FORWARD(%{NodeName}InstallationNode);
namespace Ui {
class %{NodeName}InstallationNodeView;
}

using namespace arcs::aubo_scope;
class QTreeWidgetItem;

class %{NodeName}InstallationNodeView : public QWidget, public InstallationNodeView
{
    Q_OBJECT

public:
    %{NodeName}InstallationNodeView(ViewApiProviderPtr api_provider,
                            QWidget *parent = 0);
    ~%{NodeName}InstallationNodeView();

   /// 构建界面 UI。
    void buildUi(WidgetHandle parent,
                 InstallationNodeContributionPtr contribution) override;

private slots:

private:
    Ui::%{NodeName}InstallationNodeView *ui{ nullptr };
    ViewApiProviderPtr view_api_{ nullptr };
    %{NodeName}InstallationNodePtr node_{ nullptr };
};

#endif // %{UPPER_NAME}_INSTALLATION_NODE_VIEW_H
