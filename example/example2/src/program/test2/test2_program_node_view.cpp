#include "test2_program_node_view.h"
#include "./ui_test2_program_node_view.h"
#include "test2_program_node_contribution.h"

#include <QLayout>

test2ProgramNodeView::test2ProgramNodeView(ViewApiProviderPtr api_provider,
                                           QWidget *parent)
    : QWidget(parent), ui(new Ui::test2ProgramNodeView), view_api_(api_provider)
{
}

test2ProgramNodeView::~test2ProgramNodeView()
{
    delete ui;
}

void test2ProgramNodeView::buildUi(
    WidgetHandle parent,
    ContributionProviderPtr<ProgramNodeContribution> contribution)
{
    provider_ = contribution;
    ((QWidget *)parent)->layout()->addWidget(this);
    ui->setupUi(this);
}

test2ProgramNodeContribution *test2ProgramNodeView::contribution()
{
    return dynamic_cast<test2ProgramNodeContribution *>(provider_->get());
}

void test2ProgramNodeView::on_pushButton_clicked()
{
    contribution()->addChild();
}

void test2ProgramNodeView::on_pushButton_2_clicked()
{
    contribution()->addChildBefore();
}

void test2ProgramNodeView::on_pushButton_3_clicked()
{
    contribution()->addChildAfter();
}

void test2ProgramNodeView::on_pushButton_4_clicked()
{
    contribution()->firstToLast();
}

void test2ProgramNodeView::on_pushButton_5_clicked()
{
    contribution()->removeFirst();
}

void test2ProgramNodeView::on_checkBox_stateChanged(int arg1)
{
    contribution()->squenceLock(arg1);
}

void test2ProgramNodeView::on_pushButton_6_clicked()
{
    auto names = contribution()->getnames();
    ui->comboBox->clear();
    ui->comboBox->addItems(names);
}
