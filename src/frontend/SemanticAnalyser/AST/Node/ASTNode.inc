#ifndef END_NODE_KIND
#define END_NODE_KIND(x)
#endif

ADD_NODE_KIND(ASTRoot)
#include "ExprNode.inc"
ADD_NODE_KIND(FuncParameter)
ADD_NODE_KIND(Slot)
#include "StmtNode.inc"
ADD_NODE_KIND(TypeDefinition)
  ADD_NODE_KIND(CompositeType)
    ADD_NODE_KIND(StructDef)
    ADD_NODE_KIND(UnionDef)
  ADD_NODE_KIND(Typedef)
ADD_NODE_KIND(Type)

#undef END_NODE_KIND