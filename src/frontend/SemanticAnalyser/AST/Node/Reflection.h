#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_REFLECTION_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_REFLECTION_H_

#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"

namespace Cobalt {

inline bool isExprNode(BaseASTNode* ptr)
{
    auto k = ptr->kind();
    return static_cast<int>(NK_Expr) <= static_cast<int>(k) && static_cast<int>(k) < static_cast<int>(NK_Expr_END_TAG);
}

inline bool isStmtNode(BaseASTNode* ptr)
{
    auto k = ptr->kind();
    return static_cast<int>(NK_Stmt) <= static_cast<int>(k) && static_cast<int>(k) <= static_cast<int>(NK_Stmt_END_TAG);
}

inline constexpr const char* binaryOperatorToString(AST_BinaryOperatorType p)
{
    switch (p) {
    case AST_AddOp:
        return "AddOp";
    case AST_SubOp:
        return "SubOp";
    case AST_TimesOp:
        return "TimesOp";
    case AST_DivOp:
        return "DivOp";
    case AST_ModOp:
        return "ModOp";
    case AST_GEQOp:
        return "GEQOp";
    case AST_GreaterOp:
        return "GreaterOp";
    case AST_LEQOp:
        return "LEQOp";
    case AST_LessOp:
        return "LessOp";
    case AST_EqualOp:
        return "EqualOp";
    case AST_NEqualOp:
        return "NEqualOp";
    case AST_BitAndOp:
        return "BitAndOp";
    case AST_BitOrOp:
        return "BitOrOp";
    case AST_BitXorOp:
        return "BitXorOp";
    case AST_LShiftOp:
        return "LShiftOp";
    case AST_RShiftOp:
        return "RShiftOp";
    case AST_LogicalAndOp:
        return "LogicalAndOp";
    case AST_LogicalOrOp:
        return "LogicalOrOp";
    }
}

inline constexpr const char* unaryOperatorToString(AST_UnaryOperatorType p)
{
    switch (p) {
    case AST_IncOp:
        return "IncOp";
    case AST_DecOp:
        return "DecOp";
    case AST_CompleOp:
        return "CompleOp";
    }
}

}

#endif