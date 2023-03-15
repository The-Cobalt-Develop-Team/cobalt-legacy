#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_RESOLVER_RESOLVER_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_RESOLVER_RESOLVER_H_

#include "AST/ASTVisitor.h"
#include "AST/Node/BaseNode.h"
#include "AST/Node/ExprNode.h"
#include "AST/Node/StmtNode.h"
#include "AST/Resolver/Scoop.h"

#include <deque>
#include <iostream>
#include <stdexcept>
#include <string_view>

namespace Cobalt {

namespace detail {
    template <typename T>
    struct hasDefinitionMember {
        template <typename U>
        static constexpr bool check(decltype(&U::definition)) { return true; }
        template <typename U>
        static constexpr bool check(...) { return false; }
        static constexpr bool value = check<T>(nullptr);
    };
}

template <typename T, typename U>
class Resolver : public BaseASTVisitor {
public:
    using DefinitionNodeType = T;
    using NodeType = U;
    static_assert(detail::hasDefinitionMember<NodeType>::value, "NodeType must have a member pointer to definition node with name \"definition\"");
    Resolver() { this->pushScoop(); }
    void resolve(NodeType* n)
    {
        for (auto it = stk_.rbegin(); it != stk_.rend(); ++it) {
            auto x = it->findDefinition(n->name);
            if (x != nullptr) {
                n->definition = x;
                return;
            }
        }
        throw std::invalid_argument("No such object");
    }
    void addDefinition(DefinitionNodeType* def)
    {
        (stk_.end() - 1)->addDefinition(def);
    }
    void pushScoop() { stk_.emplace_back(); }
    void popScoop() { stk_.pop_back(); }
    void visit(NodeType& node) override
    {
        this->resolve(&node);
    }
    void visit(DefinitionNodeType& node) override
    {
        this->addDefinition(&node);
    }
    void visit(ASTBlockNode& node) override
    {
        this->pushScoop();
        node.visitNext(*this);
        this->popScoop();
    }

private:
    std::deque<Scoop<DefinitionNodeType>> stk_;
};

using VariableResolver = Resolver<ASTVariableDefinitionNode, ASTVariableNode>;
using TypeResolver = Resolver<ASTTypeDefinitionNode, ASTTypeNode>;

// void pushBuiltinTypes(TypeResolver& resolver)
// {
//     static char* builtin = (char*)"<Builtin Type>";
//     static ASTTypeDefinitionNode intNode = new ASTTypeDefinitionNode(builtin);
// }

}

#endif