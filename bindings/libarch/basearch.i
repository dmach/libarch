%module basearch


%include <typedefs.i>


%{
    // make SWIG wrap following headers
    #include "libarch/basearch.h"
%}


#define CV __perl_CV
%include "libarch/basearch.h"
