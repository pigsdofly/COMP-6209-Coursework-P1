#include "part3.h"
#include <iostream>

int main() {
    // (x^20 + 3) / (x - 3)
    typedef DIV< ADD<EXP<VAR, LIT<20>>, LIT<3>>, SUB<VAR, LIT<3>>> EXAMPLE;
    DERIV<EXAMPLE>::R derivative;

    std::cout<< derivative.eval(5) << std::endl;
    std::cout<< derivative.eval(10) << std::endl;

}
