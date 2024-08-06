#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "fetch-line.h"

static char *trim_line(char *s) {
    while (isspace((unsigned char)*s)) {
        s++;
    }
    char *t = s;
    //printf("t = %s\n", t);
    while (t[0] != '\0' && t[0] != '#') {
        t++;
    }
    if (*t == '#') {
        *t = '\0';
    } 
    //printf("t = %s\n", t);
    if (*t != *s) {
        while (isspace((unsigned char)*t)) {
            printf("%s", t);
            *t = '\0';
            t--;
        }
    }
    return s;

}

char *fetch_line(char *buf, int buflen, FILE *stream, int *lineno) {
    char *s;
     if (fgets(buf, buflen, stream) == NULL)
        return NULL;
    ++*lineno;
    if (buf[strlen(buf) - 1] !=  '\n') {
        fprintf(stderr, "*** reading error: input line %d too "
            "long for %s's buf[%d]\n",
            *lineno, __func__, buflen);
        exit(EXIT_FAILURE);
    }
    s = trim_line(buf);
    if (*s != '\0')
        return s;
    else
        return fetch_line(buf, buflen, stream, lineno);
}