#if defined(SWIGPYTHON)
%typemap(out) const char **, char ** {
    PyObject *list = PyList_New(0);

    // pointer to the current item
    char ** item = $1;

    // iterate through all strings until NULL is reached
    while (*item != NULL) {
        // convert char * to python string and append to output
        PyObject * str = PyString_FromString(*item);
        PyList_Append(list, str);
        item++;
    }

    // convert the list to tuple
    PyObject *tuple = PyList_AsTuple(list);

    // the list is no longer needed
    Py_DECREF(list);

    $result = tuple;
}
#endif
