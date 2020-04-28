message("Building bindings for ruby: libarch")


foreach(MODULE_NAME ${SWIG_LIBARCH_MODULES})
    add_ruby_module(libarch ${MODULE_NAME})
endforeach()
