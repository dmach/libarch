if(NOT WITH_PYTHON3)
    return()
endif()


find_package(Python3 REQUIRED)


add_subdirectory(libarch)
