#include <stdio.h>

int mx_strcmp(const char* s1, const char *s2);

int mx_bubble_sort(char **arr, int size){
    char *temp = NULL;
    int swap_cnt = 0;

    for(int i = 1; i < size; i++){
        for(int j = 0; j < size - i; j++){
            if(mx_strcmp(arr[j], arr[j + 1]) > 0){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_cnt++;
            }
        }
    }
    return swap_cnt;
}
