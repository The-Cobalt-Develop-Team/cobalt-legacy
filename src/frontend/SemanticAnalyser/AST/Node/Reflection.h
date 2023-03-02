#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_REFLECTION_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_REFLECTION_H_

#include "AST/ASTNode.h"

namespace Cobalt {

constexpr bool isExprNode(BaseASTNode* ptr)
{
    auto k = ptr->kind();
    return static_cast<int>(NK_Expr) <= static_cast<int>(k) && static_cast<int>(k) < static_cast<int>(NK_Expr_END_TAG);
}

constexpr bool isStmtNode(BaseASTNode* ptr)
{
    auto k = ptr->kind();
    return static_cast<int>(NK_Stmt) <= static_cast<int>(k) && static_cast<int>(k) <= static_cast<int>(NK_Stmt_END_TAG);
}

}

#endif