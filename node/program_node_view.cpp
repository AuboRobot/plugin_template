#include "%{LOWER_NAME}_program_node_view.h"
#include "./ui_%{LOWER_NAME}_program_node_view.h"
#include "%{LOWER_NAME}_program_node_contribution.h"

#include <QLayout>

%{NodeName}ProgramNodeView::%{NodeName}ProgramNodeView(ViewApiProviderPtr api_provider,
                                       QWidget *parent)
    : QWidget(parent), ui(new Ui::%{NodeName}ProgramNodeView), view_api_(api_provider)
{
}

%{NodeName}ProgramNodeView::~%{NodeName}ProgramNodeView()
{
    delete ui;
}

void %{NodeName}ProgramNodeView::buildUi(
    WidgetHandle parent,
    ContributionProviderPtr<ProgramNodeContribution> contribution)
{
    provider_ = contribution;
    ((QWidget *)parent)->layout()->addWidget(this);
    ui->setupUi(this);
}

%{NodeName}ProgramNodeContribution *%{NodeName}ProgramNodeView::contribution()
{
    return dynamic_cast<%{NodeName}ProgramNodeContribution *>(provider_->get());
}
