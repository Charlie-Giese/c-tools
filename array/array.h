#ifndef H_ARRAY_H
#define H_ARRAY_H
#include "xmalloc.h"

#define make_vector(v,n) ((v) = xmalloc((n) * sizeof *(v)))
#define free_vector(v) do { free(v); v = NULL; } while (0)

#define make_matrix(a, m, n) do {                                                           \
    size_t make_matrix_ctr;                                                                 \
    make_vector(a, (m) + 1);                                                                \
    for (make_matrix_ctr = 0; make_matrix_ctr < (m); make_matrix_ctr++) {                   \
        make_vector((a)[make_matrix_ctr], (n));                                             \
    }                                                                                       \
    (a)[m] = NULL;                                                                          \
} while (0)

#define free_matrix(a) do {                                                                 \
    if (a != NULL) {                                                                        \
        size_t free_matrix_ctr;                                                             \
        for (free_matrix_ctr = 0; (a)[free_matrix_ctr] != NULL; free_matrix_ctr++) {        \
            free_vector((a)[free_matrix_ctr]);                                              \
        }                                                                                   \
        free_vector(a);                                                                     \
        a = NULL;                                                                           \
    }                                                                                       \
} while (0)

#define print_vector(fmt, v, n) do {                                                        \
    size_t print_vector_ctr;                                                                \
    for (print_vector_ctr = 0; print_vector_ctr < n; print_vector_ctr++) {                  \
        printf(fmt, (v)[print_vector_ctr]);                                                  \
    }                                                                                       \
    putchar('\n');                                                                          \
} while(0)                                                                                      

#define print_matrix(fmt, a, m, n) do {                                                     \
    size_t print_matrix_ctr;                                                                \
    for(print_matrix_ctr = 0; print_matrix_ctr < m; print_matrix_ctr++) {                   \
        print_vector(fmt, (a)[print_matrix_ctr], n);                                        \
    }                                                                                       \
    putchar('\n');                                                                          \
} while(0)

#endif /* H_ARRAY_h */