#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_RESOLVER_RESOLVER_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_RESOLVER_RESOLVER_H_

#include "AST/ASTVisitor.h"
#include "AST/Node/BaseNode.h"
#include "AST/Node/ExprNode.h"
#include "AST/Node/StmtNode.h"
#include "Resolver/Scoop.h"

#include <deque>
#include <iostream>
#include <stdexcept>
#include <string_view>

namespace Cobalt {

class VariableResolver : public BaseASTVisitor {
public:
    using DefinitionNodeType = ASTVariableDefinitionNode;
    using NodeType = ASTVariableNode;
    VariableResolver() { this->pushScoop(); }
    void resolve(NodeType* n);
    void addDefinition(DefinitionNodeType* def);
    void pushScoop() { stk_.emplace_back(); }
    void popScoop() { stk_.pop_back(); }
    void visit(NodeType& node) override;
    void visit(DefinitionNodeType& node) override;
    void visit(ASTBlockNode& node) override;

private:
    std::deque<Scoop<DefinitionNodeType>> stk_;
};

class TypeResolver : public BaseASTVisitor {
public:
    using DefinitionNodeType = ASTTypeDefinitionNode;
    using NodeType = ASTTypeNode;
    TypeResolver() { this->pushScoop(); }
    void resolve(NodeType* n);
    void addDefinition(DefinitionNodeType* def);
    void pushScoop() { stk_.emplace_back(); }
    void popScoop() { stk_.pop_back(); }
    void visit(NodeType& node) override;
    void visit(DefinitionNodeType& node) override;
    void visit(ASTBlockNode& node) override;

private:
    std::deque<Scoop<DefinitionNodeType>> stk_;
};

// void pushBuiltinTypes(TypeResolver& resolver)
// {
//     static char* builtin = (char*)"<Builtin Type>";
//     static ASTTypeDefinitionNode intNode = new ASTTypeDefinitionNode(builtin);
// }

}

#endif