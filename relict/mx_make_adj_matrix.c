#include "pathfinder.h"

static int **fill_matrix_with_zeros(int verts);

int **mx_make_adj_matrix(t_vertice **adj_list, int verts) {
    int **matrix = fill_matrix_with_zeros(verts);
    bool equal = false;

    for(int i = 0; i < verts; ++i) {
        for(int j = 0; j < verts; ++j) {
            equal = false;
            for(int k = 0; k < adj_list[i]->edges_num; ++k) {
                if(equal)
                    continue;
                if(mx_compare_edge_names(adj_list[i]->edges[k], adj_list[j]->name)) {
                    matrix[i][j] = adj_list[i]->edges[k]->distance;
                    equal = true;
                }
            }
            if(!equal || i == j)
                matrix[i][j] = 0;
        }
    }
    return matrix;
}

static int **fill_matrix_with_zeros(int verts) {
    int **matrix = (int**)malloc(sizeof(int*) * verts);
    for(int i = 0; i < verts; ++i) {
        matrix[i] = (int*)malloc(sizeof(int) * verts);
        for(int j = 0; j < verts; ++j) 
            matrix[i][j] = 0;
    }
    return matrix;
}
