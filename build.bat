cmake -B build -G "MinGW Makefiles"
cmake --build build
clang++ -o build/test.exe test.c++ -L./build/ -lwinplus -I./includes --std=c++26
.\build\test.exe