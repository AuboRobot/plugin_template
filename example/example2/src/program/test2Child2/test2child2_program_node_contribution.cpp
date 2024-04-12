#include "test2child2_program_node_contribution.h"

#include <aubo_caps/domain/script/script_writer.h>

test2Child2ProgramNodeContribution::test2Child2ProgramNodeContribution(
    ProgramApiProviderPtr api_provider, test2Child2ProgramNodeViewPtr view,
    DataModelPtr model, ProgramCreationContextPtr context)
    : api_provider_(api_provider), view_(view), model_(model), context_(context)
{
    if (context->getNodeCreationType() == ProgramCreationContext::NEW) {
        /// 以点击节点按钮的方式添加节点时进入此分支
    } else {
        /// 以加载 program 文件的方式添加节点时进入此分支
    }
}

test2Child2ProgramNodeContribution::~test2Child2ProgramNodeContribution()
{
}

void test2Child2ProgramNodeContribution::openView()
{
}

void test2Child2ProgramNodeContribution::closeView()
{
}

std::string test2Child2ProgramNodeContribution::getTitle()
{
    return "test2Child2";
}

bool test2Child2ProgramNodeContribution::isDefined()
{
    return true;
}

void test2Child2ProgramNodeContribution::generateScript(ScriptWriterPtr script_writer)
{
}

int test2Child2ProgramNodeContribution::getNum()
{
    return 1;
}
