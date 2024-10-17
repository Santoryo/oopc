#include "complex.h"
#include <iostream>

int main()
{
    std::cout << "Testing complex numbers" << std::endl;

    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3;


    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c1 + c2 << std::endl;
    std::cout << "c1 - c2: " << c1 - c2 << std::endl;
    std::cout << "c1 * c2: " << c1 * c2 << std::endl;
    std::cout << "c1 / c2: " << c1 / c2 << std::endl;
    std::cout << "c1 == c2: " << (c1 == c2) << std::endl;
    std::cout << "c1 != c2: " << (c1 != c2) << std::endl;

    std::cout << "c1 + 3.5" << c1 + 3.5 << std::endl;
    std::cout << "a + 7" << c1 + 7 << std::endl;


    return 0;


}