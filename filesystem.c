#include "filesystem.h"
#include <dirent.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

// #ifdef FLS_OS_LINUX
// char path_s[PATH_MAX];
// #elif  FLS_OS_WINDOWS
// char path[MAX_PATH];
// #endif//fls_os_linux

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
int file_type() {

}
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
/* копирует файл или католог */
int copy_s() {
    
}
/* копирует содержимое файла */
int copy_file(const char* input_file, size_t buf_size, const char* output_file, ...) {
    FILE *in, *out;
    char swap[buf_size];

    if((in = fopen(input_file, READ)) == NULL) { 
        printf("error in\n");
        return FLS_ERROR;
    }
    if((out = fopen(output_file, APPEND)) == NULL) {
        printf("error out\n");
        return FLS_ERROR;
    }

    while(fgets(swap, buf_size, in)) {
        fputs(swap, out);
        if(feof(in)) {
            break;
        }
    }
    fclose(in);
    fclose(out);
    return FLS_SUCCESS;
}
/* копирует символическую ссылку */
int copy_symlink() {}
/* создает новый католог/катологи */
int create_directory(const char* path, const int roots) {
    #ifdef FLS_OS_LINUX
    if(!mkdir(path, roots)) {
        return FLS_SUCCESS;
    }
    return FLS_ERROR;
    #elif FLS_OS_WINDOWS

    #endif

}

int create_directories(char* path, const int roots) {
    #ifdef FLS_OS_LINUX
    unsigned int i = 0; 
    size_t dir_create = 0;   /* number of directories created */
    size_t err_dir_create = 0; /* number of errors when creating directories */
    char buffer[PATH_MAX] = {};
    
    while(*path) {
        buffer[i++] = *path;

        if(*path++ == '/' || *path == '\0') {
            dir_create += 1;

            if((mkdir(buffer, roots) < 0)) {
                err_dir_create += 1;
            }
        }
    }

    if(dir_create == err_dir_create) {
        return FLS_ERROR;
    }
    return FLS_SUCCESS;


    #elif FLS_OS_WINDOWS

    #endif
}
/* создает жесткую ссылку */
int create_hard_link() {}
/* создает символическую ссылку */
int create_symlink() {}
int create_directory_symlink() {}
/* возвращает или устанавливает текущий рабочий каталог */
int current_path() {}
/* проверяет, ссылается ли путь на существующий объект файловой системы */
int file_exists(const char* file) {
    FILE *stream;

    if ((stream = fopen(file, READ)) != NULL) {
        fclose(stream);
        return FILE_EXISTS;
    }
    // fclose(stream);
    return FLS_ERROR;
}
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
        return FLS_SUCCESS;
    }
    return FLS_ERROR;
}
/* рекурсивно удаляет файл или католог и все его содержимое */
int remove_all(const char* path) {
    DIR *dir_s;
    struct dirent *dir;
    dir_s = opendir(path);

    while((dir = readdir(dir_s)) != NULL) {
        printf("%s\n", dir->d_name);
        remove_file(dir->d_name);
    }
    // удалять все файлы проверять на существование директорий 
    // (зна4ит они не удалились) соответсвтенно заходить в нее 
    // удалять проверять если остались еще директории продолжить ,
    // если нет то выйти и снова проверить на директории и так далее

    closedir(dir_s);
    return FLS_SUCCESS;
}
/* перемещает или переименовывает файл или католог */
int rename_file(const char* old, const char* new) {
    if(!rename(old, new)) {
        return FLS_SUCCESS;
    }
    return FLS_ERROR;
}
/* изменяет размер обычного файла путем усечения или заполнением нулями */
int resize_file() {}
/* определяет доступное свободное место в файловой системе */
int space() {

}
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
    if(open(file, O_DIRECTORY)) {
        return FLS_SUCCESS;
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