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
/*
template <class P, int X, int Y> 
struct GREATERTHAN {
    enum {RET= P::eval(X) > Y};

    static inline bool eval() {
        return false;
    }
};
*/
template<class P, int X>
struct IntDecl {
//    enum {value = (int) P::eval(X)};
    static const P p;

    using RET = typename IntComp<p.eval(X) < 3, char, IntComp<(26 > 3), int, long>::RET>::RET;

};




#endif
