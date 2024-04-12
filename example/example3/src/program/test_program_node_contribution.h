#ifndef TEST_PROGRAM_NODE_CONTRIBUTION_H
#define TEST_PROGRAM_NODE_CONTRIBUTION_H

#include <aubo_caps/contribution/program/program_node_contribution.h>
#include <aubo_caps/contribution/program/program_api_provider.h>
#include <aubo_caps/domain/data/data_model.h>
#include <aubo_caps++/meta_types.h>

#include "test_program_node_view.h"

using namespace arcs::aubo_scope;

ARCS_CLASS_FORWARD(testProgramNodeView);

class testProgramNodeContribution : public ProgramNodeContribution
{
public:
    testProgramNodeContribution(ProgramApiProviderPtr api_provider,
                                testProgramNodeViewPtr view, DataModelPtr model,
                                ProgramCreationContextPtr context);
    ~testProgramNodeContribution();

    /// 当用户点击程序节点进入节点界面时，将调用 openView() 。
    void openView() override;

    /// 当用户离开节点界面时，将调用 closeView() 。
    void closeView() override;

    /// 程序树上显示的该节点的标题。
    std::string getTitle() override;

    /// 判断节点是否已完成定义（未完成定义 aubo_scope 将无法运行程序）。
    bool isDefined() override;

    /// 运行或保存程序时将调用方法 generateScript() 生成 aubo_control 的可执行脚本。
    void generateScript(ScriptWriterPtr script_writer) override;

private:
    ProgramApiProviderPtr api_provider_ {nullptr};
    testProgramNodeViewPtr view_ {nullptr};
    DataModelPtr model_ {nullptr};
    ProgramCreationContextPtr context_{nullptr};

    DECLARE_ATTR(num1,double,0);
    DECLARE_ATTR(num2,double,0);
    DECLARE_ATTR(button,int,0);
};

#endif // TEST_PROGRAM_NODE_CONTRIBUTION_H
