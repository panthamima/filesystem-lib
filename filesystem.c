#include "filesystem.h"
#include <dirent.h>
#include <linux/limits.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// #ifdef FLS_OS_LINUX
// char path_s[PATH_MAX];
// #elif  FLS_OS_WINDOWS
// char path[MAX_PATH];
// #endif//fls_os_linux

/* представляет собой путь */
int path_fls() { return 0; }
/* исключение, вызванное ошибками файловой системы. */
int filesystem_error() { return 0; }
/* запись католога */
int directory_entry() { return 0; }
/* итератор содержимого католога */
int directory_iterator(const char* path, char* buffer) {
    DIR *dir_iter;
    struct dirent *dir;
    dir_iter = opendir(path);
    int i = 0;
    static uint8_t count = 0;

    count++;
    while((dir = readdir(dir_iter)) != NULL) {
        i++;
        if(i == count) {
            // if((!strcmp(dir->d_name, ".")) || (!strcmp(dir->d_name, ".."))) {
                // continue;
            // }else {
                memcpy(buffer, dir->d_name, sizeof(dir->d_name));
                return FLS_SUCCESS;
            // }
        }
    }
    count = 0;

    // #define debug
    #ifdef debug
    while((dir = readdir(dir_iter))!= NULL) {
        printf("%s\n", dir->d_name);
    }
    #endif

    closedir(dir_iter);
    return FLS_ERROR;
}
/* итератор содержимого католога и его подкатологов */
int recursive_directory_iterator() { return 0; }
/* представляет тип и разрешения файла */
int file_status() { return 0; }
/* информация о свободном и доступном пространстве в файловой системе */
int space_info() { return 0; }
/* тип файла */
int file_type() { return 0; }
/* определяет разрешения файловой системы */
int perms() { return 0; }
/* определяет семантику операций с разрешениями */
int perm_options() { return 0; }
/* определяет семантику операций копирования */
int copy_options() { return 0; }
/* опции для для итерации содержимого католога */
int directory_options() { return 0; }
/* опции для итерации содержимого католога */
int file_time_type() { return 0; }

/*---------------------------------------------------------------------------------------------------*/

/* составляет абсолютный путь */
int absolute_path() { return 0; }
/* составляет канонический путь */
int canonical_path() { return 0; }
int weakly_canonical_path() { return 0; }
/* копирует файл или католог */
int copy_s() { return 0; }
/* копирует содержимое файла */
int copy_file(const char* input_file, size_t buf_size, const char* output_file, ...) {
    FILE *in, *out;
    char swap[buf_size];

    if((in = fopen(input_file, READ)) == NULL) { 
        return FLS_ERROR;
    }
    if((out = fopen(output_file, APPEND)) == NULL) {
        return FLS_ERROR;
    }

    while(fgets(swap, buf_size, in)) {
        fputs(swap, out);
        if(feof(in)) {
            break;
        }
    }
    fclose(out);
    fclose(in);
    return FLS_SUCCESS;
}
/* копирует символическую ссылку */
int copy_symlink() { return 0; }
/* создает новый католог */
int create_directory(const char* path, const int roots) {
    #ifdef FLS_OS_LINUX
    if(!mkdir(path, roots)) {
        return FLS_SUCCESS;
    }
    return FLS_ERROR;
    #elif FLS_OS_WINDOWS

    #endif

}

/* создает путь из нескольких катологов */
int create_directories(char* path, const int roots) {
    #ifdef FLS_OS_LINUX
    unsigned int i = 0; 
    size_t dir_create = 0;   /* number of directories created */
    size_t err_dir_create = 0; /* number of errors when creating directories */
    char buffer[PATH_MAX] = {0};
    
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
int create_hard_link() { return 0; }
/* создает символическую ссылку */
int create_symlink(const char* from, const char* to) {
    if(!symlink(from, to)) {
        return FLS_SUCCESS;
    }
    return FLS_ERROR;
}
int create_directory_symlink() { return 0; }
/* возвращает или устанавливает текущий рабочий каталог */
int current_path(const char* path, const size_t path_len) { 
    char buffer[path_len];

    if(!*path) { // if path[0] == '\0'
        getcwd(buffer, path_len);
        return FLS_SUCCESS;
    }

    if(chdir(path) == 0) {
        return FLS_SUCCESS;
    }
    return FLS_ERROR;
}
/* проверяет, ссылается ли путь на существующий объект файловой системы */
int file_exists(const char* file) {
    FILE *stream;

    if ((stream = fopen(file, READ)) != NULL) {
        fclose(stream);
        return FILE_EXISTS;
    }
    return FLS_ERROR;
}
/* проверяет, ссылаются ли два пути на один и тот же объект файловой системы */
int equivalent() { return 0; }
/* возвращает размер файла */
int file_size() { return 0; }
/* возвращaет число жестких ссылок на конкретный файл */
int hard_link_count() { return 0; }
/* получает или задает время последней модификации данных */
int last_write_time() { return 0; }
/* получает права доступа к файлу */
int permissions() { return 0; }
/* получает цель символической ссылки */
int read_symlink() { return 0; }
/* удаляет файл или пустой католог */
int remove_file (const char* file) {
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

    char swap_path [PATH_MAX] = {0};
    memcpy(swap_path, path, 4096);
    current_path(swap_path, PATH_MAX);
    
    while((dir = readdir(dir_s)) != NULL) {
        printf("%s\n", dir->d_name);
        remove_file(dir->d_name);
    }
    if(!is_empty(path)) {
        
    }

    // сделать рекурсию основанную на is_empty если директория пуста
    // выйти на уровень ниже и продолжить удаление
    // если уровень == изначальному пути вернуть FLS_SUSCCSE

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
int resize_file() { return 0; }
/* определяет доступное свободное место в файловой системе */
int space() { return 0; }
/* определяет атрибуты файла */
int status() { return 0; }
/* определяет атрибуты файла, проверяя цель символической ссылки */
int symlink_status() { return 0; }
/* возвращает католог, подходящий для временных файлов */
int temp_directory_path() { return 0; }

/*---------------------------------------------------------------------------------------------------*/

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
    long pos = 0;

    if((empty_check = fopen(file, "r")) == NULL) {
        return FLS_ERROR;
    }

    if(!is_directory(file)) {
        fseek(empty_check, 0, SEEK_END);
        if ((pos = ftell(empty_check)) == -1L ||
            (pos = ftell(empty_check)) > 0) {
            fclose(empty_check);
            return FLS_ERROR;
        }
        fclose(empty_check);
        return FLS_SUCCESS;
    }
    fclose(empty_check);
    
    DIR* dir;
    struct dirent* dir_ent;
    unsigned int files_count = 0;

    dir = opendir(file);
    while((dir_ent = readdir(dir)) != NULL) {
        files_count++;
    }
    closedir(dir);

    if(files_count <= 2) {
        return FLS_SUCCESS;
    }

    return FLS_ERROR;
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