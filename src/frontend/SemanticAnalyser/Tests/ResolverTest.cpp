#include "gtest/gtest.h"
#include <iostream>

#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"
#include "AST/Node/ExprNode.h"
#include "AST/Resolver/Resolver.h"

using namespace Cobalt;

static char* kTestLocation = (char*)("<Test File>");

TEST(ResolverTest, VariableResolverTest1)
{
    auto defnode = (ASTVariableDefinitionNode*)AST_VariableDefinitionConstructor(kTestLocation, (char*)"int", (char*)"v", nullptr);
    auto varnode = (ASTVariableNode*)AST_VariableConstructor(kTestLocation, (char*)"v");
    VariableResolver resolver;
    resolver.addDefinition(defnode);
    resolver.resolve(varnode);
    ASSERT_EQ(varnode->definition, defnode);
}

TEST(ResolverTest, VariableResolverTest2)
{
    auto blocknode1 = new ASTBlockNode(kTestLocation);
    auto defnode1 = new ASTVariableDefinitionNode((char*)"int", (char*)"var1", nullptr, kTestLocation);
    auto blocknode2 = new ASTBlockNode(kTestLocation);
    auto defnode2 = new ASTVariableDefinitionNode((char*)"int", (char*)"var2", nullptr, kTestLocation);
    auto varnode1 = new ASTVariableNode((char*)"var1", kTestLocation);
    auto varnode2 = new ASTVariableNode((char*)"var2", kTestLocation);
    auto varnode1stmt = new ASTExprStmtNode(*varnode1, kTestLocation);
    auto varnode2stmt = new ASTExprStmtNode(*varnode2, kTestLocation);
    blocknode1->stmts.emplace_back(defnode1);
    blocknode1->stmts.emplace_back(blocknode2);
    blocknode2->stmts.emplace_back(defnode2);
    blocknode2->stmts.emplace_back(varnode1stmt);
    blocknode2->stmts.emplace_back(varnode2stmt);
    VariableResolver resolver;
    resolver.visit(*blocknode1);
    ASSERT_EQ(varnode1->definition, defnode1);
    ASSERT_EQ(varnode2->definition, defnode2);
}

TEST(ResolverTest, VariableTypeResolverTest1)
{
    auto blocknode1 = new ASTBlockNode(kTestLocation);
    auto defnode1 = new ASTVariableDefinitionNode((char*)"int", (char*)"var1", nullptr, kTestLocation);
    auto blocknode2 = new ASTBlockNode(kTestLocation);
    auto defnode2 = new ASTVariableDefinitionNode((char*)"int", (char*)"var2", nullptr, kTestLocation);
    auto varnode1 = new ASTVariableNode((char*)"var1", kTestLocation);
    auto varnode2 = new ASTVariableNode((char*)"var2", kTestLocation);
    auto varnode1stmt = new ASTExprStmtNode(*varnode1, kTestLocation);
    auto varnode2stmt = new ASTExprStmtNode(*varnode2, kTestLocation);
    blocknode1->stmts.emplace_back(defnode1);
    blocknode1->stmts.emplace_back(blocknode2);
    blocknode2->stmts.emplace_back(defnode2);
    blocknode2->stmts.emplace_back(varnode1stmt);
    blocknode2->stmts.emplace_back(varnode2stmt);
    VariableResolver resolver;
    TypeResolver type_resolver;
    resolver.visit(*blocknode1);
    ASSERT_EQ(varnode1->definition, defnode1);
    ASSERT_EQ(varnode2->definition, defnode2);
}
