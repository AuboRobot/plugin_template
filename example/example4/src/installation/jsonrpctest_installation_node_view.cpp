#include "jsonrpctest_installation_node_view.h"
#include "ui_jsonrpctest_installation_node_view.h"
#include "jsonrpctest_installation_node.h"

#include <QLayout>

JsonRpcTestInstallationNodeView::JsonRpcTestInstallationNodeView(
        ViewApiProviderPtr api_provider, QWidget *parent)
    : QWidget(parent), ui(new Ui::JsonRpcTestInstallationNodeView),
      view_api_(api_provider)
{
}

JsonRpcTestInstallationNodeView::~JsonRpcTestInstallationNodeView()
{
    delete ui;
}

void JsonRpcTestInstallationNodeView::buildUi(
        WidgetHandle parent, InstallationNodeContributionPtr contribution)
{
    ((QWidget *)parent)->layout()->addWidget(this);
    ui->setupUi(this);
    node_ = std::dynamic_pointer_cast<JsonRpcTestInstallationNode>(contribution);
}
