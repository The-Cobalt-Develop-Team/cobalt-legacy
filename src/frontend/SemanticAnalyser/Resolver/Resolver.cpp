#include "Resolver/Resolver.h"
#include "Resolver/Scoop.h"

namespace Cobalt {

void VariableResolver::resolve(NodeType* n)
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

void VariableResolver::addDefinition(DefinitionNodeType* def) { (stk_.end() - 1)->addDefinition(def); }
void VariableResolver::visit(NodeType& n) { this->resolve(&n); }
void VariableResolver::visit(DefinitionNodeType& n) { this->addDefinition(&n); }
void VariableResolver::visit(ASTBlockNode& node)
{
    this->pushScoop();
    node.visitNext(*this);
    this->popScoop();
}

void TypeResolver::resolve(NodeType* n)
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

void TypeResolver::addDefinition(DefinitionNodeType* def) { (stk_.end() - 1)->addDefinition(def); }
void TypeResolver::visit(NodeType& n) { this->resolve(&n); }
void TypeResolver::visit(DefinitionNodeType& n) { this->addDefinition(&n); }
void TypeResolver::visit(ASTBlockNode& node)
{
    this->pushScoop();
    node.visitNext(*this);
    this->popScoop();
}

}