#include "part4.h"
#include <iostream>
#include <typeinfo>

int main() {
    typedef ADD< ADD <MULT <LIT<4>, EXP <VAR, LIT<3>>>, MULT<LIT<2>, EXP<VAR, LIT<2>>>>, LIT<50> > EXPRESSION;
    EXPRESSION e;
    
    IntDecl<EXPRESSION, 0>::RET id;
    IntDecl<EXPRESSION, 10>::RET id2;
    IntDecl<EXPRESSION, 100>::RET id3;

    std::cout << typeid(id).name() << std::endl;
    std::cout << typeid(id2).name() << std::endl;
    std::cout << typeid(id3).name() << std::endl;

    return 0;
}
