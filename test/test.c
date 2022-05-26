#include "../filesystem.h"
#include <stdint.h>
#include <stdio.h>

// #define UNIT_TESTS 
#ifdef UNIT_TESTS
void test_is_status_file() {
    uint8_t pass_count = 0;
    FILE* stream;

    char block_file[] = "/dev/sda1";
    char directory_file[] = "/etc";
    char regular_file[] = "/etc/passwd";
    char symlink_file[] = "";
    char empty_file[] = "empty.txt";

    stream = fopen(empty_file, "a");
    if(is_block_file(block_file)) {
        printf("1 block [✔passed]\n");
    }
    else {
        printf("1 block [failed]\n");
    }
    if(is_directory(directory_file)) {
        printf("2 directory [✔passed]\n");
    }
    else {
        printf("2 directory [failed]\n");
    }
    if(is_regular_file(regular_file)) {
        printf("3 regular [✔passed]\n");
    }
    else {
        printf("3 regular [failed]\n");
    }
    if(is_symlink(symlink_file)) {
        printf("4 symlink [✔passed]\n");
    }
    else {
        printf("4 symlink [failed]\n");
    }
    if(is_empty(empty_file)) {
        printf("5 empty [✔passed]\n");
    }
    else {
        printf("5 empty [failed]\n");
    }
    if(status_known(regular_file) && status_known(block_file)) {
        printf("6 status_known [✔passed]\n");
    }
    else {
        printf("6 status_known [failed]\n");
    }
    fclose(stream);
    remove(empty_file);
    return;
}

void test_directories_create() {
    uint8_t pass_count = 0;

    if(!create_directories("/papka probel/asdasd", 0744)) {
        pass_count++;
    }
    if(!create_directory("directory/asd", 0744)) {
        pass_count++;
    }
    if(!create_directory("/etc/folder", 0744)) {
        pass_count++;
    }

    if(create_directories("asdasd/asdasd", 0777)) {
        pass_count++;
    }
    if(create_directory("directory", 0744)) {
        pass_count++;
    }
    if(create_directories("popka_local/asdasd/asd3asc", 0711)) {
        pass_count++;
    }
    if(create_directories("papka_in_koren/sad333a/a", 0741)) {
        pass_count++;
    }

    if(pass_count == 7) {
        printf("[test_directories_create] all tests(7-7) passed\n");
        return;
    }
    else {
        printf("[test_directories_create] test failed\n");
    }
}

void file_exists_test() {
    uint8_t pass_count = 0;

    if(file_exists("/home")) {
        pass_count++;
    }
    if(file_exists("/")) {
        pass_count++;
    }
    if(!file_exists("file_test")) {
        pass_count++;
    }
    if(file_exists("../../Desktop")) {
        pass_count++;
    }

    if(pass_count == 4) {
        printf("[file_exists_test] all tests(4-4) passed\n");
        return;
    }
    else {
        printf("[file_exists_test] test failed\n");
    }
}

void test_copy_file() {
    uint8_t pass_count = 0;

    if(copy_file("/etc/passwd", 128, "local_passwd")) {
        pass_count++;
    }

    remove_file("local_passwd");
    if(pass_count == 1) {
        printf("[test_copy_file] test passed\n");
        return;
    }
    else {
        printf("[test_copy_file] test failed\n");
    }

}

void test_remove_file_and_all() {

}

void test_is_empty() {
    if(!is_empty("filesystem.c")) {
        printf("bebera\n");
    }
    if(is_empty("testfile")) {
        printf("amoguesa\n");
    }
}

void test_check() {
    test_is_status_file();
    test_directories_create();
    file_exists_test();
    test_copy_file();
}

#endif

/* complete functions */

/* copy_file --- no-leaks */
/* create_directory --- no-leaks*/
/* create_directories --- no-leaks */
/* file_exists --- no-leaks */
/* remove_file --- no-leaks */
/* remove_all --- NOT FINISHED */
/* rename_file --- no-leaks */
/* is_***_file func's --- no-leaks */
/* is_empty --- no-leaks */
/* status_known --- no-leaks*/
/* current_path --- NOT FINISHED*/
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */




int main() {
    // remove_all("/home/panthamima/test_to_delete");
    // if(current_path("/home/rdwszzd/test")) {
        // puts("sus");
    // }
    if(current_path("/home/rdwszzd/test", 4096)) {
        printf("asdasdas");
    }
    
    #ifdef UNIT_TESTS
    test_check();
    test_is_empty();
    #endif
}
