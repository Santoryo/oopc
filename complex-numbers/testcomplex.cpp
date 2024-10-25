#include "complex.h"
#include <iostream>

Complex a, b, c;

void reset()
{
    a = Complex(21.0, 12.0);
    b = Complex(12.0, 2.0);
    c = Complex(53.0, 4.0);
}

void displayCategory(const std::string& category)
{
    std::cout << "====================" << std::endl;
    std::cout << category << std::endl;
    std::cout << "====================" << std::endl;
}

void test(const std::string& testName, const Complex& result)
{
    reset();
    std::cout << testName << ": " << result << std::endl;
}

void test(const std::string& testName, bool result)
{
    reset();
    std::cout << testName << ": " << result << std::endl;
}

void test(const std::string& testName, double result)
{
    reset();
    std::cout << testName << ": " << result << std::endl;
}

void testDisplayOperations()
{
    displayCategory("Display operations");
    test("a", a);
    test("b", b);
    test("c", c);
}

void testAdditionCases()
{
    displayCategory("Addition cases");
    test("a + b", a + b);
    test("a + 7", a + 7);
    test("7 + a", 7 + a);
    test("a += b += c", a += b += c);
    test("(a += b) += c", (a += b) += c);

}

void testSubstractionCases()
{
    displayCategory("Substraction cases");
    test("a - b", a - b);
    test("a - 7", a - 7);
    test("7 - a", 7 - a);
    test("a -= b -= c", a -= b -= c);
    test("(a -= b) -= c", (a -= b) -= c);
}

void testMultiplicationCases()
{
    displayCategory("Multiplication cases");
    test("a * b", a * b);
    test("a * 7", a * 7);
    test("7 * a", 7 * a);
    test("a *= b *= c", a *= b *= c);
    test("(a *= b) *= c", (a *= b) *= c);
}

void testComparisionCases()
{
    displayCategory("Comparision cases");
    test("c == 3.5", c == 3.5);
    test("3.5 == c", 3.5 == c);
    test("a == b", a == b);
    test("a != 3.2", a != 3.2);
    test("3.2 != a", 3.2 != a);
    test("a != b", a != b);
    test("c == b", c == b);
}

void testDivisionCases()
{
    displayCategory("Division cases");
    test("a / b", a / b);
    test("a / 7", a / 7);
    test("7 / a", 7 / a);
    test("a /= b", a /= b);
}

void testAmplitudes()
{
    displayCategory("Amplitude cases");
    test("a.amplitude()", a.amplitude());
    test("b.amplitude()", b.amplitude());
    test("c.amplitude()", c.amplitude());
}

void testPhases()
{
    displayCategory("Phase cases");
    test("a.phase()", a.phase());
    test("b.phase()", b.phase());
    test("c.phase()", c.phase());
}

int main()
{   
    std::cout << "Testing complex numbers" << std::endl;
    std::cout << std::boolalpha;

    testDisplayOperations();
    testAdditionCases();
    testSubstractionCases();
    testMultiplicationCases();
    testComparisionCases();
    testDivisionCases();
    testAmplitudes();
    testPhases();

    return 0;
}