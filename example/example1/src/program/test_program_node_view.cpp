#include "test_program_node_view.h"
#include "./ui_test_program_node_view.h"
#include "test_program_node_contribution.h"

#include <QLayout>
#include <QDebug>

testProgramNodeView::testProgramNodeView(ViewApiProviderPtr api_provider,
                                         QWidget *parent)
    : QWidget(parent), ui(new Ui::testProgramNodeView), view_api_(api_provider)
{
}

testProgramNodeView::~testProgramNodeView()
{
    delete ui;
}

void testProgramNodeView::buildUi(
    WidgetHandle parent,
    ContributionProviderPtr<ProgramNodeContribution> contribution)
{
    provider_ = contribution;
    ((QWidget *)parent)->layout()->addWidget(this);
    ui->setupUi(this);

    // 注册键盘
    auto keyboard_manager = view_api_->getUserInterfaceApi()
                                ->getUserInteraction()
                                ->getKeyboardManager();
    auto les = ui->widget->findChildren<QLineEdit *>();
    for (auto le : les) {
        keyboard_manager->registerDoubleKeyboard(
            le, [=]() -> std::string { return le->text().toStdString(); },
            std::make_shared<DoubleRangeValidator>(
                [=]() -> std::pair<double, double> {
                    return { -5.00, 5.00 };
                }),
            [=](const std::string &text) { le->setText(text.c_str()); });
        le->installEventFilter(this);
    }
}

void testProgramNodeView::openView()
{
    ui->lineEdit->setText(QString::number(contribution()->get_num1()));
    ui->lineEdit_2->setText(QString::number(contribution()->get_num2()));

    switch (contribution()->get_button()) {
    case 0:
        ui->checkBox_1->setChecked(true);
        break;
    case 1:
        ui->checkBox_2->setChecked(true);
        break;
    case 2:
        ui->checkBox_3->setChecked(true);
        break;
    case 3:
        ui->checkBox_4->setChecked(true);
        break;
    }
}

void testProgramNodeView::getCaculateNums(int &index, double &num1,
                                          double &num2)
{
    num1 = ui->lineEdit->text().toDouble();
    num2 = ui->lineEdit_2->text().toDouble();
    if (ui->checkBox_1->isChecked()) {
        index = 0;
    } else if (ui->checkBox_2->isChecked()) {
        index = 1;
    } else if (ui->checkBox_3->isChecked()) {
        index = 2;
    } else if (ui->checkBox_4->isChecked()) {
        index = 3;
    } else {
        index = -1;
        num1 = 0;
        num2 = 0;
    }
}

testProgramNodeContribution *testProgramNodeView::contribution()
{
    return dynamic_cast<testProgramNodeContribution *>(provider_->get());
}

void testProgramNodeView::on_lineEdit_textChanged(const QString &arg1)
{
    contribution()->setNum1(arg1.toDouble());
}

void testProgramNodeView::on_lineEdit_2_textChanged(const QString &arg1)
{
    contribution()->setNum2(arg1.toDouble());
}

void testProgramNodeView::on_checkBox_1_clicked()
{
    contribution()->setButton(0);
}

void testProgramNodeView::on_checkBox_2_clicked()
{
    contribution()->setButton(1);
}

void testProgramNodeView::on_checkBox_3_clicked()
{
    contribution()->setButton(2);
}

void testProgramNodeView::on_checkBox_4_clicked()
{
    contribution()->setButton(3);
}
