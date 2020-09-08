#ifndef LIBARCH_BASEARCH_H
#define LIBARCH_BASEARCH_H


/// Return list of native architectures compatible with a given basearch.
/// Order of items in the result has no special meaning.
///
/// Data ownership: The returned list MUST be freed. The individual list items are static and MUST NOT be freed.
char ** libarch_basearch_get_compatible_native_arches(const char * basearch);


/// Return list of multilib architectures compatible with a given basearch.
/// Order of items in the result has no special meaning.
///
/// Data ownership: The returned list MUST be freed. The individual list items are static and MUST NOT be freed.
char ** libarch_basearch_get_compatible_multilib_arches(const char * basearch);


#endif  // LIBARCH_BASEARCH_H
