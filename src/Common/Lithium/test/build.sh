# clang++ test.cpp ../Logger/src/Logger.cpp ../Logger/src/LoggerNode.cpp -o test.out -Wall -fsanitize=address -fuse-ld=lld
g++ test.cpp ../Logger/src/Logger.cpp ../Logger/src/LoggerNode.cpp -o test.out -Wall -fsanitize=address
./test.out