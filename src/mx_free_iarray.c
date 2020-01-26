#include "../inc/pathfinder.h"

void mx_free_iarray(void **arr, int row) {
    if (arr) {
        for (int a = 0; a < row; a++) {
            if( arr[a]) {
                free(arr[a]);
                arr[a] = NULL;
            }
        }
        free(arr);
        arr = NULL;
    }
}
