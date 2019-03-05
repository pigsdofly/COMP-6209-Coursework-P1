#ifndef __part4_h__
#define __part4_h__
#include "part1.h"
#include "part3.h"

// Write a program IntDecl that accepts a polynomial expression and integer X
// Calculates smallest possible primitive type that can be used to declare a var to store both value of polynomial and its derivative

// If/else equivalent templates
template<bool Condition, class Then, class Else> 
struct IntComp {
    typedef Then RET;
};

template<class Then, class Else>
struct IntComp<false, Then, Else> {
    typedef Else RET;
};

template<class P, int X>
struct IntDecl {
    // Comparison between size of P and deriv, split into separate variable because of length
    static const bool deriv_comp = (P::eval(X) > DERIV<P>::eval(X) && P::eval(X) > 0) || 
                                    (P::eval(X) < DERIV<P>::eval(X) && P::eval(X) < 0);

    // Take the larger of P and its derivative and set it to type PP
    typedef typename IntComp< deriv_comp, P, DERIV<P>>::RET PP; 
    

    // Have to do multiple comparisons this way because compiler error with nested IntComps
    typedef typename IntComp<(PP::eval(X) < 65535 && PP::eval(X) > 0), unsigned int, long>::RET uns_comp;
    typedef typename IntComp<(PP::eval(X) > -32768 && PP::eval(X) < 32767), int, uns_comp>::RET int_comp;
    typedef typename IntComp<(PP::eval(X) < 255 && PP::eval(X) > 0), char, int_comp>::RET char_comp;
    typedef typename IntComp<(PP::eval(X) >= 65535), long, char_comp >::RET RET;

};




#endif
