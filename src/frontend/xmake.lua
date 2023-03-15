add_rules("mode.release", "mode.debug")

add_requires("gtest")

target("cobalt-frontend")
    set_kind("binary")
    add_files("Executable/main.cpp")

target("cobalt-common")
    set_kind("static")
    set_languages("cxx17")
    add_includedirs("Common")
    add_files("Common/*/*.cpp")

target("cobalt-semantic-analyser")
    set_kind("static")
    set_languages("cxx17")
    add_includedirs("SemanticAnalyser")
    add_files("SemanticAnalyser/AST/*.cpp")
    add_files("SemanticAnalyser/AST/Node/*.cpp")

target("cobalt-semantic-analyser-test")
    set_kind("binary")
    set_languages("cxx17")
    add_includedirs("SemanticAnalyser")
    add_packages("gtest")
    add_files("SemanticAnalyser/Tests/*.cpp")
    add_deps("cobalt-semantic-analyser")
    add_links("gtest", "gtest_main")

