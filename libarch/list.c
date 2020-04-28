//#include "arch.h"
//#include <errno.h>
//#include <stdlib.h>
//#include <stddef.h>

#include <string.h>

#include "list.h"


int list_find(char ** list, const char * str) {
    int index = 0;
    char ** item = list;
    while (*item != NULL) {
        if (strcmp(*item, str) == 0) {
            return index;
        }
        item++;
        index++;
    }
    return -1;
}


int list_length(char ** list) {
    int length = 0;
    char ** item = list;
    while (*item != NULL) {
        item++;
        length++;
    }
    return length;
}



void list_append(char ** list, const char * str) {
    int length = list_length(list);

    // length points at the place we're going to insert because we're indexing from 0
    list[length] = (char *)str;
    list[length+1] = NULL;
}
