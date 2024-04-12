#include "test2child1_program_node_view.h"
#include "./ui_test2child1_program_node_view.h"
#include "test2child1_program_node_contribution.h"

#include <QLayout>

test2Child1ProgramNodeView::test2Child1ProgramNodeView(
    ViewApiProviderPtr api_provider, QWidget *parent)
    : QWidget(parent), ui(new Ui::test2Child1ProgramNodeView),
      view_api_(api_provider)
{
}

test2Child1ProgramNodeView::~test2Child1ProgramNodeView()
{
    delete ui;
}

void test2Child1ProgramNodeView::buildUi(
    WidgetHandle parent,
    ContributionProviderPtr<ProgramNodeContribution> contribution)
{
    provider_ = contribution;
    ((QWidget *)parent)->layout()->addWidget(this);
    ui->setupUi(this);
}

test2Child1ProgramNodeContribution *test2Child1ProgramNodeView::contribution()
{
    return dynamic_cast<test2Child1ProgramNodeContribution *>(provider_->get());
}
