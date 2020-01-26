#include "../inc/pathfinder.h"

void mx_print_distance(t_mylist *d, int *path, int i, int j) {
    int l = 0;
    int tmp;

    while(path[l] != -1)
        l++;
    for (int a = 0; a <= l; a++, l--) {
        tmp = d->matrix[path[l - 1]][path[l - 2]];
        mx_printint(tmp);
        if (a < l - 1)
            mx_printstr(" + ");
    }
    mx_printstr(" = ");
    mx_printint(d->dist[i][j]);
    free(path);
}
