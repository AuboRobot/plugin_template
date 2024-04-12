#include "jsonrpctest_program_node_contribution.h"

#include <aubo_caps/domain/script/script_writer.h>

JsonRpcTestProgramNodeContribution::JsonRpcTestProgramNodeContribution(
    ProgramApiProviderPtr api_provider, JsonRpcTestProgramNodeViewPtr view,
    DataModelPtr model, ProgramCreationContextPtr context)
    : api_provider_(api_provider), view_(view), model_(model), context_(context)
{
    if (context->getNodeCreationType() == ProgramCreationContext::NEW) {
        /// 以点击节点按钮的方式添加节点时进入此分支
    } else {
        /// 以加载 program 文件的方式添加节点时进入此分支
    }
}

JsonRpcTestProgramNodeContribution::~JsonRpcTestProgramNodeContribution()
{
}

void JsonRpcTestProgramNodeContribution::openView()
{
}

void JsonRpcTestProgramNodeContribution::closeView()
{
}

std::string JsonRpcTestProgramNodeContribution::getTitle()
{
    return "JsonRpcTest";
}

bool JsonRpcTestProgramNodeContribution::isDefined()
{
    return true;
}

void JsonRpcTestProgramNodeContribution::generateScript(
    ScriptWriterPtr script_writer)
{
    // 测试调用外部接口
    script_writer->appendLine("local result = api.testFunction()");
    // 打印获取到的结果
    script_writer->appendLine("textmsg(result)");
}
