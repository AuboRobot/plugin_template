#ifndef TEST2CHILD1_PROGRAM_NODE_VIEW_H
#define TEST2CHILD1_PROGRAM_NODE_VIEW_H

#include <QWidget>
#include <aubo_caps/contribution/program/program_node_view.h>
#include <aubo_caps/contribution/view_api_provider.h>

namespace Ui {
class test2Child1ProgramNodeView;
}

using namespace arcs::aubo_scope;
class test2Child1ProgramNodeContribution;

class test2Child1ProgramNodeView : public QWidget, public ProgramNodeView
{
    Q_OBJECT

public:
    test2Child1ProgramNodeView(ViewApiProviderPtr api_provider,
                               QWidget *parent = 0);
    ~test2Child1ProgramNodeView();

    /// 构建界面 UI。
    void buildUi(
        WidgetHandle parent,
        ContributionProviderPtr<ProgramNodeContribution> contribution) override;

private:
    test2Child1ProgramNodeContribution *contribution();

private:
    Ui::test2Child1ProgramNodeView *ui;
    ViewApiProviderPtr view_api_{ nullptr };
    ContributionProviderPtr<ProgramNodeContribution> provider_{ nullptr };
};

#endif // TEST2CHILD1_PROGRAM_NODE_VIEW_H
