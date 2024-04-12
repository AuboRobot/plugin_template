#ifndef TEST_PROGRAM_NODE_VIEW_H
#define TEST_PROGRAM_NODE_VIEW_H

#include <QWidget>
#include <aubo_caps/contribution/program/program_node_view.h>
#include <aubo_caps/contribution/view_api_provider.h>
#include <QAbstractButton>

namespace Ui {
class testProgramNodeView;
}

using namespace arcs::aubo_scope;
class testProgramNodeContribution;

class testProgramNodeView : public QWidget, public ProgramNodeView
{
    Q_OBJECT

public:
    testProgramNodeView(ViewApiProviderPtr api_provider, QWidget *parent = 0);
    ~testProgramNodeView();

    /// 构建界面 UI。
    void buildUi(
            WidgetHandle parent,
            ContributionProviderPtr<ProgramNodeContribution> contribution) override;
    void openView();
    void getCaculateNums(int &index,double &num1,double &num2);

private:

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_checkBox_1_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

private:
    testProgramNodeContribution *contribution();

private:
    Ui::testProgramNodeView *ui;
    ViewApiProviderPtr view_api_{ nullptr };
    ContributionProviderPtr<ProgramNodeContribution> provider_{ nullptr };
};

#endif // TEST_PROGRAM_NODE_VIEW_H
