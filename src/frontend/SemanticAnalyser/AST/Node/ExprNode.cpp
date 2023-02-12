#include "AST/Node/ExprNode.h"
#include "AST/ASTCApi.h"

namespace Cobalt {

}

extern "C" {

void* AST_BinaryOpNodeConstructor(void* lhs, AST_BinaryOperatorType op, void* rhs)
{
    using namespace Cobalt;
    auto lhs_ = static_cast<ASTExprNode*>(lhs), rhs_ = static_cast<ASTExprNode*>(rhs);
    auto new_node = new ASTBinaryOpNode(*lhs_, op, *rhs_);
    return static_cast<void*>(new_node);
}
}