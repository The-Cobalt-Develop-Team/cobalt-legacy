add_requires("magic_enum")

target("cobalt-frontend")
    set_kind("binary")
    add_files("Executable/main.cpp")

target("cobalt-semantic-analyser")
    set_kind("static")
    set_languages("cxx17")
    add_includedirs("SemanticAnalyser")
    add_files("SemanticAnalyser/AST/*.cpp")
    add_files("SemanticAnalyser/AST/Node/*.cpp")
    add_packages("magic_enum")