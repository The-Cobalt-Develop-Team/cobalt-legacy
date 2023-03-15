#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_BASENODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_BASENODE_H_

#include "AST/ASTNode.h"
#include "AST/ASTVisitor.h"

#include <cstring>
#include <ostream>
#include <string_view>

namespace Cobalt {

struct ASTExprNode : BaseASTNode {
    explicit ASTExprNode(char* loc)
        : BaseASTNode(loc)
    {
    }
};

struct ASTStmtNode : BaseASTNode {
    explicit ASTStmtNode(char* loc)
        : BaseASTNode(loc)
    {
    }
};

struct ASTTypeNode : BaseASTNode {
    ASTTypeNode(char* name_, char* loc)
        : BaseASTNode(loc)
        , name(name_, strlen(name_))
        , definition(nullptr)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Type; }
    void dump(std::ostream& os) const override
    {
        os << "{";
        os << R"("nodeKind":"ASTTypeNode",)";
        os << "\"type\": "
           << '\"' << name << '\"';
        os << "}";
    }
    void visitNext(BaseASTVisitor& v) override { }
    const std::string_view name;
    ASTTypeDefinitionNode* definition;
};

struct ASTTypeDefinitionNode : BaseASTNode {
    explicit ASTTypeDefinitionNode(char* loc)
        : BaseASTNode(loc)
    {
    }
};

struct ASTFuncParameterNode : BaseASTNode {
    ASTFuncParameterNode(ASTTypeNode& type_, char* name_, char* loc)
        : BaseASTNode(loc)
        , type(type_)
        , name(name_, strlen(name_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_FuncParameter; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { v.visit(type); }
    ASTTypeNode& type;
    const std::string_view name;
};

struct ASTSlotNode : BaseASTNode {
    ASTSlotNode(ASTTypeNode& type_, char* name_, char* loc)
        : BaseASTNode(loc)
        , type(type_)
        , name(name_, strlen(name_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Slot; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { v.visit(type); }
    ASTTypeNode& type;
    const std::string_view name;
};

}

#endif