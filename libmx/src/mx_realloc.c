#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    unsigned char *newPtr;

    if (!ptr)
        return malloc(size);
    else if (malloc_usable_size(ptr) >= size)               //change function for "malloc_size(ptr) 
        return ptr;
    else if (size == 0) {
        free(ptr);
        return malloc(malloc_usable_size(NULL));            //and here!
    }
    else {
        newPtr = malloc(size);
        mx_memcpy(newPtr, ptr, malloc_usable_size(ptr));    //and here!
        free(ptr);
    }

    return newPtr;
}
