#ifndef __part3_h__
#define __part3_h__

#include "part1.h"
template<class C>
struct DERIV {};

// Templates use typedef to create new types based on the types given
template <class n, class t>
struct DERIV<EXP<n, t>> {

    typedef MULT<EXP<n,SUB<t,LIT<1>>>,t> R;
    
    // If this template is called recursively, evaluate the above type R
    static inline double eval(double i) {
        return R::eval(i);
    }
};


template <class n, class t>
struct DERIV<MULT<n, t>> {
    typedef ADD<MULT<DERIV<n>, t>,MULT<n, DERIV<t>>> R;
    
    static inline double eval(double i) {
        return R::eval(i);
    }
};
/*
template <class n, class t>
struct DERIV<DIV<n, t>> {
    enum {RET = ADD<MULT<DERIV<n>::RET, t>, MULT<n, DERIV<t>::RET>>};
    typedef DIV< SUB < MULT < t,DERIV<n> >, MULT < t, DERIV<t> >,EXP<t,LIT<2>> R;
    static inline double eval(double i) {
        return R::eval(i);
    }
};

template<class n, class t>
struct DERIV<ADD<n, t>> {
    enum {RET = ADD<MULT<DERIV<n>::RET, t>, MULT<n, DERIV<t>::RET>>};
    typedef ADD<DERIV<n>, DERIV<t>> R;
    static inline double eval(double i) {
        return R::eval(i);
    }
};

template<class n, class t>
struct DERIV<SUB<n, t>> {
    enum {RET = ADD<MULT<DERIV<n>::RET, t>, MULT<n, DERIV<t>::RET>>};
    typedef SUB<DERIV<n>, DERIV<t>> R;
    static inline double eval(double i) {
        return R::eval(i);
    }
};
*/
template<>
struct DERIV<VAR> {
    typedef LIT<1> R;

    static inline int eval(double m) {
        return R::eval(m);
    }
};

template <int n>
struct DERIV<LIT<n>> {
    typedef LIT<0> R;

    static inline int eval(double m) {
        return R::eval(m);
    }
};

#endif
