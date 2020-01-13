#include "libmx.h"

void matrix_to_final(int **matrix, int size, char **top);
static void valid_one_line(char *str);
static t_mylist *struct_make(int s, int **m, int **d, char **t);
static char **read_file(int n, char **argv);
static void valid_all_line(char *str);

int main(int n, char **argv) {
    char **file_arr;
    char **top;
    int **matrix;
    int size;
    // char *str;

    file_arr = read_file(n, argv);
    // valid_one_line(file_arr[0]);
    size = mx_atoi(file_arr[0]);
    top = mx_check_rd_args(file_arr, size);
    matrix = mx_create_matrix(top, file_arr, size);
    matrix_to_final(matrix, size, top); // tut 10 leaks
    // system("leaks -q pathfinder"); //10 leaks
    return 0;
}

void matrix_to_final(int **matrix, int size, char **top) {
    int **min_dist;
    t_mylist *d;
    
    min_dist = mx_create_dist_matrix(matrix, size);
    d = struct_make(size, matrix, min_dist, top);
    mx_final_print(d);
    free(d);
    // system("leaks -q pathfinder"); //6 leaks
}

static t_mylist *struct_make(int s, int **m, int **d, char **t) {
    t_mylist *data= malloc(sizeof(t_mylist));

    data->size = s;
    data->matrix = m;
    data->dist = d;
    data->top = t;
    return data;
}

static char **read_file(int n, char **argv) {
    char *str;
    char **file;

    if (n != 2) 
        mx_print_error(INVALID_NUMBER, NULL, 0);
    str = mx_file_to_str(argv[1]);
    if (str == NULL)
        mx_print_error(NOT_EXIST, argv, 0);
    if (mx_strlen(str) == 0)
        mx_print_error(EMPTY, argv, 0);
    file = mx_strsplit(str, '\n');
    valid_one_line(file[0]);
    valid_all_line(str);
    free(str);
    return file;
}

static void valid_one_line(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '-')
            mx_print_error(ISLANDS_INVALID, NULL, 0);
        if (mx_isdigit(*str))
            str++;
        else
            mx_print_error(LINE1_INVALID, NULL, 1);
    }
}

static void valid_all_line(char *str) {
    int i = 1;
    int line = 1;
    
    while (str[i] != '\0') {
        if (str[i] == '\n' && str[i + 1] == '\n')
            mx_print_error(LINE_INVALID, NULL, line);
        if (str[i] == '\n')
            line++;
        i++;
    }
    line--;
    if (str[mx_strlen(str) - 1] != '\n') {
        mx_print_error(LINE_INVALID, NULL, line); //line 2 or 8
    }
}
