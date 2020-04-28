%module arch


%include <typedefs.i>


%{
    // make SWIG wrap following headers
    #include "libarch/arch.h"
%}


#define CV __perl_CV
%include "libarch/arch.h"
