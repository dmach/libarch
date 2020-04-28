#ifndef LIBARCH_LIST_H
#define LIBARCH_LIST_H


/// Return index of a string in string array or -1 if not found
int list_find(char ** list, const char * str);

/// Return length of a string array
int list_length(char ** list);

/// Append string to a string array
void list_append(char ** list, const char * str);


#endif  // LIBARCH_LIST_H
