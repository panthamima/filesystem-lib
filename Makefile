BUILD_FLAGS   = -Os -Wformat=2 -ggdb#-std=c99
DEBUG_FLAGS   = -Wall -O # -Werror
CXX_FLAGS     = -lstdc++fs

build: 
	gcc $(BUILD_FLAGS) -o a.out filesystem.c test/test.c 
	rm -rf *.o

debug: 
	gcc $(BUILD_FLAGS) $(DEBUG_FLAGS) -o result filesystem.c test/test.c 

cpp:
	g++ -o cpp.out test/test.cpp $(CXX_FLAGS) 