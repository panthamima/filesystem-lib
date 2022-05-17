#include "filesystem.h"
#include <stdio.h>

#ifdef FLS_OS_LINUX
char path_s[PATH_MAX];
#elif  FLS_OS_WINDOWS
char path[MAX_PATH];
#endif//fls_os_linux

#define _XOPEN_SOURCE

/* представляет собой путь */
int path_fls() {
    
}
/* исключение, вызванное ошибками файловой системы. */
int filesystem_error() {}
/* запись католога */
int directory_entry() {}
/* итератор содержимого католога */
int directory_iterator() {}
/* итератор содержимого католога и его подкатологов */
int recursive_directory_iterator() {}
/* представляет тип и разрешения файла */
int file_status() {}
/* информация о свободном и доступном пространстве в файловой системе */
int space_info() {}
/* тип файла */
int file_type() {}
/* определяет разрешения файловой системы */
int perms() {}
/* определяет семантику операций с разрешениями */
int perm_options() {}
/* определяет семантику операций копирования */
int copy_options() {}
/* опции для для итерации содержимого католога */
int directory_options() {}
/* опции для итерации содержимого католога */
int file_time_type() {}

//----------------------------------------------------------------------------------//

/* составляет абсолютный путь */
int absolute_path() {}
/* составляет канонический путь */
int canonical_path() {}
int weakly_canonical_path() {}
/* копирует файлы или катологи */
int copy() {}
/* копирует содержимое файла */
int copy_file() {}
/* копирует символическую ссылку */
int copy_symlink() {}
/* создает новый католог/катологи */
int create_directory() {}
int create_directories() {}
/* создает жесткую ссылку */
int create_hard_link() {}
/* создает символическую ссылку */
int create_symlink() {}
int create_directory_symlink() {}
/* возвращяет или устанавливает текущий рабочий каталог */
int current_path() {}
/* проверяет, ссылается ли путь на существующий объект файловой системы */
int exists() {}
/* проверяет, ссылаются ли два пути на один и тот же объект файловой системы */
int equivalent() {}
/* возвращает размер файла */
int file_size() {}
/* возвращяет число жестких ссылок на конкретный файл */
int hard_link_count() {}
/* получает или задает время последней модификации данных */
int last_write_time() {}
/* получает права доступа к файлу */
int permissions() {}
/* получает цель символической ссылки */
int read_symlink() {}
/* удаляет файл или пустой католог */
int remove_file(const char* file) {
    if(!remove(file)) {
        printf("hello\n");
        return FLS_SUCCESS;
    }
    printf("bye\n");
    return FLS_ERROR;
}
/* рекурсивно удаляет файл или католог и все его содержимое */
int remove_all() {}
/* перемещает или переименовывает файл или католог */
int rename_file(const char* old, const char* new) {
    rename(old, new);
}
/* изменяет размер обычного файла путем усечения или заполнением нулями */
int resize_file() {}
/* определяет доступное свободное место в файловой системе */
int space() {}
/* определяет атрибуты файла */
int status() {}
/* определяет атрибуты файла, проверяя цель символической ссылки */
int symlink_status() {}
/* возвращает католог, подходящий для временных файлов */
int temp_directory_path() {}

//----------------------------------------------------------------------------------//

/* проверяет, ссылается ли данный путь на блочное устройство */
int is_block_file(const char* file) {
    struct stat state;
    if(lstat(file, &state) < 0) {
        return FLS_ERROR;
    }

    if(S_ISBLK(state.st_mode)) {
        return BLOCK_FILE;
    }
    return FLS_ERROR;
}
/* проверяет, ссылается ли данный путь на католог */
int is_directory(const char* file) {
    struct stat state;
    if(lstat(file, &state) < 0) {
        return FLS_ERROR;
    }

    if(S_ISDIR(state.st_mode)) {
            printf("sdfsdf ");

        return DIRECTORY_FILE;
    }
    return FLS_ERROR;
}
/* проверяет, ссылается ли данный путь на аргумент на обычный файл */
int is_regular_file(const char* file) {
    struct stat state;
    if(lstat(file, &state) < 0) {
        return FLS_ERROR;
    }

    if(S_ISREG(state.st_mode)) {
        return REGULAR_FILE;
    }
    return FLS_ERROR;
}
/* проверяет, ссылается ли данный путь на именованный канал */
int is_fifo(const char* file) {
    struct stat state;
    if(lstat(file, &state) < 0) {
        return FLS_ERROR;
    }

    if(S_ISFIFO(state.st_mode)) {
        return FIFO_FILE;
    }
    return FLS_ERROR;
}
/* проверяет, ссылается ли данный путь на именованный IPC-socket */
int is_socket(const char* file) {
    struct stat state;
    if(lstat(file, &state) < 0) {
        return FLS_ERROR;
    }

    if(S_ISSOCK(state.st_mode)) {
        return SOCKET_FILE;
    }
    return FLS_ERROR;
}
/* проверяет, ссылается ли данный путь на 'другой' файл */
// int is_other(const char* file) {
//     if(status_known(file)) {
//         return 
//     }
//     return FLS_ERROR;
// }
/* проверяет, ссылается ли данный путь на символьное устройство */
int is_character_file(const char* file) {
    struct stat state;
    if(lstat(file, &state) < 0) {
        return FLS_ERROR;
    }
    
    if(S_ISCHR(state.st_mode)) {
            printf("sdfsdf ");
        return CHAR_FILE;
    }
    return FLS_ERROR;
}
/* проверяет, ссылается ли данный путь на пустой файл или пустой католог */
int is_empty(const char* file) {
    FILE *empty_check;
    if((empty_check = fopen(file, "r")) == NULL) {
        return FLS_ERROR;
    }
    fseek(empty_check, 0, SEEK_END);
    long pos = ftell(empty_check);
    fclose(empty_check);
    return 0;
}
/* проверяет, ссылается ли данный путь на символическую ссылку */
int is_symlink(const char* file) {
    struct stat state;
    if(lstat(file, &state) < 0) {
        return FLS_ERROR;
    }
    
    if(S_ISLNK(state.st_mode)) {
        return SYMLINK_FILE;
    }
    #ifdef __DEBUG__
    printf("symnot");
    #endif
    return FLS_ERROR;
}
/* проверяет известно ли состояние файла */
int status_known(const char* file) {
    int code_status = 0;
    if((code_status = is_block_file(file)) || 
       (code_status = is_regular_file(file)) ||
       (code_status = is_character_file(file)) ||
       (code_status = is_directory(file)) ||
       (code_status = is_fifo(file)) ||
       (code_status = is_socket(file)) || 
       (code_status = is_symlink(file))) {
        return code_status;
    }
    return false;
}


