#include "../inc/pathfinder.h"

t_mylist *mx_struct_make(int s, int **m, int **d, char **t) {
    t_mylist *data= malloc(sizeof(t_mylist));

    data->size = s;
    data->matrix = m;
    data->dist = d;
    data->top = t;
    return data;
}
