#ifndef TEST2_PROGRAM_NODE_VIEW_H
#define TEST2_PROGRAM_NODE_VIEW_H

#include <QWidget>
#include <aubo_caps/contribution/program/program_node_view.h>
#include <aubo_caps/contribution/view_api_provider.h>

namespace Ui {
class test2ProgramNodeView;
}

using namespace arcs::aubo_scope;
class test2ProgramNodeContribution;

class test2ProgramNodeView : public QWidget, public ProgramNodeView
{
    Q_OBJECT

public:
    test2ProgramNodeView(ViewApiProviderPtr api_provider, QWidget *parent = 0);
    ~test2ProgramNodeView();

    /// 构建界面 UI。
    void buildUi(
        WidgetHandle parent,
        ContributionProviderPtr<ProgramNodeContribution> contribution) override;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_6_clicked();

private:
    test2ProgramNodeContribution *contribution();

private:
    Ui::test2ProgramNodeView *ui;
    ViewApiProviderPtr view_api_{ nullptr };
    ContributionProviderPtr<ProgramNodeContribution> provider_{ nullptr };
};

#endif // TEST2_PROGRAM_NODE_VIEW_H
