#include <stdio.h>
#include "xmalloc.h"

void *malloc_or_exit(size_t nbytes, const char *file, int line) {
    void *x;

    if (nbytes == 0) {
        fprintf(stderr, "%s:line %d: can't allocate 0 bytes\n", 
                file, line);
    }

    if ((x = malloc(nbytes)) == NULL) {
        fprintf(stderr, "%s:line %d: malloc() of %zu bytes failed\n", 
                file, line, nbytes);
        exit(EXIT_FAILURE);
    } else
        return x;
}