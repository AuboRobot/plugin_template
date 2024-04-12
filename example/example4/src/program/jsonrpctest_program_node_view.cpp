#include "jsonrpctest_program_node_view.h"
#include "./ui_jsonrpctest_program_node_view.h"
#include "jsonrpctest_program_node_contribution.h"

#include <QLayout>

JsonRpcTestProgramNodeView::JsonRpcTestProgramNodeView(ViewApiProviderPtr api_provider,
                                                       QWidget *parent)
    : QWidget(parent), ui(new Ui::JsonRpcTestProgramNodeView), view_api_(api_provider)
{
}

JsonRpcTestProgramNodeView::~JsonRpcTestProgramNodeView()
{
    delete ui;
}

void JsonRpcTestProgramNodeView::buildUi(
        WidgetHandle parent,
        ContributionProviderPtr<ProgramNodeContribution> contribution)
{
    provider_ = contribution;
    ((QWidget *)parent)->layout()->addWidget(this);
    ui->setupUi(this);
}

JsonRpcTestProgramNodeContribution *JsonRpcTestProgramNodeView::contribution()
{
    return dynamic_cast<JsonRpcTestProgramNodeContribution *>(provider_->get());
}
