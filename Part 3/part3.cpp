#include "part3.h"
#include <iostream>

int main() {
    //typedef MULT< VAR, EXP< VAR, LIT<3>>> EXPR;
    //DERIV<EXPR>::R derivative;
    //typedef DIV< ADD<EXP<VAR, LIT<20>>, LIT<3>>, SUB<VAR, LIT<3> > > EXAMPLE;
    typedef EXP<MULT<VAR,LIT<3>>, LIT<2>> EXPONENT;
    DERIV<EXPONENT>::R derivative;  
    std::cout<< derivative.eval(3) << std::endl;

}
