#ifndef __part2_h__
#define __part2_h__
#include "part1.h"
#include <iostream>

// integrate function - lower bound, upper bound and divisions. 
// interpolation function 
// trapezoidal rule and rectangle rule
// loops must be statically unrolled
//iterative way
template <class P, int COUNT>
struct RECTUNROLL {
    static inline double eval(double div, double lower) {
        P p;
        double midpoint = (lower + (div + lower))/2;
        return (div * p.eval(midpoint)) + RECTUNROLL<P, COUNT-1>::eval(div, lower+div);
    };
};

template <class P> 
struct RECTUNROLL<P, 0> {
    static inline double eval(double div, double lower) {
        P p;
        double midpoint = (lower + (div + lower))/2;
        return div * p.eval(midpoint);
    };
};

template <class P, int COUNT>
struct RECT {
    static inline double eval(double lower, double higher) {
        double div = (higher - lower) / (double) COUNT;
        P p;

        return RECTUNROLL<P, COUNT>::eval(div, lower);
        /*for (double i = lower; i <= higher; i += div) {
            double midpoint = (i + (div + i))/2;
            sum += div * p.eval(midpoint);
        }
        return sum;*/
    }
};



template <class P>
struct TRAP {};

template <class RULE>
struct INTEGRATE {
    static inline double integrate(double lower, double higher) {
        
        return RULE::eval(lower, higher);
    };
};

#endif
