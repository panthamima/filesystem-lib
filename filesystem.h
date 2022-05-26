#ifndef FILESYS_H
#define FILESYS_H

#ifndef FLS_OS_DETECTED
#if defined(__APPLE__) && defined(__MACH__)
#define FLS_OS_MACOS   // not supported
#elif defined(__linux__)
#define FLS_OS_LINUX   // currently being developed 0.1%
#elif defined(__ANDROID__)
#define FLS_OS_ANDROID // not supported
#endif
#elif defined(_WIN32)
#define FLS_OS_WINDOWS // not supported
#define FLS_OS_WIN32   // not supported
#elif defined(_WIN64)
#define FLS_OS_WINDOWS // not supported
#define FLS_OS_WIN64   // not supported
#else
#error "Operating system currently not supported!"
#endif

#ifdef FLS_OS_WINDOWS
#include <windows.h>
/* additional includes */
#include <shellapi.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <wchar.h>
#include <winioctl.h>
#else
#include <dirent.h>
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#endif

//--general libraries--//
#include <string.h>
#include <stdio.h>

/*---------------------------------------------------------------------------------------------------*/
/*                                                                                                   */
/*   All functions returns unsigned value (1, 2, 3, ...) if the action is completed successfully     */
/*                       and 0 if there was some kind of error                                       */
/*                                                                                                   */
/*---------------------------------------------------------------------------------------------------*/

#define READ "r"
#define APPEND "a"
#define TRUNC "w"

/* представляет собой путь */
int path_fls();
/* исключение, вызванное ошибками файловой системы. */
int filesystem_error();
/* запись католога */
int directory_entry();
/* итератор содержимого католога */
int directory_iterator();
/* итератор содержимого католога и его подкатологов */
int recursive_directory_iterator();
/* представляет тип и разрешения файла */
int file_status();
/* информация о свободном и доступном пространстве в файловой системе */
int space_info();
/* тип файла */
int file_type();
/* определяет разрешения файловой системы */
int perms();
/* определяет семантику операций с разрешениями */
int perm_options();
/* определяет семантику операций копирования */
int copy_options();
/* опции для для итерации содержимого католога */
int directory_options();
/* опции для итерации содержимого католога */
int file_time_type();

/*---------------------------------------------------------------------------------------------------*/

/* составляет абсолютный путь */
int absolute_path();
/* составляет канонический путь */
int canonical_path();
int weakly_canonical_path();
/* копирует файлы или катологи */
int copy();
/* копирует содержимое файла */
int copy_file(const char* input_file, size_t buf_size, const char* output_file, ...);
/* копирует символическую ссылку */
int copy_symlink();
/* создает новый католог/катологи */
int create_directory(const char* path, const int roots);
int create_directories(char* path, const int roots);
/* создает жесткую ссылку */
int create_hard_link();
/* создает символическую ссылку */
int create_symlink();
int create_directory_symlink();
/* возвращяет или устанавливает текущий рабочий каталог */
int current_path(const char* path, const size_t path_len);
/* проверяет, ссылается ли путь на существующий объект файловой системы */
int file_exists(const char* file);
/* проверяет, ссылаются ли два пути на один и тот же объект файловой системы */
int equivalent();
/* возвращает размер файла */
int file_size();
/* возвращяет число жестких ссылок на конкретный файл */
int hard_link_count();
/* получает или задает время последней модификации данных */
int last_write_time();
/* получает права доступа к файлу */
int permissions();
/* получает цель символической ссылки */
int read_symlink();
/* удаляет файл или пустой католог */
int remove_file(const char* file);
/* рекурсивно удаляет файл или католог и все его содержимое */
int remove_all(const char* path);
/* перемещает или переименовывает файл или католог */
int rename_file(const char* old, const char* );
/* изменяет размер обычного файла путем усечения или заполнением нулями */
int resize_file();
/* определяет доступное свободное место в файловой системе */
int space();
/* определяет атрибуты файла */
int status();
/* определяет атрибуты файла, проверяя цель символической ссылки */
int symlink_status();
/* возвращает католог, подходящий для временных файлов */
int temp_directory_path();

/*---------------------------------------------------------------------------------------------------*/

#define FLS_ERROR 0
#define FLS_SUCCESS 1

#define BLOCK_FILE 1
#define FIFO_FILE 2
#define SOCKET_FILE 3
#define UNKNOWN_FILE 4
#define DIRECTORY_FILE 5
#define REGULAR_FILE 6
#define CHAR_FILE 7
#define SYMLINK_FILE 8
#define EMPTY_FILE 9
#define FILE_EXISTS 10

/* проверяет, ссылается ли данный путь на блочное устройство */
#if defined(S_ISBLK)
int is_block_file(const char* file);
#endif
/* проверяет, ссылается ли данный путь на символьное устройство */
#if defined(S_ISCHR)
int is_character_file(const char* file);
#endif
/* проверяет, ссылается ли данный путь на католог */
#if defined(S_ISDIR)
int is_directory(const char* file);
#endif
/* проверяет, ссылается ли данный путь на пустой файл или пустой католог */
int is_empty(const char* file);
/* проверяет, ссылается ли данный путь на именованный канал */
#if defined(S_ISFIFO)
int is_fifo(const char* file);
#endif
/* проверяет, ссылается ли данный путь на символическую ссылку */
#if defined(S_ISLNK)
int is_symlink(const char* file);
#endif
/* проверяет, ссылается ли данный путь на аргумент на обычный файл */
#if defined(S_ISREG)
int is_regular_file(const char* file);
#endif
/* проверяет, ссылается ли данный путь на именованный IPC-socket */
#if defined(S_ISSOCK)
int is_socket(const char* file);
#endif
/* проверяет, ссылается ли данный путь на 'другой' файл */
// int is_other(const char* file);
/* проверяет известно ли состояние файла */
int status_known(const char* file);


/*------------------------------------------* my functions *-----------------------------------------*/
/* if mode == hidden(show . and ..) else without . and .. */
int show_all_files_in_directory(const char* path, const int mode);
/* рекурсивно копирует все файлы из директории */
int copy_all_files_in_directory_in_other_directory(const char* old_path, const char* new_path, const int mode);
/*---------------------------------------------------------------------------------------------------*/

#endif //FILESYS_H