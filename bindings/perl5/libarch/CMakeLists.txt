message("Building bindings for perl5: libarch")


foreach(MODULE_NAME ${SWIG_LIBARCH_MODULES})
    add_perl5_module(libarch ${MODULE_NAME})
endforeach()
