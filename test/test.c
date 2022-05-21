#include "../filesystem.h"
#include <string.h>

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

/* complete functions */
/* copy_file */
/* create_directory */
/* exists */
/* remove_file --- no-leaks*/
/* remove_all --- NOT FINISHED*/
/* rename_file --- no-leaks*/
/* is_***_file func's --- no-leaks ???*/
/* is_empty --- NOT FINISHED*/
/* status_known */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */

int main() {
    // char in[] = "filesystem.c";
    // char out[] = "out.txt";
    char dir[] = "/home/user";
    char new_dir[] = "/home/user/asd";
    // copy_file(in, 2, out);
    // create_directory(dir, 777);
    if(exists(new_dir)) {
        // printf("sdasd");
        // return 1;
    }
    // printf("asdasdasdasdasda");
    // return 0;
    remove_all(new_dir);
}
