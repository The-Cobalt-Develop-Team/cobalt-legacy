#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_STMTNODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_STMTNODE_H_

#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"
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
    std::vector<ASTStmtNode*> stmts;
};

struct ASTBreakNode : ASTStmtNode {
    explicit ASTBreakNode(char* loc)
        : ASTStmtNode(loc)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Break; }
    void dump(std::ostream& os) const override;
};

struct ASTContinueNode : ASTStmtNode {
    explicit ASTContinueNode(char* loc)
        : ASTStmtNode(loc)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Continue; }
    void dump(std::ostream& os) const override;
};

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
    const ASTStmtNode& stmt;
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
    const ASTExprNode& cond;
    const ASTStmtNode& stmt;
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
    const ASTExprNode& cond;
    const ASTStmtNode& stmt;
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
    const ASTStmtNode& init;
    const ASTExprNode& cond;
    const ASTStmtNode& mod;
    const ASTStmtNode& body;
};

struct ASTGotoNode : ASTStmtNode {
    ASTGotoNode(char* label_, char* loc)
        : ASTStmtNode(loc)
        , label(label_, strlen(label_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Goto; }
    void dump(std::ostream& os) const override;
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
    const ASTExprNode& expr;
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
    const ASTExprNode& cond;
    const ASTStmtNode& body;
};

struct ASTLabelNode : ASTStmtNode {
    ASTLabelNode(char* name_, char* loc)
        : ASTStmtNode(loc)
        , name(name_, strlen(name_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Label; }
    void dump(std::ostream& os) const override;
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
    const ASTExprNode& expr;
};

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
};

}

#endif