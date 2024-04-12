#include "test2child1_program_node_contribution.h"

#include <aubo_caps/domain/script/script_writer.h>

test2Child1ProgramNodeContribution::test2Child1ProgramNodeContribution(
    ProgramApiProviderPtr api_provider, test2Child1ProgramNodeViewPtr view,
    DataModelPtr model, ProgramCreationContextPtr context)
    : api_provider_(api_provider), view_(view), model_(model), context_(context)
{
    programModel_ = api_provider_->getProgramApi()->getProgramModel();

    if (context->getNodeCreationType() == ProgramCreationContext::NEW) {
        /// 以点击节点按钮的方式添加节点时进入此分支
    } else {
        /// 以加载 program 文件的方式添加节点时进入此分支
    }
}

test2Child1ProgramNodeContribution::~test2Child1ProgramNodeContribution()
{
}

void test2Child1ProgramNodeContribution::openView()
{
}

void test2Child1ProgramNodeContribution::closeView()
{
}

std::string test2Child1ProgramNodeContribution::getTitle()
{
    return "test2Child1";
}

bool test2Child1ProgramNodeContribution::isDefined()
{
    return true;
}

void test2Child1ProgramNodeContribution::generateScript(
    ScriptWriterPtr script_writer)
{
}
