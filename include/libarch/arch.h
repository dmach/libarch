#ifndef LIBARCH_ARCH_H
#define LIBARCH_ARCH_H


//typedef struct Arch * ArchPtr;
//struct Arch;
typedef struct _Arch * ArchPtr;
//typedef struct _arch Arch;


/// Return pointer to Arch or NULL if not found.
///
/// Data ownership: The data is static and MUST NOT be freed.
ArchPtr get_arch(const char * name);


/// Return name of an Arch.
//
/// Data ownership: The data is static and MUST NOT be freed.
const char * get_arch_name(ArchPtr arch);


/// Return basearch of an Arch.
//
/// Data ownership: The data is static and MUST NOT be freed.
const char * get_arch_basearch(ArchPtr arch);


/// Return number of bits of an Arch.
/// Typical values are 64 or 32.
/// If 0 is returned, then the architecture is either noarch or source.
///
/// Data ownership: The data is static and MUST NOT be freed.
int get_arch_bits(ArchPtr arch);


const char ** get_arch_compatible_native_arches(ArchPtr arch);
const char ** get_arch_compatible_multilib_arches(ArchPtr arch);


/// Determine if an Arch is multilib.
int get_arch_is_multilib(ArchPtr arch);


/// Determine if an Arch is noarch.
int get_arch_is_noarch(ArchPtr arch);


/// Determine if an Arch is source.
int get_arch_is_source(ArchPtr arch);


#endif  // LIBARCH_ARCH_H
