#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_EXPRNODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_EXPRNODE_H_

#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"
#include "AST/Node/BaseNode.h"

#include <cstring>
#include <ostream>
#include <string_view>
#include <vector>

namespace Cobalt {

struct ASTBinaryOpNode : ASTExprNode {
    using Operator = AST_BinaryOperatorType;
    [[nodiscard]] ASTNodeKind kind() const override { return NK_BinaryOp; }
    void dump(std::ostream& os) const override;
    ~ASTBinaryOpNode() override
    {
        delete &lhs;
        delete &rhs;
    }
    ASTBinaryOpNode(ASTExprNode& lhs_, Operator op_, ASTExprNode& rhs_, char* loc)
        : ASTExprNode(loc)
        , lhs(lhs_)
        , rhs(rhs_)
        , op(op_)
    {
    }
    void visitNext(BaseASTVisitor& v) override
    {
        v.visit(lhs);
        v.visit(rhs);
    }
    ASTExprNode &lhs, &rhs;
    const Operator op;
};

// TODO: Finish speclizer for LogicalOr and LogicalAnd
struct ASTLogicalOrNode : ASTBinaryOpNode { };
struct ASTLogicalAndNode : ASTBinaryOpNode { };

struct ASTUnaryOpNode : ASTExprNode {
    using Operator = AST_UnaryOperatorType;
    [[nodiscard]] ASTNodeKind kind() const override { return NK_UnaryOp; }
    void dump(std::ostream& os) const override;
    ASTUnaryOpNode(ASTExprNode& expr_, Operator op_, char* loc)
        : ASTExprNode(loc)
        , expr(expr_)
        , op(op_)
    {
    }
    ~ASTUnaryOpNode() override
    {
        delete &expr;
    }
    void visitNext(BaseASTVisitor& v) override { v.visit(expr); }
    ASTExprNode& expr;
    const Operator op;
};

struct ASTLHSNode : ASTExprNode {
    explicit ASTLHSNode(char* loc)
        : ASTExprNode(loc)
    {
    }
};

struct ASTAbstractAssignNode : ASTExprNode {
    explicit ASTAbstractAssignNode(char* loc)
        : ASTExprNode(loc)
    {
    }
};

struct ASTAssignNode : ASTAbstractAssignNode {
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Assign; }
    void dump(std::ostream& os) const override;
    ASTAssignNode(ASTLHSNode& lhs_, ASTExprNode& rhs_, char* loc)
        : ASTAbstractAssignNode(loc)
        , lhs(lhs_)
        , rhs(rhs_)
    {
    }
    ~ASTAssignNode() override
    {
        delete &lhs;
        delete &rhs;
    }
    void visitNext(BaseASTVisitor& v) override
    {
        v.visit(lhs);
        v.visit(rhs);
    }
    ASTLHSNode& lhs;
    ASTExprNode& rhs;
};

struct ASTOpAssignNode : ASTAbstractAssignNode {
    using Operator = AST_BinaryOperatorType;
    ASTOpAssignNode(ASTLHSNode& lhs_, Operator op_, ASTExprNode& rhs_, char* loc)
        : ASTAbstractAssignNode(loc)
        , lhs(lhs_)
        , op(op_)
        , rhs(rhs_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_OpAssign; }
    void dump(std::ostream& os) const override;
    ~ASTOpAssignNode() override
    {
        delete &lhs;
        delete &rhs;
    }
    void visitNext(BaseASTVisitor& v) override
    {
        v.visit(lhs);
        v.visit(rhs);
    }
    ASTLHSNode& lhs;
    const Operator op;
    ASTExprNode& rhs;
};

