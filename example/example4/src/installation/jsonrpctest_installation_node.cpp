#include "jsonrpctest_installation_node.h"
#include <QDir>
#include <QDebug>

JsonRpcTestInstallationNode::JsonRpcTestInstallationNode(
    InstallationApiProviderPtr api_provider,
    JsonRpcTestInstallationNodeViewPtr view, DataModelPtr model,
    InstallationCreationContextPtr context, const std::string &location)
    : api_provider_(api_provider), view_(view), model_(model), context_(context)
{
    if (context_->getNodeCreationType() == InstallationCreationContext::NEW) {
        /// 以点击节点按钮的方式添加节点时进入此分支
    } else {
        /// 以加载 installation 文件的方式添加节点时进入此分支
    }

    user_server_ = new QProcess();

    // FIXME: 找到正确的加载路径
    auto dir = QDir(location.c_str());
    dir.cd("..");

    user_server_->setProgram(QString("%1/user_service").arg(dir.path()));
    user_server_->setArguments(QStringList() << QString::number(8988));
    QObject::connect(user_server_, &QProcess::stateChanged,
                     [](QProcess::ProcessState newState) {
                         //
                     });
    QObject::connect(user_server_, &QProcess::errorOccurred,
                     [](QProcess::ProcessError error) {
                         //
                     });

    // 启动用户服务端
    user_server_->start();
}

void JsonRpcTestInstallationNode::openView()
{
}

void JsonRpcTestInstallationNode::closeView()
{
}

void JsonRpcTestInstallationNode::generateScript(ScriptWriterPtr script_writer)
{
    // 连接到服务端
    script_writer->appendLine(
        QString(
            "local api = sched.jsonrpc.proxy('http://127.0.0.1:%1/jsonrpc')")
            .arg(8988)
            .toStdString());
}
