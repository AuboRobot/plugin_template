#include "test_installation_node_view.h"
#include "ui_test_installation_node_view.h"
#include "test_installation_node.h"

#include <QLayout>
#include <QDebug>

testInstallationNodeView::testInstallationNodeView(
        ViewApiProviderPtr api_provider, QWidget *parent)
    : QWidget(parent), ui(new Ui::testInstallationNodeView),
      view_api_(api_provider)
{
}

testInstallationNodeView::~testInstallationNodeView()
{
    delete ui;
}

void testInstallationNodeView::buildUi(
        WidgetHandle parent, InstallationNodeContributionPtr contribution)
{
    ((QWidget *)parent)->layout()->addWidget(this);
    ui->setupUi(this);
    node_ = std::dynamic_pointer_cast<testInstallationNode>(contribution);

    auto keyboard_manager = view_api_->getUserInterfaceApi()
                                ->getUserInteraction()
                                ->getKeyboardManager();
    auto les = ui->widget->findChildren<QLineEdit *>();
    for(auto le:les){
        keyboard_manager->registerDoubleKeyboard(
            le,[=]() -> std::string { return le->text().toStdString(); },
            std::make_shared<DoubleRangeValidator>(
                [=]() -> std::pair<double, double> {
                    return { -5.00, 5.00 };
                }),
            [=](const std::string &text) {
                le->setText(text.c_str());
            });
        le->installEventFilter(this);
    }

    ui->lineEdit->setText(QString::number(node_->get_num1()));
    ui->lineEdit_2->setText(QString::number(node_->get_num2()));
}

void testInstallationNodeView::on_pushButton_clicked()
{
    auto num1 = ui->lineEdit->text().toDouble();
    auto num2 = ui->lineEdit_2->text().toDouble();
    auto num3 = num1 + num2;
    ui->label_9->setText(QString::number(num3));
}

void testInstallationNodeView::on_pushButton_2_clicked()
{
    auto num1 = ui->lineEdit_3->text().toDouble();
    auto num2 = ui->lineEdit_4->text().toDouble();
    auto num3 = num1 - num2;
    ui->label_10->setText(QString::number(num3));
}

void testInstallationNodeView::on_pushButton_3_clicked()
{
    auto num1 = ui->lineEdit_5->text().toDouble();
    auto num2 = ui->lineEdit_6->text().toDouble();
    auto num3 = num1 * num2;
    ui->label_11->setText(QString::number(num3));
}

void testInstallationNodeView::on_pushButton_4_clicked()
{
    auto num1 = ui->lineEdit_7->text().toDouble();
    auto num2 = ui->lineEdit_8->text().toDouble();
    auto num3 = (double)num1 / num2;
    ui->label_12->setText(QString::number(num3));
}

void testInstallationNodeView::on_lineEdit_textChanged(const QString &arg1)
{
    node_->set_num1(arg1.toDouble());
}

void testInstallationNodeView::on_lineEdit_2_textChanged(const QString &arg1)
{
    node_->set_num2(arg1.toDouble());
}
