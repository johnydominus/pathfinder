#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    unsigned char *newPtr;

    if (!ptr)
        return malloc(size);
    else if (malloc_usable_size(ptr) >= size) 
        return ptr;
    else if (size == 0) {
        free(ptr);
        return malloc(malloc_usable_size(NULL));
    }
    else {
        newPtr = malloc(size);
        mx_memcpy(newPtr, ptr, malloc_usable_size(ptr));
        free(ptr);
    }

    return newPtr;
}
