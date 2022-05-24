#include "../filesystem.h"
#include <endian.h>
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

void test_directory_create() {

}

void test_copy_file() {

}

void test_remove_file_and_all() {

}
/* complete functions */

/* copy_file */
/* create_directory */
/* file_exists */
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
    char asd[] = "../../asdasd/asdasd";
    create_directories(asd, 0777);    
    // printf("%ld", sizeof(asd));
    
}
