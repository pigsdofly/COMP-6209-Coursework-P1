#include <iostream>
#include "part2.h"

int main() {
    typedef ADD<EXP<VAR, LIT<2>>, SUB< MULT< LIT<2>, VAR>, LIT<3>>> POLY;
    POLY p;
    typedef INTEGRATE<0, 10, RECT<POLY>> INTEGRATION;
    INTEGRATION i;

    std::cout << p.eval(3) << std::endl;

    std::cout << "10/200 is: " << 10.0 / 200.0 << std::endl;
    std::cout << "Integrating polynomial over the interval [0,10] with 200 divisions: " << i.integrate(200.0) << std::endl;

    return 0;
}
