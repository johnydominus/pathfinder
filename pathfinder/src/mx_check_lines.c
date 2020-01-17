#include "pathfinder.h"

static bool check_first_island(char *str, int *iter);
static bool check_sec_island(char *str, int *iter);
static bool check_path(char *str, int *iter);

bool mx_check_lines(char *str, int *iter, int *vertices) {
    int line = 1;

    if (*vertices == 0 && !str[*iter] && !str[*iter + 1])
        return false;
    while (true) {
        ++line;
        if (check_first_island(str, iter) == false
            || check_sec_island(str, iter) == false
            || check_path(str, iter) == false) {
            mx_error(INVALID_LINE, mx_itoa(line));
            return false;
        }
        if (!str[*iter])
            break;
    }
    return true;
}

static bool check_first_island(char *str, int *iter) {
    int temp = *iter;
    while (true) {
        if (mx_isalpha(str[*iter]))
            ++(*iter);
        else if (str[*iter] == '-') {
            if (*iter == temp)
                return false;
            else {
                ++(*iter);
                break;
            }
        }
        else
            return false;
    }
    return true;
}

static bool check_sec_island(char *str, int *iter) {
    int temp = *iter;
    while (true) {
        if (mx_isalpha(str[*iter]))
            ++(*iter);
        else if (str[*iter] == ',') {
            if (*iter == temp)
                return false;
            else {
                ++(*iter);
                break;
            }
        }
        else
            return false;
    }
    return true;
}

static bool check_path(char *str, int *iter) {
    int temp = *iter;
    while (true) {
        if (mx_isdigit(str[*iter]))
            ++(*iter);
        else if (str[*iter] && str[*iter] == '\n') {
            if (*iter == temp)
                return false;
            else {
                ++(*iter);
                break;
            }
        }
        else
            return false;
    }
    return true;
}
