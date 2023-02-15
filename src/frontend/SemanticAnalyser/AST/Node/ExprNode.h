#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_EXPRNODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_EXPRNODE_H_

#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"

#include "magic_enum.hpp"

#include <ostream>

namespace Cobalt {

struct ASTExprNode : BaseASTNode { };

struct ASTBinaryOpNode : ASTExprNode {
    using Operator = AST_BinaryOperatorType;
    [[nodiscard]] ASTNodeKind kind() const override { return NK_BinaryOp; }
    void dump(std::ostream& os) const override
    {
        lhs.dump(os);
        os << ' ' << magic_enum::enum_name(op) << ' ';
        rhs.dump(os);
        os << std::endl;
    }
    ASTBinaryOpNode(ASTExprNode& lhs_, Operator op_, ASTExprNode& rhs_)
        : lhs(lhs_)
        , rhs(rhs_)
        , op(op_)
    {
    }
    const ASTExprNode &lhs, &rhs;
    const Operator op;
};

struct ASTLogicalOrNode : ASTBinaryOpNode { };
struct ASTLogicalAndNode : ASTBinaryOpNode { };

struct ASTUnaryOpNode : ASTExprNode {
    using Operator = AST_UnaryOperatorType;
    [[nodiscard]] ASTNodeKind kind() const override { return NK_UnaryOp; }
    void dump(std::ostream& os) const override
    {
        os << magic_enum::enum_name(op) << ' ';
        expr.dump(os);
        os << std::endl;
    }
    ASTUnaryOpNode(ASTExprNode& expr_, Operator op_)
        : expr(expr_)
        , op(op_)
    {
    }
    const ASTExprNode& expr;
    const Operator op;
};

}

#endif