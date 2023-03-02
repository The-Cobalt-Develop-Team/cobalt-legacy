#include "AST/Node/ExprNode.h"
#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"
#include "AST/Node/Reflection.h"

namespace Cobalt {

}

extern "C" {

void* AST_AssignNodeConstructor(char* loc, void* lhs, void* rhs)
{
    auto lhs_ = static_cast<Cobalt::ASTLHSNode*>(lhs);
    auto rhs_ = static_cast<Cobalt::ASTExprNode*>(rhs);
    auto new_node = new Cobalt::ASTAssignNode(*lhs_, *rhs_, loc);
    return static_cast<void*>(new_node);
}

void* AST_OpAssignNodeConstructor(char* loc, void* lhs, AST_BinaryOperatorType op, void* rhs)
{
    auto lhs_ = static_cast<Cobalt::ASTLHSNode*>(lhs);
    auto rhs_ = static_cast<Cobalt::ASTExprNode*>(rhs);
    auto new_node = new Cobalt::ASTOpAssignNode(*lhs_, op, *rhs_, loc);
    return static_cast<void*>(new_node);
}

void* AST_AddressNodeConstructor(char* loc, void* expr)
{
    auto expr_ = static_cast<Cobalt::ASTExprNode*>(expr);
    auto new_node = new Cobalt::ASTAddressNode(*expr_, loc);
    return static_cast<void*>(new_node);
}

void* AST_BinaryOpNodeConstructor(char* loc, void* lhs, AST_BinaryOperatorType op, void* rhs)
{
    using namespace Cobalt;
    auto lhs_ = static_cast<ASTExprNode*>(lhs), rhs_ = static_cast<ASTExprNode*>(rhs);
    auto new_node = new ASTBinaryOpNode(*lhs_, op, *rhs_, loc);
    return static_cast<void*>(new_node);
}

void* AST_CondExprNodeConstructor(char* loc, void* condition, void* statement_a, void* statement_b)
{
    auto cond = static_cast<Cobalt::ASTExprNode*>(condition);
    auto stmt1 = static_cast<Cobalt::ASTStmtNode*>(statement_a);
    auto stmt2 = static_cast<Cobalt::ASTStmtNode*>(statement_b);
    auto new_node = new Cobalt::ASTCondExprNode(*cond, *stmt1, *stmt2, loc);
    return static_cast<void*>(new_node);
}

void* AST_FuncCallNodeConstructor(char* loc, char* func)
{
    return static_cast<void*>(new Cobalt::ASTFuncCallNode(func, loc));
}

void* AST_AddFuncCallParameter(void* func_call, void* param)
{
    auto func = static_cast<Cobalt::ASTFuncCallNode*>(func_call);
    auto param_ = static_cast<Cobalt::ASTFuncParameterNode*>(param);
    func->params.emplace_back(param_);
    return func_call;
}

void* AST_ArraySubscriptConstructor(char* loc, void* array, void* subscript)
{
    auto array_ = static_cast<Cobalt::ASTExprNode*>(array);
    auto subs_ = static_cast<Cobalt::ASTExprNode*>(subscript);
    auto new_node = new Cobalt::ASTArraySubscriptNode(*array_, *subs_, loc);
    return static_cast<void*>(new_node);
}

void* AST_DereferenceConstructor(char* loc, void* ptr)
{
    auto p = static_cast<Cobalt::ASTExprNode*>(ptr);
    auto new_node = new Cobalt::ASTDereferenceNode(*p, loc);
    return static_cast<void*>(new_node);
}

void* AST_MemberConstructor(char* loc, void* obj, char* memb)
{
    auto p = static_cast<Cobalt::ASTExprNode*>(obj);
    auto newn = new Cobalt::ASTMemberNode(*p, memb, loc);
    return static_cast<void*>(newn);
}

void* AST_PtrMemberConstructor(char* loc, void* ptr, char* memb)
{
    auto p = static_cast<Cobalt::ASTExprNode*>(ptr);
    auto newn = new Cobalt::ASTMemberNode(*p, memb, loc);
    return static_cast<void*>(newn);
}

void* AST_VariableConstructor(char* loc, char* name)
{
    return static_cast<void*>(new Cobalt::ASTVariableNode(name, loc));
}

void* AST_IntLiteralConstructor(char* loc, char* raw)
{
    return static_cast<void*>(new Cobalt::ASTIntLiteralNode(raw, loc));
}

void* AST_StringLiteralConstructor(char* loc, char* raw)
{
    return static_cast<void*>(new Cobalt::ASTStringLiteralNode(raw, loc));
}

void* AST_FloatLiteralConstructor(char* loc, char* raw)
{
    return static_cast<void*>(new Cobalt::ASTFloatLiteralNode(raw, loc));
}

void* AST_SizeofNodeConstructor(char* loc, void* node)
{
    auto p = static_cast<Cobalt::BaseASTNode*>(node);
    if (Cobalt::isExprNode(p)) {
        auto n = static_cast<Cobalt::ASTExprNode*>(node);
        return static_cast<void*>(new Cobalt::ASTSizeofExprNode(*n, loc));
    } else {
        auto n = static_cast<Cobalt::ASTTypeNode*>(node);
        return static_cast<void*>(new Cobalt::ASTSizeofTypeNode(*n, loc));
    }
}

void* AST_UnaryOpNodeConstructor(char* loc, void* expr, AST_UnaryOperatorType op)
{
    using namespace Cobalt;
    auto expr_ = static_cast<ASTExprNode*>(expr);
    auto new_node = new ASTUnaryOpNode(*expr_, op, loc);
    return static_cast<void*>(new_node);
}
}