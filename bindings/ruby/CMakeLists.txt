if(NOT WITH_RUBY)
    return()
endif()


message("Building bindings for ruby")


find_package(Ruby REQUIRED)
include_directories(${RUBY_INCLUDE_DIRS})


function(add_ruby_module LIBRARY_NAME MODULE_NAME)
    set(TARGET_NAME "ruby_${MODULE_NAME}")
    set_property(SOURCE ../../${LIBRARY_NAME}/${MODULE_NAME}.i PROPERTY SWIG_MODULE_NAME ${MODULE_NAME})
    set(CMAKE_SWIG_FLAGS -module ${MODULE_NAME} -ruby)
    swig_add_library(${TARGET_NAME} LANGUAGE ruby SOURCES ../../${LIBRARY_NAME}/${MODULE_NAME}.i)
    set_property(TARGET ${TARGET_NAME} PROPERTY OUTPUT_NAME ${MODULE_NAME})
    target_compile_options(${TARGET_NAME} PUBLIC ${SWIG_COMPILE_OPTIONS})
    set_target_properties("${TARGET_NAME}" PROPERTIES LINKER_LANGUAGE C)

    string(REPLACE "_" "-" C_LIBRARY_NAME ${LIBRARY_NAME})
    swig_link_libraries(${TARGET_NAME} ${C_LIBRARY_NAME})
    swig_link_libraries(${TARGET_NAME} ${RUBY_LIBRARIES})

    install(TARGETS ${TARGET_NAME} LIBRARY DESTINATION "${RUBY_VENDORARCH_DIR}/${LIBRARY_NAME}")
endfunction()


add_subdirectory(libarch)
