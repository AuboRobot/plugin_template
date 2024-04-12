#ifndef %{UPPER_NAME}_PROGRAM_NODE_VIEW_H
#define %{UPPER_NAME}_PROGRAM_NODE_VIEW_H

#include <QWidget>
#include <aubo_caps/contribution/program/program_node_view.h>
#include <aubo_caps/contribution/view_api_provider.h>

namespace Ui {
class %{NodeName}ProgramNodeView;
}

using namespace arcs::aubo_scope;
class %{NodeName}ProgramNodeContribution;

class %{NodeName}ProgramNodeView : public QWidget, public ProgramNodeView
{
    Q_OBJECT

public:
    %{NodeName}ProgramNodeView(ViewApiProviderPtr api_provider, QWidget *parent = 0);
    ~%{NodeName}ProgramNodeView();

    /// 构建界面 UI。
    void buildUi(
        WidgetHandle parent,
        ContributionProviderPtr<ProgramNodeContribution> contribution) override;

private:
    %{NodeName}ProgramNodeContribution *contribution();

private:
    Ui::%{NodeName}ProgramNodeView *ui;
    ViewApiProviderPtr view_api_{ nullptr };
    ContributionProviderPtr<ProgramNodeContribution> provider_{ nullptr };
};

#endif // %{UPPER_NAME}_PROGRAM_NODE_VIEW_H
