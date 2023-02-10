#include <iostream>
#include <string>
#include <vector>

class Tokens {
public:
    enum {
        YACC,
        TOKENH,
    };
    void GetTokens()
    {
        std::string x;
        while (std::cin >> x) {
            _tokens.push_back(x);
            ++_length;
        }
    }
    void PrintTokens(int type, unsigned long long align) // type=YACC or TOKENH; align means that print how many words in a line.
    {
        switch (type) {
        case YACC:
            for (int i = 0; i < _length; i++) {
                if (i % align == 0) {
                    std::cout << std::endl
                              << "%token ";
                }
                std::cout << _tokens[i] << ' ';
            }
            std::cout << std::endl;
            break;
        case TOKENH:
            for (int i = 0; i < _length; i++) {
                std::cout << _tokens[i] << ',' << std::endl;
            }
            break;
        default:
            throw(std::invalid_argument("Illegal Arguments"));
            break;
        }
    }

private:
    std::vector<std::string>
        _tokens;
    unsigned long long _length = 0;
};