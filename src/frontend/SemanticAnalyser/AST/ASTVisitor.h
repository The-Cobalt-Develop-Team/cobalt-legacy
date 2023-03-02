#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_ASTVISITOR_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_ASTVISITOR_H_

namespace Cobalt {

struct BaseASTNode;

class BaseASTVisitor {
public:
    virtual ~BaseASTVisitor() = default;
    virtual void visit(BaseASTNode&);
};

}

#endif