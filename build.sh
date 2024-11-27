g++ -fpic -shared src/*.c++ -Iinclude -o winplus.dll
g++ test.c++ -lwinplus -L./