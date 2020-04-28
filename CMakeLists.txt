message("Running CMake on libarch...")
cmake_minimum_required(VERSION 3.5)


include(VERSION.cmake)
project(libarch LANGUAGES C VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
cmake_policy(VERSION ${CMAKE_VERSION})


message("Building ${PROJECT_NAME} version ${PROJECT_VERSION}")


if(DEFINED PACKAGE_VERSION)
    if(NOT ${PACKAGE_VERSION} STREQUAL ${PROJECT_VERSION})
        message(FATAL_ERROR "Variables PROJECT_VERSION and PACKAGE_VERSION differ. Make sure the versions in VERSION.cmake and the value provided via -DPACKAGE_VERSION are in sync.")
    endif()
endif()


# build options - documentation
option(WITH_HTML "Build HTML documentation" ON)
option(WITH_MAN "Build man pages" ON)

# build options - tests
option(WITH_TESTS "Build tests" ON)

# build options - debugging
option(WITH_SANITIZERS "Build with address, leak and undefined sanitizers (DEBUG ONLY)" OFF)

# build options - bindings
option(WITH_GO "Build Go bindings" ON)
option(WITH_PERL5 "Build Perl 5 bindings" ON)
option(WITH_PYTHON3 "Build Python 3 bindings" ON)
option(WITH_RUBY "Build Ruby bindings" ON)


# includes
include(GNUInstallDirs)


# common dependencies
find_package(PkgConfig REQUIRED)

#set(CMAKE_LINKER_LANGUAGE C)

# C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# warnings
add_compile_options(-Wall -Wextra)
add_compile_options(-Werror)
add_compile_options(-Wcast-align -Wformat-nonliteral -Wmissing-format-attribute -Wredundant-decls -Wsign-compare -Wtype-limits -Wuninitialized -Wwrite-strings)
# not sure about the conversion warnings being errors; review later
add_compile_options(-Wconversion)
# -pedantic-errors monitors array sizes
add_compile_options(-pedantic-errors)


# linker options
if(NOT CMAKE_C_COMPILER_ID MATCHES "Clang")
    # clang doesn't support this option
    add_compile_options(-Wl,--as-needed)
endif()


if(WITH_SANITIZERS)
    message(WARNING "Building with sanitizers enabled!")
    set(SANITIZER_FLAGS "-fsanitize=address -fsanitize=leak -fsanitize=undefined")
    if(CMAKE_C_COMPILER_ID MATCHES "Clang")
        # requires: compiler-rt package on Fedora
        set(SANITIZER_FLAGS "${SANITIZER_FLAGS} -static-libsan")
    else()
        set(SANITIZER_FLAGS "${SANITIZER_FLAGS} -static-libasan -static-liblsan -static-libubsan")
    endif()
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${SANITIZER_FLAGS}")
endif()


include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}")


add_subdirectory("include")
add_subdirectory("libarch")
add_subdirectory("doc")
add_subdirectory("bindings")

# tests
enable_testing()
add_subdirectory("test")
