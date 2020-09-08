message("Building bindings for python3: libarch")


file(REMOVE ${CMAKE_CURRENT_BINARY_DIR}/__init__.py)
foreach(MODULE_NAME ${SWIG_LIBARCH_MODULES})
    add_python3_module(libarch ${MODULE_NAME})
    file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/__init__.py "from . import ${MODULE_NAME}\n")
endforeach()


install(FILES ${CMAKE_CURRENT_BINARY_DIR}/__init__.py DESTINATION ${Python3_SITEARCH}/libarch)
