#ifndef TEST_INSTALLATION_NODE_VIEW_H
#define TEST_INSTALLATION_NODE_VIEW_H

#include <QWidget>

#include <aubo_caps/contribution/installation/installation_node_view.h>
#include <aubo_caps/contribution/view_api_provider.h>

ARCS_CLASS_FORWARD(testInstallationNode);
namespace Ui {
class testInstallationNodeView;
}

using namespace arcs::aubo_scope;
class QTreeWidgetItem;

class testInstallationNodeView : public QWidget, public InstallationNodeView
{
    Q_OBJECT

public:
    testInstallationNodeView(ViewApiProviderPtr api_provider,
                             QWidget *parent = 0);
    ~testInstallationNodeView();

    /// 构建界面 UI。
    void buildUi(WidgetHandle parent,
                 InstallationNodeContributionPtr contribution) override;

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::testInstallationNodeView *ui{ nullptr };
    ViewApiProviderPtr view_api_{ nullptr };
    testInstallationNodePtr node_{ nullptr };
};

#endif // TEST_INSTALLATION_NODE_VIEW_H
