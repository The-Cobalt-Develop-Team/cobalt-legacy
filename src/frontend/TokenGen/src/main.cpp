#include "../include/tokengen.hpp"

Tokens tokens;

int main()
{
    std::string inputName, outputName, type;
    unsigned long long align = 0;
    std::cout << "Please input the input name of your token file:" << std::endl;
    std::cin >> inputName;
    std::cout << "Please input the type you want(Yacc,tokenh):" << std::endl;
    std::cin >> type;
    std::cout << "Please input the align:" << std::endl;
    std::cin >> align;
    std::cout << "Please input the output name of your token file:" << std::endl;
    std::cin >> outputName;
    freopen(inputName.c_str(), "r", stdin);
    freopen(outputName.c_str(), "w", stdout);
    tokens.GetTokens();
    if (type == "Yacc") {
        tokens.PrintTokens(Tokens::YACC, align);
    } else if (type == "tokenh") {
        tokens.PrintTokens(Tokens::TOKENH, align);
    }
    return 0;
}