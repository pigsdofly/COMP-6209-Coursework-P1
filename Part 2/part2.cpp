#include <iostream>
#include "part2.h"

int main() {
    typedef ADD<EXP<VAR, LIT<2>>, SUB< MULT< LIT<2>, VAR>, LIT<3>>> POLY;
    typedef INTEGRATE<RECT<POLY, 200>> RECT_INTEGRATION;
    typedef INTEGRATE<TRAP<POLY, 200>> TRAP_INTEGRATION;
    RECT_INTEGRATION i;
    TRAP_INTEGRATION t;
    
    std::cout << "Integrating Polynomial x^2 + 2x -3: " << std::endl;
    std::cout << "Integrating polynomial (rectangle rule) over the interval [0,10] with 200 divisions: " << i.integrate(0.0, 10.0) << std::endl;
    std::cout << "Integrating polynomial (trapezium rule) over the interval [0,10] with 200 divisions: " << t.integrate(0.0, 10.0) << std::endl;
    

    return 0;
}