struct ASTAddressNode : ASTExprNode {
    ASTAddressNode(ASTExprNode& expr_, char* loc)
        : ASTExprNode(loc)
        , expr(expr_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Address; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { v.visit(expr); }
    ~ASTAddressNode() override
    {
        delete &expr;
    }
    ASTExprNode& expr;
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
    void dump(std::ostream& os) const override;
    ~ASTCondExprNode() override
    {
        delete &cond;
        delete &stmt1;
        delete &stmt2;
    }
    void visitNext(BaseASTVisitor& v) override
    {
        v.visit(cond);
        v.visit(stmt1);
        v.visit(stmt2);
    }
    ASTExprNode& cond;
    ASTStmtNode &stmt1, &stmt2;
};

struct ASTFuncCallNode : ASTExprNode {
    ASTFuncCallNode(char* func, char* loc)
        : ASTExprNode(loc)
        , name(func, strlen(func))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_FuncCall; }
    void dump(std::ostream& os) const override;
    ~ASTFuncCallNode() override
    {
        for (auto p : params)
            delete p;
    }
    void visitNext(BaseASTVisitor& v) override
    {
        for (auto p : params)
            v.visit(*p);
    }
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
    void dump(std::ostream& os) const override;
    ~ASTArraySubscriptNode() override
    {
        delete &array;
        delete &subscript;
    }
    void visitNext(BaseASTVisitor& v) override
    {
        v.visit(array);
        v.visit(subscript);
    }
    ASTExprNode& array;
    ASTExprNode& subscript;
};

struct ASTDereferenceNode : ASTLHSNode {
    ASTDereferenceNode(ASTExprNode& ptr_, char* loc)
        : ASTLHSNode(loc)
        , ptr(ptr_)
    {
    }
    ~ASTDereferenceNode() override { delete &ptr; }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Dereference; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { v.visit(ptr); }
    ASTExprNode& ptr;
};

struct ASTMemberNode : ASTLHSNode {
    ASTMemberNode(ASTExprNode& obj_, char* name, char* loc)
        : ASTLHSNode(loc)
        , obj(obj_)
        , member(name, strlen(name))
    {
    }
    ~ASTMemberNode() override { delete &obj; }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Member; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { v.visit(obj); }
    ASTExprNode& obj;
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
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { v.visit(obj); }
    ~ASTPtrMemberNode() override { delete &obj; }
    ASTExprNode& obj;
    const std::string_view member;
};

struct ASTVariableNode : ASTLHSNode {
    ASTVariableNode(char* name_, char* loc)
        : ASTLHSNode(loc)
        , name(name_, strlen(name_))
        , definition(nullptr)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Variable; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { }
    ~ASTVariableNode() override = default;
    const std::string_view name;
    ASTVariableDefinitionNode* definition;
};

struct ASTLiteralNode : ASTExprNode {
    explicit ASTLiteralNode(char* loc)
        : ASTExprNode(loc)
    {
    }
    ~ASTLiteralNode() override = default;
    void visitNext(BaseASTVisitor& v) override { }
};

struct ASTIntLiteralNode : ASTLiteralNode {
    ASTIntLiteralNode(char* raw_, char* loc)
        : ASTLiteralNode(loc)
        , raw(raw_, strlen(raw_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_IntLiteral; }
    void dump(std::ostream& os) const override;
    const std::string_view raw;
};

struct ASTStringLiteralNode : ASTLiteralNode {
    ASTStringLiteralNode(char* raw_, char* loc)
        : ASTLiteralNode(loc)
        , raw(raw_, strlen(raw_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_StringLiteral; }
    void dump(std::ostream& os) const override;
    const std::string_view raw;
};

struct ASTFloatLiteralNode : ASTLiteralNode {
    ASTFloatLiteralNode(char* raw_, char* loc)
        : ASTLiteralNode(loc)
        , raw(raw_, strlen(raw_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_FloatLiteral; }
    void dump(std::ostream& os) const override;
    const std::string_view raw;
};

struct ASTSizeofExprNode : ASTExprNode {
    ASTSizeofExprNode(ASTExprNode& expr_, char* loc)
        : ASTExprNode(loc)
        , expr(expr_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_SizeofExpr; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { v.visit(expr); }
    ~ASTSizeofExprNode() override { delete &expr; }
    ASTExprNode& expr;
};

struct ASTSizeofTypeNode : ASTExprNode {
    ASTSizeofTypeNode(ASTTypeNode& type_, char* loc)
        : ASTExprNode(loc)
        , type(type_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_SizeofType; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { v.visit(type); }
    ~ASTSizeofTypeNode() override { delete &type; }
    ASTTypeNode& type;
};

// TODO: UnaryArithmeticOperators
struct ASTUnaryArithmeticOpNode : ASTUnaryOpNode { };
struct ASTPrefixOpNode : ASTUnaryArithmeticOpNode { };
struct ASTSuffixOpNode : ASTUnaryArithmeticOpNode { };

// TODO: CastNode
struct ASTCastNode : ASTExprNode { };

}

#endif