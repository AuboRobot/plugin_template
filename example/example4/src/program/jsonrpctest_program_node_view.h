#ifndef JSONRPCTEST_PROGRAM_NODE_VIEW_H
#define JSONRPCTEST_PROGRAM_NODE_VIEW_H

#include <QWidget>
#include <aubo_caps/contribution/program/program_node_view.h>
#include <aubo_caps/contribution/view_api_provider.h>

namespace Ui {
class JsonRpcTestProgramNodeView;
}

using namespace arcs::aubo_scope;
class JsonRpcTestProgramNodeContribution;

class JsonRpcTestProgramNodeView : public QWidget, public ProgramNodeView
{
    Q_OBJECT

public:
    JsonRpcTestProgramNodeView(ViewApiProviderPtr api_provider, QWidget *parent = 0);
    ~JsonRpcTestProgramNodeView();

    /// 构建界面 UI。
    void buildUi(
            WidgetHandle parent,
            ContributionProviderPtr<ProgramNodeContribution> contribution) override;

private:
    JsonRpcTestProgramNodeContribution *contribution();

private:
    Ui::JsonRpcTestProgramNodeView *ui;
    ViewApiProviderPtr view_api_{ nullptr };
    ContributionProviderPtr<ProgramNodeContribution> provider_{ nullptr };
};

#endif // JSONRPCTEST_PROGRAM_NODE_VIEW_H
