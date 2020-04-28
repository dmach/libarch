if(NOT WITH_TESTS)
    return()
endif()


message("Building tests")


# libarch
#add_subdirectory(libarch)

# bindings
#add_subdirectory(go)
#add_subdirectory(perl5)
add_subdirectory(python3)
#add_subdirectory(ruby)
