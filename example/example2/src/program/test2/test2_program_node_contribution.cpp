#include "test2_program_node_contribution.h"

#include <aubo_caps/domain/script/script_writer.h>
#include <QDebug>

test2ProgramNodeContribution::test2ProgramNodeContribution(
    ProgramApiProviderPtr api_provider, test2ProgramNodeViewPtr view,
    DataModelPtr model, ProgramCreationContextPtr context)
    : api_provider_(api_provider), view_(view), model_(model), context_(context)
{
    programModel_ = api_provider_->getProgramApi()->getProgramModel();
    nf_ = programModel_->getProgramNodeFactory();

    if (context->getNodeCreationType() == ProgramCreationContext::NEW) {
        /// 以点击节点按钮的方式添加节点时进入此分支
    } else {
        /// 以加载 program 文件的方式添加节点时进入此分支
    }
}

test2ProgramNodeContribution::~test2ProgramNodeContribution()
{
}

void test2ProgramNodeContribution::openView()
{
}

void test2ProgramNodeContribution::closeView()
{
}

std::string test2ProgramNodeContribution::getTitle()
{
    return "test2";
}

bool test2ProgramNodeContribution::isDefined()
{
    return true;
}

void test2ProgramNodeContribution::generateScript(ScriptWriterPtr script_writer)
{
}

void test2ProgramNodeContribution::addChild()
{
    auto root = programModel_->getTreeNode(this);
    auto child1 = nf_->createUserProgramNode(
        typeid(test2Child1ProgramNodeService).name());
    root->addChild(child1);
}

void test2ProgramNodeContribution::addChildBefore()
{
    auto root = programModel_->getTreeNode(this);
    auto children = root->getChildren();
    if (children.size() >= 1) {
        auto child2 = nf_->createUserProgramNode(
            typeid(test2Child2ProgramNodeService).name());
        root->insertChildBefore(children[0], child2);
        // 未进行智能指针转换的情况下只能调用到ProgramNodeContribution中的函数
        child2->getProgramNodeContribution()->getTitle();
        // 进行智能指针转换后可以调用到自定义函数
        std::dynamic_pointer_cast<test2Child2ProgramNodeContribution>(
            child2->getProgramNodeContribution())
            ->getNum();
        // 通过程序树也可以找到对应的节点并调用对应的自定义函数
        std::dynamic_pointer_cast<test2Child2ProgramNodeContribution>(
            children[0]->getProgramNode()->getProgramNodeContribution())
            ->getNum();
        /* 在调用该接口节点的子节点中通过programnode获取到对应的treenode
         getProgramNode:           treenode->programnode
         locateDescendantTreeNode: programnode->treenode*/
        // root->locateDescendantTreeNode();
    }
}

void test2ProgramNodeContribution::addChildAfter()
{
    auto root = programModel_->getTreeNode(this);
    auto children = root->getChildren();
    if (children.size() >= 1) {
        auto child2 = nf_->createUserProgramNode(
            typeid(test2Child2ProgramNodeService).name());
        root->insertChildAfter(children[children.size() - 1], child2);
    }
}

void test2ProgramNodeContribution::firstToLast()
{
    auto root = programModel_->getTreeNode(this);
    auto children = root->getChildren();
    if (children.size() >= 1) {
        auto first = root->cutChildNode(children[0]);
        root->insertChildAfter(children[children.size() - 1],
                               first->getProgramNode());
    }
}

void test2ProgramNodeContribution::removeFirst()
{
    auto root = programModel_->getTreeNode(this);
    auto children = root->getChildren();
    if (children.size() >= 1) {
        root->removeChild(children[0]);
    }
}

void test2ProgramNodeContribution::squenceLock(bool lock)
{
    // 节点在scope中无法上下移动
    auto root = programModel_->getTreeNode(this);
    root->setChildSequenceLocked(lock);
}

QStringList test2ProgramNodeContribution::getnames()
{
    auto root = programModel_->getTreeNode(this);
    QStringList names;
    root->traverse([&](ProgramNodePtr node, int index, int) -> int {
        Q_UNUSED(index)
        names.push_back(node->getProgramNodeContribution()->getTitle().data());
        return 0;
    });
    return names;
}
