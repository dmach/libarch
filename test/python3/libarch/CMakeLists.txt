add_test(NAME test_python3_libarch COMMAND ${Python3_EXECUTABLE} -m unittest WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set_property(TEST test_python3_libarch PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_BINARY_DIR}/bindings/python3")
