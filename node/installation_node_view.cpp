#include "%{LOWER_NAME}_installation_node_view.h"
#include "ui_%{LOWER_NAME}_installation_node_view.h"
#include "%{LOWER_NAME}_installation_node.h"

#include <QLayout>

%{NodeName}InstallationNodeView::%{NodeName}InstallationNodeView(
    ViewApiProviderPtr api_provider, QWidget *parent)
    : QWidget(parent), ui(new Ui::%{NodeName}InstallationNodeView),
      view_api_(api_provider)
{
}

%{NodeName}InstallationNodeView::~%{NodeName}InstallationNodeView()
{
    delete ui;
}

void %{NodeName}InstallationNodeView::buildUi(
    WidgetHandle parent, InstallationNodeContributionPtr contribution)
{
    ((QWidget *)parent)->layout()->addWidget(this);
    ui->setupUi(this);
    node_ = std::dynamic_pointer_cast<%{NodeName}InstallationNode>(contribution);
}
