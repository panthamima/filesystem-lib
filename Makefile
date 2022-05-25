LIBS          = 
BUILD_FLAGS   = -Os -Wformat=2 -ggdb -Wall#-std=c99
DEBUG_FLAGS   = -Wall -O # -Werror

build: 
	gcc $(BUILD_FLAGS) -o a.out test/test.c filesystem.c

cpp:
	g++ -o cpp.out test/test.cpp