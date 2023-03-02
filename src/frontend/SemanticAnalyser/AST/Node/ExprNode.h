#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_EXPRNODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_EXPRNODE_H_

#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"
#include "AST/Node/BaseNode.h"

#include "magic_enum.hpp"

#include <cstring>
#include <ostream>
#include <string_view>
#include <vector>

namespace Cobalt {

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
    ASTBinaryOpNode(ASTExprNode& lhs_, Operator op_, ASTExprNode& rhs_, char* loc)
        : ASTExprNode(loc)
        , lhs(lhs_)
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
    ASTUnaryOpNode(ASTExprNode& expr_, Operator op_, char* loc)
        : ASTExprNode(loc)
        , expr(expr_)
        , op(op_)
    {
    }
    const ASTExprNode& expr;
    const Operator op;
};

struct ASTLHSNode : ASTExprNode {
    explicit ASTLHSNode(char* loc)
        : ASTExprNode(loc)
    {
    }
};

struct ASTAssignNode : ASTExprNode {
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Assign; }
    void dump(std::ostream& os) const override
    {
        lhs.dump(os);
        os << " = ";
        rhs.dump(os);
    }
    ASTAssignNode(ASTLHSNode& lhs_, ASTExprNode& rhs_, char* loc)
        : ASTExprNode(loc)
        , lhs(lhs_)
        , rhs(rhs_)
    {
    }
    const ASTLHSNode& lhs;
    const ASTExprNode& rhs;
};

struct ASTOpAssignNode : ASTExprNode {
    using Operator = AST_BinaryOperatorType;
    ASTOpAssignNode(ASTLHSNode& lhs_, Operator op_, ASTExprNode& rhs_, char* loc)
        : ASTExprNode(loc)
        , lhs(lhs_)
        , op(op_)
        , rhs(rhs_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_OpAssign; }
    void dump(std::ostream& os) const override
    {
        lhs.dump(os);
        os << magic_enum::enum_name(op) << "= ";
        rhs.dump(os);
    }
    const ASTLHSNode& lhs;
    const Operator op;
    const ASTExprNode& rhs;
};

struct ASTAddressNode : ASTExprNode {
    ASTAddressNode(ASTExprNode& expr_, char* loc)
        : ASTExprNode(loc)
        , expr(expr_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Address; }
    void dump(std::ostream& os) const override
    {
        os << "&";
        expr.dump(os);
    }
    const ASTExprNode& expr;
};

struct ASTCondExprNode : ASTExprNode {
    ASTCondExprNode(ASTExprNode& cond_, ASTStmtNode& stmt1_, ASTStmtNode& stmt2_, char* loc)
        : ASTExprNode(loc)
        , cond(cond_)
        , stmt1(stmt1_)
        , stmt2(stmt2_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_CondExpr; }
    void dump(std::ostream& os) const override
    {
        cond.dump(os);
        os << "?";
        stmt1.dump(os);
        os << ":";
        stmt2.dump(os);
    }
    const ASTExprNode& cond;
    const ASTStmtNode &stmt1, &stmt2;
};

struct ASTFuncCallNode : ASTExprNode {
    ASTFuncCallNode(char* func, char* loc)
        : ASTExprNode(loc)
        , name(func, strlen(func))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_FuncCall; }
    void dump(std::ostream& os) const override { os << name; }
    const std::string_view name;
    std::vector<ASTFuncParameterNode*> params;
};

struct ASTArraySubscriptNode : ASTLHSNode {
    ASTArraySubscriptNode(ASTExprNode& array_, ASTExprNode& subscript_, char* loc)
        : ASTLHSNode(loc)
        , array(array_)
        , subscript(subscript_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_ArraySubscript; }
    void dump(std::ostream& os) const override
    {
        array.dump(os);
        subscript.dump(os);
    }
    const ASTExprNode& array;
    const ASTExprNode& subscript;
};

struct ASTDereferenceNode : ASTLHSNode {
    ASTDereferenceNode(ASTExprNode& ptr_, char* loc)
        : ASTLHSNode(loc)
        , ptr(ptr_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Dereference; }
    void dump(std::ostream& os) const override
    {
        os << "&";
        ptr.dump(os);
    }
    const ASTExprNode& ptr;
};

struct ASTMemberNode : ASTLHSNode {
    ASTMemberNode(ASTExprNode& obj_, char* name, char* loc)
        : ASTLHSNode(loc)
        , obj(obj_)
        , member(name, strlen(name))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Member; }
    void dump(std::ostream& os) const override
    {
        obj.dump(os);
        os << member;
    }
    const ASTExprNode& obj;
    const std::string_view member;
};

struct ASTPtrMemberNode : ASTLHSNode {
    ASTPtrMemberNode(ASTExprNode& obj_, char* name, char* loc)
        : ASTLHSNode(loc)
        , obj(obj_)
        , member(name, strlen(name))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Member; }
    void dump(std::ostream& os) const override
    {
        obj.dump(os);
        os << member;
    }
    const ASTExprNode& obj;
    const std::string_view member;
};

struct ASTVariableNode : ASTLHSNode {
    ASTVariableNode(char* name_, char* loc)
        : ASTLHSNode(loc)
        , name(name_, strlen(name_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Variable; }
    void dump(std::ostream& os) const override { os << name; }
    const std::string_view name;
};

struct ASTLiteralNode : ASTExprNode {
    explicit ASTLiteralNode(char* loc)
        : ASTExprNode(loc)
    {
    }
};

struct ASTIntLiteralNode : ASTLiteralNode {
    ASTIntLiteralNode(char* raw_, char* loc)
        : ASTLiteralNode(loc)
        , raw(raw_, strlen(raw_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_IntLiteral; }
    void dump(std::ostream& os) const override { os << raw; }
    const std::string_view raw;
};

struct ASTStringLiteralNode : ASTLiteralNode {
    ASTStringLiteralNode(char* raw_, char* loc)
        : ASTLiteralNode(loc)
        , raw(raw_, strlen(raw_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_StringLiteral; }
    void dump(std::ostream& os) const override { os << raw; }
    const std::string_view raw;
};

struct ASTFloatLiteralNode : ASTLiteralNode {
    ASTFloatLiteralNode(char* raw_, char* loc)
        : ASTLiteralNode(loc)
        , raw(raw_, strlen(raw_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_FloatLiteral; }
    void dump(std::ostream& os) const override { os << raw; }
    const std::string_view raw;
};

struct ASTSizeofExprNode : ASTExprNode {
    ASTSizeofExprNode(ASTExprNode& expr_, char* loc)
        : ASTExprNode(loc)
        , expr(expr_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_SizeofExpr; }
    void dump(std::ostream& os) const override { expr.dump(os); }
    const ASTExprNode& expr;
};

struct ASTSizeofTypeNode : ASTExprNode {
    ASTSizeofTypeNode(ASTTypeNode& type_, char* loc)
        : ASTExprNode(loc)
        , type(type_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_SizeofType; }
    void dump(std::ostream& os) const override { type.dump(os); }
    const ASTTypeNode& type;
};

struct ASTUnaryArithmeticOpNode : ASTUnaryOpNode { };
struct ASTPrefixOpNode : ASTUnaryArithmeticOpNode { };
struct ASTSuffixOpNode : ASTUnaryArithmeticOpNode { };

}

#endif