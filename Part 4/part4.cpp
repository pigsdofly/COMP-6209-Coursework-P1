#include "part4.h"
#include <iostream>
#include <typeinfo>

int main() {
    // 4(x^3) + 2(x^2) + 50
    typedef ADD< ADD <MULT <LIT<4>, EXP <VAR, LIT<3>>>, MULT<LIT<2>, EXP<VAR, LIT<2>>>>, LIT<50> > EXPRESSION;

    IntDecl<EXPRESSION, -30>::RET id;
    IntDecl<EXPRESSION, -20>::RET id2;
    IntDecl<EXPRESSION, -10>::RET id3;
    IntDecl<EXPRESSION, 0>::RET id4;
    IntDecl<EXPRESSION, 10>::RET id5;
    IntDecl<EXPRESSION, 20>::RET id6;

    // Type names as returned by typeid.name may require piping to 'c++filt' to get the full names
    std::cout << "Value for polynomial with -30: "<< EXPRESSION::eval(-30) << "\nType for polynomial with -30: " << typeid(id).name() << std::endl;
    std::cout << "Value for polynomial with -20: "<< EXPRESSION::eval(-20) << "\nType for polynomial with -20: " << typeid(id2).name() << std::endl;
    std::cout << "Value for polynomial with -10: "<< EXPRESSION::eval(-10) << "\nType for polynomial with -10: " << typeid(id3).name() << std::endl;
    std::cout << "Value for polynomial with 0: "<< EXPRESSION::eval(0) << "\nType for polynomial with 0: " << typeid(id4).name() << std::endl;
    std::cout << "Value for polynomial with 10: "<< EXPRESSION::eval(10) << "\nType for polynomial with 10: " << typeid(id5).name() << std::endl;
    std::cout << "Value for polynomial with 20: "<< EXPRESSION::eval(20) << "\nType for polynomial with 20: " << typeid(id6).name() << std::endl;

    return 0;
}
