#include <iostream>
#include "part1.h"

int main()
{
    // Create two types for two different expressions
    typedef ADD<VAR, LIT<3>> SUM;
    typedef ADD<EXP<VAR, LIT<4>>, EXP<SUB<VAR, LIT<2>>, LIT<2>>> POLYNOMIAL; 
    SUM s;
    POLYNOMIAL p;
    // Plug numbers into these expressions for x and print them
    std::cout << "x + 3 where x = 3 is: " << s.eval(3) << std::endl;
    std::cout << "x^4 + (x-2)^2 where x = 5 is: " << p.eval(5) << std::endl;
}