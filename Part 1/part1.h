#ifndef __part1_h__
#define __part1_h__

#include <cmath>

// Template for integer literal
template <int X>
struct LIT {
    // double parameter not used but there so that its compatible with other expressions
    static inline int eval(double a) {
        return X;
    };
};

// Template for a polynomial variable
struct VAR {
    static inline double eval(double a) {
        return a;
    }
};

// Templates for mathematical expressions (plus, minus, multiply, divide, exponentiate)
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
        // Using cmath pow function for exponentiation
        return pow(X::eval(a),Y::eval(a));
    }
};


#endif