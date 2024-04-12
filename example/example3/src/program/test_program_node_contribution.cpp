#include "test_program_node_contribution.h"

#include <aubo_caps/domain/script/script_writer.h>

testProgramNodeContribution::testProgramNodeContribution(
    ProgramApiProviderPtr api_provider, testProgramNodeViewPtr view,
    DataModelPtr model, ProgramCreationContextPtr context)
    : api_provider_(api_provider), view_(view), model_(model), context_(context)
{
    if (context->getNodeCreationType() == ProgramCreationContext::NEW) {
        /// 以点击节点按钮的方式添加节点时进入此分支
    } else {
        /// 以加载 program 文件的方式添加节点时进入此分支
    }
}

testProgramNodeContribution::~testProgramNodeContribution()
{
}

void testProgramNodeContribution::openView()
{
    view_->openView();
}

void testProgramNodeContribution::closeView()
{
}

std::string testProgramNodeContribution::getTitle()
{
    return "test";
}

bool testProgramNodeContribution::isDefined()
{
    return true;
}

void testProgramNodeContribution::generateScript(ScriptWriterPtr script_writer)
{
    int index = -1;
    double num1;
    double num2;
    view_->getCaculateNums(index, num1, num2);
    switch (index) {
    case -1:
        return;
    case 0:
        script_writer->appendLine(QString("result = algorithm:add(%1,%2)")
                                      .arg(num1)
                                      .arg(num2)
                                      .toStdString());
        break;
    case 1:
        script_writer->appendLine(QString("result = algorithm:sub(%1,%2)")
                                      .arg(num1)
                                      .arg(num2)
                                      .toStdString());
        break;
    case 2:
        script_writer->appendLine(QString("result = algorithm:mul(%1,%2)")
                                      .arg(num1)
                                      .arg(num2)
                                      .toStdString());
        break;
    case 3:
        script_writer->appendLine(QString("result = algorithm:div(%1,%2)")
                                      .arg(num1)
                                      .arg(num2)
                                      .toStdString());
        break;
    }
    script_writer->appendLine("textmsg(result)");
}
