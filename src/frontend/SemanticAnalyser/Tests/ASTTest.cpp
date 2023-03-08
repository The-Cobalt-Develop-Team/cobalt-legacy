#include "gtest/gtest.h"
#include <iostream>

#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"
#include "AST/Node/Reflection.h"

using namespace Cobalt;

char* kTestLocation = (char*)("<Test File>");

TEST(ASTBuildTest, ExprNodeTest1)
{
    char* raw1 = (char*)("114514");
    char* raw2 = (char*)("1919810");
    auto lhs_ = static_cast<ASTIntLiteralNode*>(AST_IntLiteralConstructor(kTestLocation, raw1));
    auto rhs_ = static_cast<ASTIntLiteralNode*>(AST_IntLiteralConstructor(kTestLocation, raw2));
    auto node = static_cast<BaseASTNode*>(AST_BinaryOpNodeConstructor(kTestLocation, lhs_, AST_AddOp, rhs_));
    ASSERT_TRUE(isExprNode(node));
}
