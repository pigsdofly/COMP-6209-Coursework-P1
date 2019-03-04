#ifndef __part4_h__
#define __part4_h__
#include "part1.h"
#include "part3.h"

// Write a program IntDecl that accepts a polynomial expression and integer X
// Calculates smallest possible primitive type that can be used to declare a var to store both value of polynomial and its derivative

template<bool Cond, class Then, class Else> 
struct IntComp {
    typedef Then RET;
};

template<class Then, class Else>
struct IntComp<false, Then, Else> {
    typedef Else RET;
};


template<class P, int X, int Y>
struct LessThan {
    static constexpr bool eval() {
        return P::eval(X) < Y;
    }
};

template<class P, int X>
struct IntDecl {
    static const P p;
    typedef typename IntComp<LessThan<P, X, 255>::eval(), char, IntComp<LessThan<P,X,3000>::eval(), int, long>::RET >::RET RET;

};




#endif
