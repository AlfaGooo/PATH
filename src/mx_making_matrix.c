#include "libmx.h"

static int str_num(char *isl);

int **mx_create_matrix(char **top, char **str, int size) {
    int **mtrx = mx_create_zero_matrix(size);
    int i = 0;
    int j = 0;
    char *word2;

    for (int line = 1; str[line] != NULL; line++, i = 0, j = 0) {
        while (i < size) {
            if (mx_memcmp(str[line], top[i], mx_strlen(top[i])) == 0)
                break;
            i++;
        }
        word2 = mx_memchr(str[line], '-', mx_strlen(str[line]));
        while (j < size) {
            if (mx_memcmp(word2 + 1, top[j], mx_strlen(top[j])) == 0)
                break;
            j++;
        }
        mtrx[i][j] = str_num(str[line]);
        mtrx[j][i] = mtrx[i][j];
    }
    return mtrx;
}

static int str_num(char *isl) {
    int c;

    c = mx_get_char_index(isl, ',') + 1;
    return mx_atoi(&isl[c]);
}
