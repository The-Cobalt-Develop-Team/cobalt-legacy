#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_ASTNODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_ASTNODE_H_

#include "AST/ASTVisitor.h"

#include <ostream>

namespace Cobalt {

enum ASTNodeKind {
#define ADD_NODE_KIND(name) NK_##name,
#include "AST/Node/ASTNode.inc"
#undef ADD_NODE_KIND
};

struct BaseASTNode {
    virtual ~BaseASTNode() = default;
    [[nodiscard]] virtual ASTNodeKind kind() const = 0;
    virtual void dump(std::ostream& os) const = 0;
    virtual void visit(BaseASTVisitor& visitor)
    {
        visitor.visit(*this);
    }
};

#define ADD_NODE_KIND(name) \
    struct AST##name##Node;
#include "AST/Node/ASTNode.inc"
#undef ADD_NODE_KIND

}

#endif