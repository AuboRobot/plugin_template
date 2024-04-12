#ifndef TEST2CHILD2_PROGRAM_NODE_SERVICE_H
#define TEST2CHILD2_PROGRAM_NODE_SERVICE_H

#include <aubo_caps/contribution/program/program_node_service.h>
#include "test2child2_program_node_contribution.h"
#include "test2child2_program_node_view.h"

using namespace arcs::aubo_scope;

class test2Child2ProgramNodeService : public ProgramNodeService
{
public:
    test2Child2ProgramNodeService();
    ~test2Child2ProgramNodeService();

    /// aubo_scope 加载节点时的唯一标识。
    std::string getId() override;

    /// 程序节点的标题（ 显示在 aubo_scope 左下方程序节点按钮栏 ）。
    std::string getTitle() override;

    /// 程序节点的图标（ 显示在 aubo_scope 左下方程序节点按钮栏 ）。
    std::string getIcon() override;

    /// 配置其允许的父/子节点的集合。
    void configureContribution(
        ProgramContributionConfigurationPtr configuration) override;

    /// 创建节点 view 类实例。
    ProgramNodeViewPtr createView(ViewApiProviderPtr api_provider) override;

    /// 创建节点 contribution 类实例。
    ProgramNodeContributionPtr createNode(
        ProgramApiProviderPtr api_provider, ProgramNodeViewPtr view,
        DataModelPtr model, ProgramCreationContextPtr context) override;
};

#endif // TEST2CHILD2_PROGRAM_NODE_SERVICE_H
