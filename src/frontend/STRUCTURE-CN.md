# STRUCTURE

Common: 公用数据结构

LexicalAnalyser: 词法分析相关

Parser: 语法分析相关

SemanticAnalyser: 语义分析相关

IR: 把AST翻译成LLVM IR

Executable: 可执行文件相关

TokenGen: 一个辅助工具，通过读入一个文件自动生成yacc的头和tokens.h中的enum部分。