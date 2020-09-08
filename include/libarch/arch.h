#ifndef LIBARCH_ARCH_H
#define LIBARCH_ARCH_H


typedef struct _Arch * libarch_arch;


/// Return pointer to Arch or NULL if not found.
///
/// Data ownership: The data is static and MUST NOT be freed.
libarch_arch libarch_get_arch(const char * name);


/// Return name of an Arch.
//
/// Data ownership: The data is static and MUST NOT be freed.
const char * libarch_arch_get_name(libarch_arch arch);


/// Return basearch of an Arch.
//
/// Data ownership: The data is static and MUST NOT be freed.
const char * libarch_arch_get_basearch(libarch_arch arch);


/// Return number of bits of an Arch.
/// Typical values are 64 or 32.
/// If 0 is returned, then the architecture is either noarch or source.
///
/// Data ownership: The data is static and MUST NOT be freed.
int libarch_arch_get_bits(libarch_arch arch);


const char ** libarch_arch_get_compatible_native_arches(libarch_arch arch);
const char ** libarch_arch_get_compatible_multilib_arches(libarch_arch arch);


/// Determine if an Arch is multilib.
int libarch_arch_is_multilib(libarch_arch arch);


/// Determine if an Arch is noarch.
int libarch_arch_is_noarch(libarch_arch arch);


/// Determine if an Arch is source.
int libarch_arch_is_source(libarch_arch arch);


#endif  // LIBARCH_ARCH_H
