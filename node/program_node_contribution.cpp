#include "%{LOWER_NAME}_program_node_contribution.h"

#include <aubo_caps/domain/script/script_writer.h>

%{NodeName}ProgramNodeContribution::%{NodeName}ProgramNodeContribution(
    ProgramApiProviderPtr api_provider, %{NodeName}ProgramNodeViewPtr view,
    DataModelPtr model, ProgramCreationContextPtr context)
    : api_provider_(api_provider), view_(view), model_(model), context_(context)
{
    if (context->getNodeCreationType() == ProgramCreationContext::NEW) {
        /// 以点击节点按钮的方式添加节点时进入此分支
    } else {
        /// 以加载 program 文件的方式添加节点时进入此分支
    }
}

%{NodeName}ProgramNodeContribution::~%{NodeName}ProgramNodeContribution()
{
}

void %{NodeName}ProgramNodeContribution::openView()
{
}

void %{NodeName}ProgramNodeContribution::closeView()
{
}

std::string %{NodeName}ProgramNodeContribution::getTitle()
{
    return "%{NodeName}";
}

bool %{NodeName}ProgramNodeContribution::isDefined()
{
    return true;
}

void %{NodeName}ProgramNodeContribution::generateScript(ScriptWriterPtr script_writer)
{
}
