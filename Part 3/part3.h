#ifndef __part3_h__
#define __part3_h__

#include "part1.h"
// Base template
template<class C>
struct DERIV {};

// These templates use typedefs so that we can represent the final derivative expression as a type to input values into.
// dy/dx for x^y
template <class X, class Y>
struct DERIV<EXP<X, Y>> {
    typedef MULT<EXP<X,SUB<Y,LIT<1>>>,Y> R;
    // If this template is called recursively, evaluate the above type R
    static inline double eval(double a) {
        return R::eval(a);
    }
};

// dy/dx for x*y
template <class X, class Y>
struct DERIV<MULT<X, Y>> {
    typedef ADD<MULT<DERIV<X>, Y>,MULT<X, DERIV<Y>>> R;
    
    static inline double eval(double a) {
        return R::eval(a);
    }
};

// dy/dx for x/y
template <class X, class Y>
struct DERIV<DIV<X, Y>> {
    typedef DIV < SUB <MULT <Y, DERIV<X> >, MULT<X, DERIV<Y> > >, EXP <Y, LIT<2> > > R;
    
    static inline double eval(double a) {
        return R::eval(a);
    }
};

// dy/dx for x + y
template<class X, class Y>
struct DERIV<ADD<X, Y>> {
    typedef ADD<DERIV<X>, DERIV<Y>> R;

    static inline double eval(double a) {
        return R::eval(a);
    }
};

// dy/dx for x - y
template<class X, class Y>
struct DERIV<SUB<X, Y>> {
    typedef SUB<DERIV<X>, DERIV<Y>> R;
    
    static inline double eval(double a) {
        return R::eval(a);
    }
};

// dy/dx for x
template<>
struct DERIV<VAR> {
    typedef LIT<1> R;

    static inline double eval(double a) {
        return R::eval(a);
    }
};

// dy/dx for literal
template <int X>
struct DERIV<LIT<X>> {
    typedef LIT<0> R;

    static inline double eval(double a) {
        return R::eval(a);
    }
};

#endif
