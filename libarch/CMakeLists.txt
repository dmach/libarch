# use any sources found under the current directory
file(GLOB_RECURSE LIBARCH_SOURCES *.c)


# build libarch.so
add_library(libarch SHARED ${LIBARCH_SOURCES})
set_target_properties(libarch PROPERTIES LINKER_LANGUAGE C)
set_target_properties(libarch PROPERTIES OUTPUT_NAME "arch")
set_target_properties(libarch PROPERTIES SOVERSION 0)


# install libarch.so
install(TARGETS libarch LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})


# create a .pc file
configure_file("libarch.pc.in" ${CMAKE_CURRENT_BINARY_DIR}/libarch.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libarch.pc DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}/pkgconfig)
