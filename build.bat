g++ -fpic -shared src/winplus_time.c++ src/winplus_wmb.c++ -Iinclude -o winplus.dll
g++ test.c++ -lwinplus -L./
