#include "matrix.h"
#include <iostream>
#include <fstream>

void testAdditions();
void testSubtraction();
void testMultiplication();
void testNegation();
void testDetachment();
void testDifferentConstructors();
void testFileConstructor();
void populateMatrix(Matrix &m);

void populateMatrix(Matrix &m)
{
    for (size_t i = 0; i < m.getRows(); i++)
    {
        for (size_t j = 0; j < m.getCols(); j++)
        {
            m(i, j) = i * m.getCols() + j;
        }
    }
}

void testAdditions()
{
    std::cout << "Testing additions" << std::endl;
    Matrix m1(2, 2), m2(2, 2), m3(2, 3);
    populateMatrix(m1);
    populateMatrix(m2);
    populateMatrix(m3);

    std::cout << "m1 \n" << m1 << std::endl;
    std::cout << "m2 \n" << m2 << std::endl;
    std::cout << "m3 \n" << m3 << std::endl;

    std::cout << "m1 + m3, expected exception" << std::endl;
    try
    {
        m1 + m3;
    }
    catch (InvalidMatrixSizeException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "m1 + m2 " << std::endl << m1 + m2 << std::endl;
    std::cout << "m1 += m2 " << std::endl << (m1 += m2) << std::endl;

    std::cout << "m1 \n" << m1 << std::endl;
}

void testSubtraction()
{
    std::cout << "Testing substractions" << std::endl;
    Matrix m1(2, 2), m2(2, 2), m3(2, 3);
    populateMatrix(m2);
    m1 = m2 * 3;
    populateMatrix(m3);

    std::cout << "m1 \n" << m1 << std::endl;
    std::cout << "m2 \n" << m2 << std::endl;
    std::cout << "m3 \n" << m3 << std::endl;

    std::cout << "m1 - m3, expected exception" << std::endl;
    try
    {
        m1 - m3;
    }
    catch (InvalidMatrixSizeException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "m1 - m2 " << std::endl << m1 - m2 << std::endl;
    std::cout << "m1 -= m2 " << std::endl << (m1 -= m2) << std::endl;

    std::cout << "m1 \n" << m1 << std::endl;
}

void testMultiplication()
{
    std::cout << "Testing additions" << std::endl;
    Matrix m1(2, 2), m2(2, 2), m3(2, 3);

    populateMatrix(m1);
    populateMatrix(m2);
    populateMatrix(m3);

    std::cout << "m1 \n" << m1 << std::endl;
    std::cout << "m2 \n" << m2 << std::endl;
    std::cout << "m3 \n" << m3 << std::endl;

    std::cout << "m1 * m3 \n" << m1 * m3 << std::endl;

    std::cout << "m1 * m2 " << std::endl << m1 * m2 << std::endl;
    std::cout << "m1 *= m2 " << std::endl << (m1 *= m2) << std::endl;
    std::cout << "m1 * 2 " << std::endl << m1 * 3.14 << std::endl;
    std::cout << "2 * m1 " << std::endl << 3.14 * m1 << std::endl;

}

void testNegation()
{
    std::cout << "Testing negation" << std::endl;
    Matrix m(5, 5);
    populateMatrix(m);

    std::cout << "m \n" << m << std::endl;
    std::cout << "-m \n" << -m << std::endl;
}

void testDetachment()
{
    std::cout << "Testing detachment" << std::endl;
    Matrix m(2, 2);
    populateMatrix(m);

    std::cout << "m \n" << m << std::endl;
    Matrix m2 = m;
    std::cout << "m2 \n" << m2 << std::endl;
    m(0, 0) = 100;
    std::cout << "m \n" << m << std::endl;
    std::cout << "m2 \n" << m2 << std::endl;
}

void testDifferentConstructors()
{
    std::cout << "Testing different constructors" << std::endl;
    Matrix m1(2, 2);
    populateMatrix(m1);
    std::cout << "Normal constructor \n" << m1 << std::endl;

    Matrix m2(m1);
    std::cout << "Copy constructor \n" << m2 << std::endl;

    Matrix m3(2, 2);
    m3 = m1;
    std::cout << "Assignment operator \n" << m3 << std::endl;

    Matrix m4(10);
    std::cout << "Single value constructor \n" << m4 << std::endl;
}

void testFileConstructor()
{
    std::cout << "Testing file constructor" << std::endl;
    std::ifstream file("test1.txt");
    std::ifstream file2("test2.txt");
    std::ifstream file3("test3.txt");

    try {
        Matrix m(file);
        std::cout << "test1.txt \n" << m << std::endl;
    } catch (InvalidMatrixFileException &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "test2.txt, expected error \n";
        Matrix m(file2);
        std::cout << m << std::endl;
    } catch (InvalidMatrixFileException &e) {
        std::cerr << e.what() << std::endl << std::endl;
    }

    try {
        Matrix m(file3);
        std::cout << "test3.txt \n" << m << std::endl;
    } catch (InvalidMatrixFileException &e) {
        std::cerr << e.what() << std::endl;
    }
}


int main()
{
    testAdditions();
    testSubtraction();
    testMultiplication();
    testNegation();
    testDetachment();
    testDifferentConstructors();
    testFileConstructor();
}
