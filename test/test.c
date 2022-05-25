#include "../filesystem.h"
#include <stdint.h>

// #define UNIT_TESTS 
#ifdef UNIT_TESTS
void test_is_status_file() {
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
}

void test_directories_create() {
    uint8_t pass_count = 0;
    if(create_directories("asdasd/asdasd", 0777)) {
        pass_count++;
    }
    if(!create_directories("/papka probel/asdasd", 0744)) {
        pass_count++;
    }
    if(create_directories("popka_local/asdasd/asd3asc", 0711)) {
        pass_count++;
    }
    if(create_directories("papka_in_koren/sad333a/a", 0741)) {
        pass_count++;
    }

    if(pass_count == 4) {
        printf("[test_directories_create] all tests(4-4) passed\n");
        return;
    }
    else {
        printf("[test_directories_create] test failed\n");
    }
}

void file_exists_test() {
    file_exists("/home");
    file_exists("/");
    file_exists("file_test");
    file_exists("../../Desktop");
}

void test_copy_file() {
    copy_file("file1", 128, "file2");
    remove_file("file1");
    remove_file("file2");
}

void test_remove_file_and_all() {

}

void test_check() {
    test_copy_file();
    test_directories_create();
}

#endif


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
    if(is_empty("filesystem.c")) {
        
    }
}
