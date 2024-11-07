#include "poly.h"
#include <iostream>

int main()
{
    Poly p1 = 5;
    p1(2.3);

    p1[3] = 21.2;

    Poly p2;

    p2 = 7;
    p2[3] = 1.2;
    p2[2] = -3.2;

    Poly p3 = 0;
    p3[3] = 0;
    p3[2] = 0;

    std::cout << "P1 " << p1 << std::endl;
    std::cout << "P2 " << p2 << std::endl;
    std::cout << "P3 " << p3 << std::endl;

    std::cout << p1 + p2 << std::endl;
    std::cout << p1 - p2 << std::endl;
    std::cout << p1 * p2 << std::endl;
    std::cout << p1 / p2 << std::endl;

}