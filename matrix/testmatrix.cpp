#include "matrix.h"
#include <iostream>
#include <fstream>

void testAdditions();
void testSubtraction();
void testMultiplication();
void testNegation();
void testReadWrite();
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
    std::cout << "Testing multiplcations" << std::endl;
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
    std::cout << "m1 * 2 " << std::endl << m1 * 2 << std::endl;
    std::cout << "2 * m1 " << std::endl << 2 * m1 << std::endl;

}

void testNegation()
{
    std::cout << "Testing negation" << std::endl;
    Matrix m(5, 5);
    populateMatrix(m);

    std::cout << "m \n" << m << std::endl;
    std::cout << "-m \n" << -m << std::endl;
}

void testReadWrite()
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

    std::cout << "m(0, 0) " << m(0,0) << std::endl;
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

    try
    {
        Matrix m(file);
        std::cout << "test1.txt \n" << m << std::endl;
    }
    catch (InvalidMatrixFileException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "test2.txt, expected error \n";
    try
    {
        Matrix m(file2);
        std::cout << "Error, exception not thrown." << std::endl;
        //std::cout << m << std::endl;
    }
    catch (MatrixException &e)
    {
        std::cerr << e.what() << std::endl << std::endl;
    }

    try
    {
        Matrix m(file3);
        std::cout << "test3.txt \n" << m << std::endl;
    }
    catch (MatrixException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void testReferenceCounting()
{
    std::cout << "Testing reference counting" << std::endl;
    Matrix m1(3, 3);
    populateMatrix(m1);
    std::cout << "Reference count for m1: " << m1.getReferenceCount() << std::endl;
    Matrix m2(m1);
    std::cout << "m2 created by copying m1" << std::endl;
    std::cout << "Reference count for m1: " << m1.getReferenceCount() << std::endl;
    std::cout << "Reference count for m2: " << m2.getReferenceCount() << std::endl;
    std::cout << std::endl;
    Matrix m3(3,3);
    m3 = m2;
    std::cout << "m3 created by assigning m2 to it" << std::endl;
    std::cout << "Reference count for m1: " << m1.getReferenceCount() << std::endl;
    std::cout << "Reference count for m2: " << m2.getReferenceCount() << std::endl;
    std::cout << std::endl;
    m1(1,1) = 99;
    std::cout << "m1(1,1) has been changed m1 != m2 and m3" << std::endl;
    std::cout << "Reference count for m1: " << m1.getReferenceCount() << std::endl;
    std::cout << "Reference count for m2: " << m2.getReferenceCount() << std::endl;
    std::cout << std::endl;
}


int main()
{
    testAdditions();
    testSubtraction();
    testMultiplication();
    testNegation();
    testReadWrite();
    testDifferentConstructors();
    testFileConstructor();
    testReferenceCounting();

    Matrix a(2,2);
    populateMatrix(a);
    Matrix b(a);
    std::cout << a.getReferenceCount() << std::endl;
    std::cout << b.getReferenceCount() << std::endl;
    std::cout << (a += b) << std::endl;
    std::cout << a.getReferenceCount() << std::endl;
    std::cout << b.getReferenceCount() << std::endl;
}
