message("Building bindings for go: libarch")


foreach(MODULE_NAME ${SWIG_LIBARCH_MODULES})
    add_go_module(libarch ${MODULE_NAME})
endforeach()
