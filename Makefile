BUILD_FLAGS   = -Os -Wformat=2 -ggdb#-std=c99
DEBUG_FLAGS   = -Wall -O # -Werror

build: 
	gcc $(BUILD_FLAGS) -o a.out filesystem.c test/test.c 
	rm -rf *.o

debug: 
	gcc $(BUILD_FLAGS) $(DEBUG_FLAGS) -o result filesystem.c test/test.c 

# buildw:
# gcc -o awe main.c src/*.c crypt/*.c $(LIBS) 