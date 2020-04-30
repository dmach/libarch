#include <stdlib.h>
#include <string.h>

#include "libarch/arch.h"

#include "list.h"


// -pedantic-errors option checks if the numbers aren't too small
#define MAX_ARCHES 10


typedef struct _Arch {
    const char * name;
    int bits;
    const char * basearch;
    const char * compatible_native_arches[MAX_ARCHES];
    const char * compatible_multilib_arches[MAX_ARCHES];
    int is_multilib;
    int is_noarch;
    int is_source;
} _Arch;


static struct _Arch arch_list[] = {
    // basearch: aarch64
    {
        .name = "aarch64",
        .bits = 64,
        .basearch = "aarch64",
        .compatible_native_arches = {"aarch64", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },

    // basearch: armhfp
    {
        .name = "armv6hl",
        .bits = 32,
        .basearch = "armhfp",
        .compatible_native_arches = {"armv6hl", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },
    {
        .name = "armv7hl",
        .bits = 32,
        .basearch = "armhfp",
        .compatible_native_arches = {"armv7hl", "armv6hl", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },
    {
        .name = "armv7hnl",
        .bits = 32,
        .basearch = "armhfp",
        .compatible_native_arches = {"armv7hnl", "armv7hl", "armv6hl", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },
    {
        .name = "armv8hl",
        .bits = 32,
        .basearch = "armhfp",
        .compatible_native_arches = {"armv8hl", "armv7hnl", "armv7hl", "armv6hl", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },

    // basearch: i386
    {
        .name = "athlon",
        .bits = 32,
        .basearch = "i386",
        .compatible_native_arches = {"athlon", "i686", "i586", "i486", "i386", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },
    {
        .name = "geode",
        .bits = 32,
        .basearch = "i386",
        .compatible_native_arches = {"geode", "i686", "i586", "i486", "i386", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },
    {
        .name = "i686",
        .bits = 32,
        .basearch = "i386",
        .compatible_native_arches = {"i686", "i586", "i486", "i386", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },
    {
        .name = "i586",
        .bits = 32,
        .basearch = "i386",
        .compatible_native_arches = {"i586", "i486", "i386", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },
    {
        .name = "i486",
        .bits = 32,
        .basearch = "i386",
        .compatible_native_arches = {"i486", "i386", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },
    {
        .name = "i386",
        .bits = 32,
        .basearch = "i386",
        .compatible_native_arches = {"i386", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },

    // basearch: ia64
    {
        .name = "ia64",
        .bits = 64,
        .basearch = "ia64",
        .compatible_native_arches = {"ia64", "noarch", NULL},
        .compatible_multilib_arches = {"i686", "i586", "i486", "i386", NULL},
        .is_multilib = 1,
        .is_noarch = 0,
        .is_source = 0,
    },

    // basearch: ppc
    {
        .name = "ppc",
        .bits = 32,
        .basearch = "ppc",
        .compatible_native_arches = {"ppc", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },

    // basearch: ppc64
    {
        .name = "ppc64",
        .bits = 64,
        .basearch = "ppc64",
        .compatible_native_arches = {"ppc64", "noarch", NULL},
        .compatible_multilib_arches = {"ppc", NULL},
        .is_multilib = 1,
        .is_noarch = 0,
        .is_source = 0,
    },
    {
        .name = "ppc64p7",
        .bits = 64,
        .basearch = "ppc64",
        .compatible_native_arches = {"ppc64p7", "ppc64", "noarch", NULL},
        .compatible_multilib_arches = {"ppc", NULL},
        .is_multilib = 1,
        .is_noarch = 0,
        .is_source = 0,
    },

    // basearch: ppc64le
    {
        .name = "ppc64le",
        .bits = 64,
        .basearch = "ppc64le",
        .compatible_native_arches = {"ppc64le", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },

    // basearch: s390
    {
        .name = "s390",
        .bits = 32,
        .basearch = "s390",
        .compatible_native_arches = {"s390", "noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 0,
    },

    // basearch: s390x
    {
        .name = "s390x",
        .bits = 64,
        .basearch = "s390x",
        .compatible_native_arches = {"s390x", "noarch", NULL},
        .compatible_multilib_arches = {"s390", NULL},
        .is_multilib = 1,
        .is_noarch = 0,
        .is_source = 0,
    },

    // basearch: x86_64
    {
        .name = "amd64",
        .bits = 64,
        .basearch = "x86_64",
        .compatible_native_arches = {"amd64", "x86_64", "noarch", NULL},
        .compatible_multilib_arches = {"athlon", "i686", "i586", "i486", "i386", NULL},
        .is_multilib = 1,
        .is_noarch = 0,
        .is_source = 0,
    },
    {
        .name = "ia32e",
        .bits = 64,
        .basearch = "x86_64",
        .compatible_native_arches = {"ia32e", "x86_64", "noarch", NULL},
        .compatible_multilib_arches = {"athlon", "i686", "i586", "i486", "i386", NULL},
        .is_multilib = 1,
        .is_noarch = 0,
        .is_source = 0,
    },
    {
        .name = "x86_64",
        .bits = 64,
        .basearch = "x86_64",
        .compatible_native_arches = {"x86_64", "noarch", NULL},
        .compatible_multilib_arches = {"athlon", "i686", "i586", "i486", "i386", NULL},
        .is_multilib = 1,
        .is_noarch = 0,
        .is_source = 0,
    },

    // basearch: noarch
    {
        .name = "noarch",
        .bits = 0,
        .basearch = "noarch",
        .compatible_native_arches = {"noarch", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 1,
        .is_source = 0,
    },

    // basaearch: src
    {
        .name = "src",
        .bits = 0,
        .basearch = "src",
        .compatible_native_arches = {"src", "nosrc", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 1,
    },
    {
        .name = "nosrc",
        .bits = 0,
        .basearch = "src",
        .compatible_native_arches = {"src", "nosrc", NULL},
        .compatible_multilib_arches = {NULL},
        .is_multilib = 0,
        .is_noarch = 0,
        .is_source = 1,
    },
};

#define ARCH_LIST_LEN (sizeof(arch_list)/sizeof(*arch_list))

ArchPtr get_arch(const char * name) {
    ArchPtr result = NULL;
    for (size_t i = 0; i < ARCH_LIST_LEN; i++) {
        if (strcmp(arch_list[i].name, name) == 0) {
            result = &arch_list[i];
            break;
        }
    }
    return result;
}


const char * get_arch_name(ArchPtr arch) {
    return arch->name;
}


const char * get_arch_basearch(ArchPtr arch) {
    return arch->basearch;
}


int get_arch_bits(ArchPtr arch) {
    return arch->bits;
}


const char ** get_arch_compatible_native_arches(ArchPtr arch) {
    return arch->compatible_native_arches;
}


const char ** get_arch_compatible_multilib_arches(ArchPtr arch) {
    return arch->compatible_multilib_arches;
}


int get_arch_is_multilib(ArchPtr arch) {
    return arch->is_multilib;
}


int get_arch_is_noarch(ArchPtr arch) {
    return arch->is_noarch;
}


int get_arch_is_source(ArchPtr arch) {
    return arch->is_source;
}


char ** get_basearch_compatible_native_arches(const char * basearch) {
    // arch_list is a superset of all architectures,
    // allocating by it's length + 1 for the NULL terminator should be sufficient
    char ** result = malloc((ARCH_LIST_LEN + 1) * sizeof(char *));
    result[0] = NULL;


    for (size_t i = 0; i < ARCH_LIST_LEN; i++) {
        ArchPtr arch = &arch_list[i];
        if (arch->name == NULL) {
            // ARCH_LIST_LEN is greater than actual array length
            break;
        }
        if (strcmp(arch->basearch, basearch) != 0) {
            // skip architectures with a different basearch
            continue;
        }
        char ** item = (char **)arch->compatible_native_arches;
        while (*item != NULL) {
            if (list_find(result, *item) == -1) {
                list_append(result, *item);
            }
            item++;
        }
    }
    return result;
}


char ** get_basearch_compatible_multilib_arches(const char * basearch) {
    // arch_list is a superset of all architectures,
    // allocating by it's length + 1 for the NULL terminator should be sufficient
    char ** result = malloc((ARCH_LIST_LEN + 1) * sizeof(char *));
    result[0] = NULL;


    for (size_t i = 0; i < ARCH_LIST_LEN; i++) {
        ArchPtr arch = &arch_list[i];
        if (arch->name == NULL) {
            // ARCH_LIST_LEN is greater than actual array length
            break;
        }
        if (strcmp(arch->basearch, basearch) != 0) {
            // skip architectures with a different basearch
            continue;
        }
        char ** item = (char **)arch->compatible_multilib_arches;
        while (*item != NULL) {
            if (list_find(result, *item) == -1) {
                list_append(result, *item);
            }
            item++;
        }
    }
    return result;
}

/*
char ** get_basearch_compatible_multilib_arches(const char * basearch) {
    // arch_list is a superset of all architectures,
    // allocating by it's length + 1 for the NULL terminator should be sufficient
    char ** result = malloc((ARCH_LIST_LEN + 1) * sizeof(char *));
    result[0] = NULL;

    for (int i = 0; i < ARCH_LIST_LEN; i++) {
        ArchPtr arch = &arch_list[i];
        if (arch->name == NULL) {
            // ARCH_LIST_LEN is greater than actual array length
            break;
        }
        if (arch->is_source) {
            continue;
        }
        if (!arch->is_multilib) {
            continue;
        }
        if (arch->is_noarch) {
            // do not append noarch to multilib arches
            continue;
        }
        if (strcmp(arch->basearch, basearch) == 0) {
            list_append(result, arch->name);
        }
    }
    return result;
}
*/
