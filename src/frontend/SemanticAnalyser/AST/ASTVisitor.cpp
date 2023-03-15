#include "AST/ASTVisitor.h"
#include "AST/Node/ASTRootNode.h"
#include "AST/Node/BaseNode.h"
#include "AST/Node/ExprNode.h"
#include "AST/Node/StmtNode.h"
#include "AST/Node/TypeNode.h"
#include <iostream>

namespace Cobalt {

namespace detail {
    void stmtNodeDefaultVisitImpl(ASTStmtNode& p, BaseASTVisitor& v)
    {
        switch (p.kind()) {
#define ADD_NODE_KIND(name)                        \
    case NK_##name: {                              \
        v.visit(static_cast<AST##name##Node&>(p)); \
        break;                                     \
    }
#define ADD_STMT_NODE
#define END_NODE_KIND(x)
#include "AST/Node/StmtNode.inc"
#undef ADD_NODE_KIND
#undef END_NODE_KIND
        default:
            break;
        }
    }
    void exprNodeDefaultVisitImpl(ASTExprNode& expr, BaseASTVisitor& v)
    {
        switch (expr.kind()) {
#define ADD_NODE_KIND(name)                             \
    case NK_##name: {                                   \
        v.visit(*static_cast<AST##name##Node*>(&expr)); \
        break;                                          \
    }
#define ADD_EXPR_NODE
#define END_NODE_KIND(x)
#include "AST/Node/ExprNode.inc"
#undef END_NODE_KIND
#undef ADD_NODE_KIND
        default:
            break;
        }
    }
}

#define ADD_NODE_KIND(name)                        \
    void BaseASTVisitor::visit(AST##name##Node& v) \
    {                                              \
        v.visitNext(*this);                        \
    }

#define ADD_STMT_NODE                               \
    void BaseASTVisitor::visit(ASTStmtNode& v)      \
    {                                               \
        detail::stmtNodeDefaultVisitImpl(v, *this); \
    }

#define ADD_EXPR_NODE                                  \
    void BaseASTVisitor::visit(ASTExprNode& expr)      \
    {                                                  \
        detail::exprNodeDefaultVisitImpl(expr, *this); \
    }
#include "AST/Node/ASTNode.inc"
#undef ADD_NODE_KIND
}