#ifndef __part1_h__
#define __part1_h__

#include <cmath>

//Template for integer literal
template <int X>
struct LIT {
    static inline int eval(double a) {
        return X;
    };
};

template <class X, class Y>
struct ADD {
    static inline double eval(double a) {
        return X::eval(a) + Y::eval(a);
    }
};

template <class X, class Y>
struct SUB {
    static inline int eval(double a) {
        return X::eval(a) - Y::eval(a);
    }
};

template <class X, class Y>
struct MULT {
    static inline double eval(double a) {
        return X::eval(a) * Y::eval(a);
    }
};

template <class X, class Y>
struct DIV {
    static inline double eval(double a) {
        return X::eval(a) / Y::eval(a);
    }
};

template <class X, class Y>
struct EXP {
    static inline double eval(double a) {
        return pow(X::eval(a),Y::eval(a));
    }
};

struct VAR {
    static inline double eval(double a) {
        return a;
    }
};

#endif