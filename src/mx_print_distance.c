#include "libmx.h"

void mx_print_distance(t_tool *d, int *path, int i, int j) {
    int l = 0;

    while(path[l] != -1)
        l++;
    for (int a = 0; a <= l; a++, l--) {
        mx_printint(d->matrix[path[l - 1]][path[l - 2]]);
        if (a < l - 1)
            mx_printstr(" + ");
    }
    mx_printstr(" = ");
    mx_printint(d->dist[i][j]);
}
