#include "AST/Node/ASTRootNode.h"

#include "AST/ASTCApi.h"

extern "C" {
void* AST_ASTRootNodeConstructor()
{
    return static_cast<void*>(Cobalt::ASTASTRootNode::instance());
}

void* AST_AddASTRootNodeChildren(void* node)
{
    auto ptr = Cobalt::ASTASTRootNode::instance();
    ptr->children.emplace_back(static_cast<Cobalt::BaseASTNode*>(node));
    return ptr;
}
}