#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_ASTVISITOR_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_ASTVISITOR_H_

#include "AST/ASTNode.h"

namespace Cobalt {

class BaseASTVisitor {
public:
    virtual ~BaseASTVisitor() = default;
#define ADD_NODE_KIND(name) \
    virtual void visit(AST##name##Node& node);
#include "AST/Node/ASTNode.inc"
#undef ADD_NODE_KIND
};

}

#endif