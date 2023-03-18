#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_STMTNODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_STMTNODE_H_

#include "AST/ASTNode.h"
#include "AST/ASTVisitor.h"
#include "AST/Node/BaseNode.h"

#include <cstring>
#include <ostream>
#include <stdexcept>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace Cobalt {

struct ASTBlockNode : ASTStmtNode {
    explicit ASTBlockNode(char* loc)
        : ASTStmtNode(loc)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Block; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override;
    ~ASTBlockNode() override
    {
        for (auto p : stmts)
            delete p;
    }
    std::vector<ASTStmtNode*> stmts;
};

struct ASTBreakNode : ASTStmtNode {
    explicit ASTBreakNode(char* loc)
        : ASTStmtNode(loc)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Break; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor&) override { }
};

struct ASTContinueNode : ASTStmtNode {
    explicit ASTContinueNode(char* loc)
        : ASTStmtNode(loc)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Continue; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor&) override { }
};

// TODO: Redesign Switch and Case
struct ASTCaseNode : ASTStmtNode {
    explicit ASTCaseNode(char* name, ASTStmtNode& stmt_, char* loc)
        : ASTStmtNode(loc)
        , label(name)
        , stmt(stmt_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Case; }
    void dump(std::ostream& os) const override;
    const std::string_view label;
    ASTStmtNode& stmt;
    void visitNext(BaseASTVisitor& v) override { }
};

struct ASTDoWhileNode : ASTStmtNode {
    ASTDoWhileNode(ASTExprNode& c, ASTStmtNode& s, char* loc)
        : ASTStmtNode(loc)
        , cond(c)
        , stmt(s)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_DoWhile; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override
    {
        v.visit(cond);
        v.visit(stmt);
    }
    ~ASTDoWhileNode() override
    {
        delete &cond;
        delete &stmt;
    }
    ASTExprNode& cond;
    ASTStmtNode& stmt;
};

struct ASTWhileNode : ASTStmtNode {
    ASTWhileNode(ASTExprNode& c, ASTStmtNode& s, char* loc)
        : ASTStmtNode(loc)
        , cond(c)
        , stmt(s)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_While; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override
    {
        v.visit(cond);
        v.visit(stmt);
    }
    ASTExprNode& cond;
    ASTStmtNode& stmt;
};

struct ASTForNode : ASTStmtNode {
    ASTForNode(ASTStmtNode& init_, ASTExprNode& cond_, ASTStmtNode& mod_, ASTStmtNode& body_, char* loc)
        : ASTStmtNode(loc)
        , init(init_)
        , cond(cond_)
        , mod(mod_)
        , body(body_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_For; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override
    {
        v.visit(init);
        v.visit(cond);
        v.visit(mod);
        v.visit(body);
    }
    ~ASTForNode() override
    {
        delete &init;
        delete &cond;
        delete &mod;
        delete &body;
    }
    ASTStmtNode& init;
    ASTExprNode& cond;
    ASTStmtNode& mod;
    ASTStmtNode& body;
};

struct ASTGotoNode : ASTStmtNode {
    ASTGotoNode(char* label_, char* loc)
        : ASTStmtNode(loc)
        , label(label_, strlen(label_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Goto; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { }
    const std::string_view label;
};

struct ASTExprStmtNode : ASTStmtNode {
    ASTExprStmtNode(ASTExprNode& expr_, char* loc)
        : ASTStmtNode(loc)
        , expr(expr_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_ExprStmt; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override;
    ~ASTExprStmtNode() override { delete &expr; }
    ASTExprNode& expr;
};

struct ASTIfNode : ASTStmtNode {
    ASTIfNode(ASTExprNode& cond_, ASTStmtNode& body_, char* loc)
        : ASTStmtNode(loc)
        , cond(cond_)
        , body(body_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_If; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override
    {
        v.visit(cond);
        v.visit(body);
    }
    ~ASTIfNode() override
    {
        delete &cond;
        delete &body;
    }
    ASTExprNode& cond;
    ASTStmtNode& body;
};

struct ASTLabelNode : ASTStmtNode {
    ASTLabelNode(char* name_, char* loc)
        : ASTStmtNode(loc)
        , name(name_, strlen(name_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Label; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { }
    const std::string_view name;
};

struct ASTReturnNode : ASTStmtNode {
    ASTReturnNode(ASTExprNode& expr_, char* loc)
        : ASTStmtNode(loc)
        , expr(expr_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Return; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { v.visit(expr); }
    ~ASTReturnNode() override { delete &expr; }
    ASTExprNode& expr;
};

// TODO: Redesign
struct ASTSwitchNode : ASTStmtNode {
    ASTSwitchNode(ASTExprNode& state_, char* loc)
        : ASTStmtNode(loc)
        , state(state_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Switch; }
    void dump(std::ostream& os) const override;
    const ASTExprNode& state;
    std::unordered_map<std::string_view, ASTStmtNode*> bodies;
    void visitNext(BaseASTVisitor& v) override { }
};

struct ASTVariableDefinitionNode : ASTStmtNode {
    ASTVariableDefinitionNode(char* type_, char* name_, ASTExprNode* init_, char* loc)
        : ASTStmtNode(loc)
        , type(type_, strlen(type_))
        , name(name_, strlen(name_))
        , init(init_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_VariableDefinition; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override
    {
        if (init)
            v.visit(*init);
    }
    ~ASTVariableDefinitionNode() override { delete init; }
    const std::string_view type;
    const std::string_view name;
    ASTExprNode* init;
};

}

#endif