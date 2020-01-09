#include "pathfinder.h"

t_pathfinder *mx_create_pathfinder(void) {
    t_pathfinder *new_pathfinder = malloc(sizeof(t_pathfinder));
    new_pathfinder->temp_distance = 0;
    new_pathfinder->parsed_isls = 0;
    new_pathfinder->isl1 = NULL;
    new_pathfinder->isl2 = NULL;
    new_pathfinder->file_data = NULL;
    return new_pathfinder;
}
