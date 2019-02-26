#ifndef __part2_h__
#define __part2_h__
#include "part1.h"
#include <iostream>

// integrate function - lower bound, upper bound and divisions. 
// interpolation function 
// trapezoidal rule and rectangle rule
// loops must be statically unrolled

// Loop unrolling template for rectangle rule
template <class P, int COUNT>
struct RECTUNROLL {
    static inline double eval(double div, double lower) {
        double midpoint = (lower + (div + lower))/2;
        return (div * P::eval(midpoint)) + RECTUNROLL<P, COUNT-1>::eval(div, lower+div);
    };
};

// Final template for when COUNT hits 0
template <class P> 
struct RECTUNROLL<P, 0> {
    static inline double eval(double div, double lower) {
        return 0;
    };
};

// Base template for rectangle rule. COUNT parameter represents the divisions and is used for the loop.
// Template exists to calculate the div parameter from COUNT before its fiddled with
template <class P, int COUNT>
struct RECT {
    static inline double eval(double lower, double higher) {
        double div = (higher - lower) / (double) COUNT;
        return RECTUNROLL<P, COUNT>::eval(div, lower);
    }
};

// Loop unrolling template for trapezium rule
template <class P, int COUNT>
struct TRAPUNROLL {
    static inline double eval(double div, double lower) {
        double val = div * ((P::eval(lower) + P::eval(lower + div)) / 2);
        return val + TRAPUNROLL<P, COUNT - 1>::eval(div, lower+div);
    }
};

template <class P>
struct TRAPUNROLL <P, 0> {
    static inline double eval(double div, double lower) {
        return 0;
    }
};

template <class P, int COUNT>
struct TRAP {
    static inline double eval(double lower, double higher) {
        double div = (higher - lower) / (double) COUNT;
        return TRAPUNROLL<P, COUNT>::eval(div, lower);
    }
};

template <class RULE>
struct INTEGRATE {
    static inline double integrate(double lower, double higher) {
        return RULE::eval(lower, higher);
    };
};

#endif
