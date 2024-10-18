#include "complex.h"
#include <iostream>

Complex a(1.0, 2.0);
Complex b(3.4, 5.0);
Complex c(5.1, 9.0);

void test()
{
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
    std::cout << "a - b: " << a - b << std::endl;
    std::cout << "a * b: " << a * b << std::endl;
    std::cout << "a / b: " << a / b << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
}

void testEdgeCases()
{
    std::cout << "Testing a += b += c +=" << std::endl;
    std::cout << (a += b += c) << std::endl;
    std::cout << "Testing (a += b) += c" << std::endl;
    std::cout << ((a += b) += c) << std::endl;
    std::cout << "Testing a *= b *= c" << std::endl;
    std::cout << (a *= b *= c) << std::endl;
    std::cout << "Testing (a *= b) *= c" << std::endl;
    std::cout << ((a *= b) *= c) << std::endl;
    std::cout << "Testing a + 7" << std::endl;
    std::cout << (a + 7) << std::endl;

}

int main()
{
    std::cout << "Testing complex numbers" << std::endl;
    std::cout << std::boolalpha;
    test();
    testEdgeCases();


    return 0;


}