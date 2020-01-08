#include "pathfinder.h"

void mx_error(t_error error_type, char *filename) {
    switch (error_type) {
        case INVALID_ARG_NUM:
            mx_printerr("usage: ./pathfinder [filename]\n");
            break;
        case INVALID_FIRST_LINE:
            mx_printerr("error: line 1 is not valid\n");
            break;
        case INVALID_ISLANDS_NUM:
            mx_printerr("error: invalid number of islands\n");
            break;
        case NO_FILE:
            mx_printerr("error: file ");
            mx_printerr(filename);
            mx_printerr(" does not exist\n");
            break;
        case EMPTY_FILE:
            mx_printerr("error: file ");
            mx_printerr(filename);
            mx_printerr(" is empty\n");
            break;
        case INVALID_LINE:
            mx_printerr("error: line ");
            mx_printerr(filename);
            mx_printerr(" is not valid\n");
            break;
        case WRONG_POINTER:
            mx_printerr("wrong pointer passed to a function\n");
            break;
        default:
            break;
    }
}
