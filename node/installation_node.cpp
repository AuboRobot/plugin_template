#include "%{LOWER_NAME}_installation_node.h"

%{NodeName}InstallationNode::%{NodeName}InstallationNode(
    InstallationApiProviderPtr api_provider, %{NodeName}InstallationNodeViewPtr view,
    DataModelPtr model, InstallationCreationContextPtr context)
    : api_provider_(api_provider), view_(view), model_(model),context_(context)
{
    if (context_->getNodeCreationType() == InstallationCreationContext::NEW) {
        /// 以点击节点按钮的方式添加节点时进入此分支
    } else {
        /// 以加载 installation 文件的方式添加节点时进入此分支
    }
}

void %{NodeName}InstallationNode::openView()
{
}

void %{NodeName}InstallationNode::closeView()
{
}

void %{NodeName}InstallationNode::generateScript(ScriptWriterPtr script_writer)
{
}
