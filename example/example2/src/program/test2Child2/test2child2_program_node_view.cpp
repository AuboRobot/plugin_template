#include "test2child2_program_node_view.h"
#include "./ui_test2child2_program_node_view.h"
#include "test2child2_program_node_contribution.h"

#include <QLayout>

test2Child2ProgramNodeView::test2Child2ProgramNodeView(ViewApiProviderPtr api_provider,
                                                       QWidget *parent)
    : QWidget(parent), ui(new Ui::test2Child2ProgramNodeView), view_api_(api_provider)
{
}

test2Child2ProgramNodeView::~test2Child2ProgramNodeView()
{
    delete ui;
}

void test2Child2ProgramNodeView::buildUi(
    WidgetHandle parent,
    ContributionProviderPtr<ProgramNodeContribution> contribution)
{
    provider_ = contribution;
    ((QWidget *)parent)->layout()->addWidget(this);
    ui->setupUi(this);
}

test2Child2ProgramNodeContribution *test2Child2ProgramNodeView::contribution()
{
    return dynamic_cast<test2Child2ProgramNodeContribution *>(provider_->get());
}
