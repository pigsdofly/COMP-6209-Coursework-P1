#include "part4.h"
#include <iostream>
#include <typeinfo>

int main() {
//    typedef ADD< ADD <MULT <LIT<4>, EXP <VAR, LIT<3>>>, MULT<LIT<2>, EXP<VAR, LIT<2>>>>, LIT<50> > EXPRESSION;
    typedef ADD<LIT<3>, VAR> EXPRESSION;  
    EXPRESSION e;
    IntDecl<EXPRESSION, 0>::RET i;
    
    std::cout << typeid(i).name() << std::endl;

    return 0;
}
