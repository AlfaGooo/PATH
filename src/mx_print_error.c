#include "../inc/pathfinder.h"

static void invalid_err(enum e_eror errors, int i);

void mx_print_error(enum e_eror errors, char **a, int i) {
    if (errors == NOT_EXIST) {
        mx_printerr("error: file ");
        mx_printerr(a[1]);
        mx_printerr(" does not exist\n");
    }
    else if (errors == EMPTY) {
        mx_printerr("error: file ");
        mx_printerr(a[1]);
        mx_printerr(" is empty\n");
    }
    invalid_err(errors, i);
    exit(1);
}

static void invalid_err(enum e_eror errors, int i) {
    if (errors == INVALID_NUMBER) {
        mx_printerr("usage: ./pathfinder [filename]\n");
    }
    else if (errors == LINE1_INVALID) {
        mx_printerr("error: line 1 is not valid\n");
    }
    else if (errors == LINE_INVALID) {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(i + 1));
        mx_printerr(" is not valid\n");
    }
    else if (errors == ISLANDS_INVALID)
        mx_printerr("error: invalid number of islands\n");
}
