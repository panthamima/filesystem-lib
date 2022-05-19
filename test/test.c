#include "../filesystem.h"

int check_file() {
    char path[4096] = "/";
    if(is_block_file(path)) {
        printf("block\n");
    }
    if(is_character_file(path)) {
        printf("char\n");
    }
    if(is_directory(path)) {
        printf("directory\n");
    }
    if(is_fifo(path)) {
        printf("fifo\n");
    }
    if(is_regular_file(path)) {
        printf("regular\n");
    }
    // if(is_symlink(path)) {
    //     printf("symlink\n");
    // }
    // if(is_empty(path)) {
    //     printf("empty\n");
    // }

    printf("error\n");
    return 1;
}

int main() {
    char in[] = "filesystem.c";
    char out[] = "out.txt";
    
    copy_file(in, 2, out);

}
