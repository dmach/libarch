if(NOT (WITH_GO OR WITH_PERL5 OR WITH_PYTHON3 OR WITH_RUBY))
    return()
endif()


message("Building bindings")


find_package(SWIG REQUIRED)
include(UseSWIG)


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    # using 64bit architecture
    set(CMAKE_SWIG_FLAGS "-DSWIGWORDSIZE64")
endif()


include_directories(${CMAKE_SOURCE_DIR}/include)


# SWIG is flooding logs with warnings we can't fix -> turn them off
set(SWIG_COMPILE_OPTIONS
    -Wno-cast-align
    -Wno-conversion
    -Wno-deprecated-declarations
    -Wno-missing-declarations
    -Wno-missing-field-initializers
    -Wno-pedantic
    -Wno-redundant-decls
    -Wno-sign-compare
    -Wno-strict-aliasing
    -Wno-unused-function
    -Wno-unused-parameter
)


# list of all modules that will be included in libarch bindings
list(APPEND SWIG_LIBARCH_MODULES arch)
list(APPEND SWIG_LIBARCH_MODULES basearch)


add_subdirectory(go)
add_subdirectory(perl5)
add_subdirectory(python3)
add_subdirectory(ruby)
