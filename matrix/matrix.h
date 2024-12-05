#pragma once
#include <iostream>
#include <exception>
#include <cstdlib>

class Matrix
{
    private:
        struct MatrixData;
        MatrixData *data;
        friend void fillData(std::ifstream &file, Matrix::MatrixData *data, size_t rowNum, size_t colNum);
    public:
        ~Matrix();
        Matrix(size_t, size_t);
        Matrix(const Matrix &);
        Matrix(double value);
        Matrix(std::ifstream &);
        double operator()(size_t, size_t) const;
        double &operator()(size_t, size_t);
        Matrix &operator=(const Matrix &);

        Matrix operator*(double scalar) const;
        friend Matrix operator*(double scalar, const Matrix &m);
        Matrix operator*(const Matrix &other) const;
        Matrix operator*=(const Matrix &other);
        friend Matrix operator*=(double scalar, const Matrix &m);

        Matrix operator+(const Matrix &other) const;
        Matrix operator-(const Matrix &other) const;
        Matrix operator-() const;

        Matrix operator+=(const Matrix &other);
        Matrix operator-=(const Matrix &other);

        bool operator==(const Matrix &other) const;
        bool operator!=(const Matrix &other) const;

        size_t getRows() const;
        size_t getCols() const;

        size_t getReferenceCount() const;
        friend std::ostream &operator<<(std::ostream &, const Matrix &);
};

struct Matrix::MatrixData
{
    double **cells;
    size_t rows;
    size_t cols;
    size_t referenceCount;
    MatrixData(size_t, size_t);
    ~MatrixData();
    MatrixData *detach();
};

class MatrixException : public std::exception
{
    std::string msg;
    public:
        MatrixException(std::string msg) : msg("[Matrix Error] " + msg) {}
        const char *what() const noexcept override
        {
            return msg.c_str();
        }
};

class InvalidIndexException : public MatrixException
{
    public:
        InvalidIndexException() : MatrixException("Invalid index") {}
};

class InvalidMatrixSizeException : public MatrixException
{
    public:
        InvalidMatrixSizeException() : MatrixException("Invalid matrix size") {}
};

class InvalidMatrixFileException : public MatrixException
{
public:
    InvalidMatrixFileException(const std::string &msg = "Invalid file") : MatrixException(msg) {}
};

class InvalidMatrixFileDimensionsException : public MatrixException
{
public:
    InvalidMatrixFileDimensionsException(const std::string &msg = "Dimensions in stream matrix must be positive integers") : MatrixException(msg) {}
};