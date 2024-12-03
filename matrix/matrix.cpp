#include "matrix.h"
#include <string>
#include <fstream>
#include <sstream>

void readDimensions(std::ifstream &file, size_t &rowNum, size_t &colNum);

Matrix::Matrix(size_t rows, size_t cols)
{
    data = new MatrixData(rows, cols);
}

Matrix::Matrix(const Matrix &other)
{
    data = other.data;
    data->referenceCount++;
}

Matrix::Matrix(double value)
{
    data = new MatrixData(1, 1);
    data->cells[0][0] = value;
}

Matrix::Matrix(std::ifstream &file)
{
    if (file.eof() || file.bad())
    {
        throw InvalidMatrixFileException();
    }

    size_t rowNum, colNum;
    readDimensions(file, rowNum, colNum);

    data = new MatrixData(rowNum, colNum);
    fillData(file, data, rowNum, colNum);
}

void readDimensions(std::ifstream &file, size_t &rowNum, size_t &colNum)
{
    std::string line;
    if (getline(file, line))
    {
        std::istringstream iss(line);
        if (!(iss >> rowNum >> colNum))
        {
            throw InvalidMatrixFileException("Invalid dimensions");
        }
    }
    else
    {
        throw InvalidMatrixFileException("Could not read dimensions");
    }

    if (rowNum <= 0 || colNum <= 0)
    {
        throw InvalidMatrixFileException("Dimensions must be positive");
    }
}

void fillData(std::ifstream &file, Matrix::MatrixData *data, size_t rowNum, size_t colNum)
{
    std::string line;
    size_t currRowNum = 0;
    while (getline(file, line) && currRowNum < rowNum)
    {
        std::istringstream iss(line);
        size_t currColNum = 0;
        double value;

        while (iss >> value)
        {
            if (currColNum >= colNum)
            {
                throw InvalidMatrixFileException("Too many values in a row");
            }

            data->cells[currRowNum][currColNum] = value;
            currColNum++;
        }

        if (currColNum != colNum)
        {
            throw InvalidMatrixFileException("Too few values in a row");
        }

        currRowNum++;
    }

    if (currRowNum != rowNum)
    {
        throw InvalidMatrixFileException();
    }
}

Matrix::~Matrix()
{
    if (--data->referenceCount == 0)
    {
        delete data;
    }
}

Matrix::MatrixData::MatrixData(size_t rows, size_t cols)
{
    this->rows = rows;
    this->cols = cols;
    referenceCount = 1;

    cells = new double *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        cells[i] = new double[cols];
        for (size_t j = 0; j < cols; j++)
        {
            cells[i][j] = 0;
        }
    }

}

Matrix::MatrixData::~MatrixData()
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] cells[i];
    }
    delete[] cells;
}

Matrix::MatrixData *Matrix::MatrixData::detach()
{
    if (referenceCount == 1)
    {
        return this;
    }

    MatrixData *newData = new MatrixData(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            newData->cells[i][j] = cells[i][j];
        }
    }

    referenceCount--;
    return newData;
}

double Matrix::operator()(size_t i, size_t j) const
{
    return data->cells[i][j];
}

double &Matrix::operator()(size_t i, size_t j)
{
    if(i >= data->rows || j >= data->cols)
    {
        throw InvalidIndexException();
    }

    if (data->referenceCount > 1)
    {
        data = data->detach();
    }
    return data->cells[i][j];
}

Matrix &Matrix::operator=(const Matrix &other)
{

    if(this == &other)
    {
        return *this;
    }

    if (--data->referenceCount == 0)
    {
        delete data;
    }

    data = other.data;
    data->referenceCount++;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
    for (size_t i = 0; i < m.data->rows; i++)
    {
        for (size_t j = 0; j < m.data->cols; j++)
        {
            os << m.data->cells[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

Matrix Matrix::operator*(double scalar) const
{
    Matrix result(data->rows, data->cols);
    for (size_t i = 0; i < data->rows; i++)
    {
        for (size_t j = 0; j < data->cols; j++)
        {
            result(i, j) = data->cells[i][j] * scalar;
        }
    }
    return result;
}

Matrix operator*(double scalar, const Matrix &m)
{
    return m * scalar;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    if (data->cols != other.data->rows)
    {
        throw InvalidMatrixSizeException();
    }

    Matrix result(this->getRows(), other.getCols());
    for (size_t i = 0; i < data->rows; i++)
    {
        for (size_t j = 0; j < other.data->cols; j++)
        {
            double sum = 0;
            for (size_t k = 0; k < data->cols; k++)
            {
                sum += data->cells[i][k] * other.data->cells[k][j];
            }
            result(i, j) = sum;
        }
    }
    return result;
}

Matrix Matrix::operator*=(const Matrix &other)
{
    *this = *this * other;
    return *this;
}

Matrix operator*=(double scalar, const Matrix &m)
{
    return m * scalar;
}

size_t Matrix::getRows() const
{
    return data->rows;
}

size_t Matrix::getCols() const
{
    return data->cols;
}

Matrix Matrix::operator+(const Matrix &other) const
{
    if (data->rows != other.data->rows || data->cols != other.data->cols)
    {
        throw InvalidMatrixSizeException();
    }

    Matrix result(data->rows, data->cols);

    for (size_t i = 0; i < data->rows; i++)
    {
        for (size_t j = 0; j < data->cols; j++)
        {
            result(i, j) = data->cells[i][j] + other.data->cells[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const
{
    return *this + (-other);
}

Matrix Matrix::operator+=(const Matrix &other)
{
    *this = *this + other;
    return *this;
}

Matrix Matrix::operator-=(const Matrix &other)
{
    *this = *this - other;
    return *this;
}

Matrix Matrix::operator-() const
{
    Matrix result(data->rows, data->cols);
    for (size_t i = 0; i < data->rows; i++)
    {
        for (size_t j = 0; j < data->cols; j++)
        {
            result(i, j) = -data->cells[i][j];
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix &other) const
{
    if (data->rows != other.data->rows || data->cols != other.data->cols)
    {
        throw InvalidMatrixSizeException();
    }

    for (size_t i = 0; i < data->rows; i++)
    {
        for (size_t j = 0; j < data->cols; j++)
        {
            if (data->cells[i][j] != other.data->cells[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &other) const
{
    return !(*this == other);
}

size_t Matrix::getReferenceCount() const
{
    return data->referenceCount;
}



