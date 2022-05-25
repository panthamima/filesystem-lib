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

void test_directories_create() {
    char asd[] = "../../popka_local/asdasd/asd3asc";
    char qwe[] = "/home/rdwszzd/papka_in_koren/sad333a/a";
    char qweqwe[] = "/home/rdwszzd/papka probel/asdasd";
    char hjk[] = "asdasd/asdasd";
    create_directories(asd, 0777);
    create_directories(qwe, 0444);    
    create_directories(qweqwe, 0111);
    create_directories(hjk, 0);
}

void test_copy_file() {
    copy_file("file1", 128, "file2");
    remove_file("file1");
    remove_file("file2");
}

void test_remove_file_and_all() {

}
/* complete functions */

/* copy_file --- no-leaks */
/* create_directory */
/* create_directories --- no-leaks */
/* file_exists --- no-leaks*/
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
    // test_copy_file();
    if(!file_exists("/home")) {
        puts("sasasa");
    }
    puts("2e1231");
}
