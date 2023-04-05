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

struct ASTBuiltinTypeNode : ASTTypeDefinitionNode {
    ASTBuiltinTypeNode(char* name_, char* loc)
        : ASTTypeDefinitionNode(name_, loc)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_BuiltinType; }
    void dump(std::ostream& os) const override;
    void visitNext(BaseASTVisitor& v) override { }
};

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

struct ASTSimpleTypeNode : ASTTypeNode {
    ASTSimpleTypeNode(char* name_, char* loc)
        : ASTTypeNode(loc)
        , name(name_, strlen(name_))
        , definition(nullptr)
    {
    }
    void visitNext(BaseASTVisitor& v) override { }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_SimpleType; }
    void dump(std::ostream& os) const override
    {
        // TODO: ASTSimpleTypeNode::dump
    }

    const std::string_view name;
    ASTTypeDefinitionNode* definition;
};

struct ASTFunctionSignatureNode : ASTTypeNode {
    ASTFunctionSignatureNode(ASTTypeNode& res_type_, char* loc)
        : ASTTypeNode(loc)
        , res_type(res_type_)
    {
    }
    ~ASTFunctionSignatureNode() override
    {
        delete &res_type;
        for (auto p : param_types)
            delete p;
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_FunctionSignature; }
    void dump(std::ostream& os) const override
    {
        // TODO: ASTFunctionSignatureNode::dump
    }
    void visitNext(BaseASTVisitor& v) override
    {
        v.visit(res_type);
        for (auto p : param_types)
            v.visit(*p);
    }
    ASTTypeNode& res_type;
    std::vector<ASTTypeNode*> param_types;
};

struct ASTComplexTypeNode : ASTTypeNode {
    ASTComplexTypeNode(char* name_, char* loc)
        : ASTTypeNode(loc)
        , name(name_, strlen(name_))
    {
    }
    ~ASTComplexTypeNode() override
    {
        for (auto p : param)
            delete p;
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_ComplexType; }
    void dump(std::ostream& os) const override
    {
        // TODO: ASTComplexTypeNode::dump
    }
    void visitNext(BaseASTVisitor& v) override
    {
        for (auto p : param)
            v.visit(*p);
    }
    const std::string_view name;
    std::vector<ASTTypeNode*> param;
};

}

#endif