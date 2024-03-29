#ifndef ADD_STMT_NODE
#define ADD_STMT_NODE ADD_NODE_KIND(Stmt)
#endif

ADD_STMT_NODE
  ADD_NODE_KIND(VariableDefinition)
  ADD_NODE_KIND(Block)
  ADD_NODE_KIND(Break)
  ADD_NODE_KIND(Continue)
  ADD_NODE_KIND(Case)
  ADD_NODE_KIND(DoWhile)
  ADD_NODE_KIND(While)
  ADD_NODE_KIND(For)
  ADD_NODE_KIND(Goto)
  ADD_NODE_KIND(ExprStmt)
  ADD_NODE_KIND(If)
  ADD_NODE_KIND(Label)
  ADD_NODE_KIND(Return)
  ADD_NODE_KIND(Switch)
END_NODE_KIND(Stmt)

#undef ADD_STMT_NODE