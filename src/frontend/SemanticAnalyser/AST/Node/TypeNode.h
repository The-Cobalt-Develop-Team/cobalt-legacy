#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_TYPENODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_TYPENODE_H_

#include "AST/ASTNode.h"
#include "AST/ASTVisitor.h"
#include "AST/Node/BaseNode.h"

#include <cstring>
#include <ostream>
#include <string_view>
#include <vector>

namespace Cobalt {

struct ASTTypedefNode : ASTTypeDefinitionNode {
    ASTTypedefNode(ASTTypeNode& type_, char* name_, char* loc)
        : ASTTypeDefinitionNode(name_, loc)
        , type(type_)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Typedef; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { v.visit(type); }
    ~ASTTypedefNode() override { delete &type; }
    ASTTypeNode& type;
};

struct ASTCompositeTypeNode : ASTTypeDefinitionNode {
    ASTCompositeTypeNode(char* name_, char* loc)
        : ASTTypeDefinitionNode(name_, loc)
    {
    }
    void visitNext(BaseASTVisitor& v) override
    {
        for (auto p : slots)
            v.visit(*p);
    }
    ~ASTCompositeTypeNode() override
    {
        for (auto p : slots)
            delete p;
    }
    std::vector<ASTSlotNode*> slots;
};

struct ASTStructDefNode : ASTCompositeTypeNode {
    ASTStructDefNode(char* name, char* loc)
        : ASTCompositeTypeNode(name, loc)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_StructDef; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { }
};

struct ASTUnionDefNode : ASTCompositeTypeNode {
    ASTUnionDefNode(char* name, char* loc)
        : ASTCompositeTypeNode(name, loc)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_UnionDef; }
    void dump(std::ostream& os) const override;
};

}

#endif