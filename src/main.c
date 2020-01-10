#include "libmx.h"

void matrix_to_final(int **matrix, int size, char **top);
static void valid_one_line(char *str);
static t_tool *struct_make(int s, int **m, int **d, char **t);
static char **read_file(int n, char **argv);

int main(int n, char **argv) {
    char **file_arr;
    char **top;
    int **matrix;
    int size;

    file_arr = read_file(n, argv);
    valid_one_line(file_arr[0]);
    size = mx_atoi(file_arr[0]);
    top = mx_check_rd_args(file_arr, size);
    matrix = mx_create_matrix(top, file_arr, size);
    matrix_to_final(matrix, size, top);
    return 0;
}

void matrix_to_final(int **matrix, int size, char **top) {
    int **min_dist;
    t_tool *d;

    min_dist = mx_create_dist_matrix(matrix, size);
    d = struct_make(size, matrix, min_dist, top);
    mx_final_print(d);
    free(d);
}

static t_tool *struct_make(int s, int **m, int **d, char **t) {
    t_tool *data= malloc(sizeof(t_tool));
    
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
    free(str);
    return file;
}

static void valid_one_line(char *str) {
    while (*str != '\0') {
        if (mx_isdigit(*str))
            str++;
        else
            mx_print_error(LINE1_INVALID, NULL, 1);
    }
}
