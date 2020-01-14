#include "header.h"

static int str_inc_dublenewline(char* file);
static int check_for_newline(char* file);

char *mx_invalid_file(int argc, char *argv[]) {
    int fd = -2;
    char *file = NULL;

    if (argc != 2)
        mx_print_errors(INV_ARGC, NULL);
    fd = open(argv[1], O_RDONLY);
    if (errno)
        mx_print_errors(FILE_NOT_EXIST, argv[1]);
    close(fd);
    file = mx_file_to_str(argv[1]);
    if (!file)
        mx_print_errors(FILE_EMPTY, argv[1]);
    if (str_inc_dublenewline(file) != 0)
        mx_print_errors(INV_LINE, mx_itoa(str_inc_dublenewline(file)));
    if (check_for_newline(file) != 0)
        mx_print_errors(INV_LINE, mx_itoa(check_for_newline(file)));
    return file;
}

static int str_inc_dublenewline(char* file) {
    int line = 0;
    int i = 0;

    while(file[i] != '\0') {
        if (file[i] == '\n') {
            line++;
            if (mx_isdigit(file[i - 1]) == false)
                return line;
        }
        i++;
    }
    line = 0;
    return line;
}

static int check_for_newline(char* file) {
    int i = 0;
    int line = 1;

    while(file[i] != '\0') {
        if (file[i] == '\n')
            line++;
        i++;
    }
    if (file[i - 1] != '\n' && file[i - 2] != '\n')
        return line;
    line = 0;
    return line;
}
