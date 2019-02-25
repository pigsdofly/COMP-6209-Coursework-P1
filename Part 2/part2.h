#ifndef __part2_h__
#define __part2_h__
#include "part1.h"
#include <iostream>

// integrate function - lower bound, upper bound and divisions. 
// interpolation function 
// trapezoidal rule and rectangle rule
// loops must be statically unrolled
//iterative way

template <class P>
struct RECT {
    static inline double eval(double div, int LOWER, int HIGHER) {
        double sum = 0;
        P p;
        //return RECTUNROLL<LOWER>::();
        for (double i = LOWER; i <= HIGHER; i += div) {
            double midpoint = (i + (div + i))/2;
            sum += div * p.eval(midpoint);
        }
        return sum;
    }
};
/*
template <double LOWER>
struct RECTUNROLL {
    static inline double eval(double div, P p) {
        double midpoint = (LOWER + (div + LOWER))/2;
        return (div * p.eval(midpoint)) + RECTUNROLL<LOWER+div>::eval(div, p);
    };
};
*/
template <class P>
struct TRAP {};

template <int LOWER, int HIGHER, class RULE>
struct INTEGRATE {
    static inline double integrate(int divisions) {
        double div = ((double) HIGHER - (double) LOWER) / divisions;
        
        return RULE::eval(div, LOWER, HIGHER);
    };
};

#endif
