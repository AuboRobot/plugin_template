#include "test_installation_node.h"

testInstallationNode::testInstallationNode(
        InstallationApiProviderPtr api_provider, testInstallationNodeViewPtr view,
        DataModelPtr model, InstallationCreationContextPtr context)
    : api_provider_(api_provider), view_(view), model_(model),context_(context)
{
    if (context_->getNodeCreationType() == InstallationCreationContext::NEW) {
        /// 以点击节点按钮的方式添加节点时进入此分支
    } else {
        /// 以加载 installation 文件的方式添加节点时进入此分支
    }
}

void testInstallationNode::openView()
{
}

void testInstallationNode::closeView()
{
}

void testInstallationNode::generateScript(ScriptWriterPtr script_writer)
{
    script_writer->appendLine(R"(
local function add(num1,num2)
    return num1 + num2
end
local function subtract(num1,num2)
    return num1 - num2
end
local function multiply(num1,num2)
    return num1 * num2
end
local function divide(num1,num2)
    return num1 / num2
end
)");
}
