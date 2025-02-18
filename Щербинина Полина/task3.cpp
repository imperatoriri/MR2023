#include <iostream>
#include <stdexcept>

#include "matrix.hpp"

template <typename Type>
Matrix<Type>::Matrix(std::initializer_list<std::initializer_list<Type>> matrix)
    : rows(matrix.size()), cols(rows > 0 ? matrix.begin()->size() : 0)
{
    for (const auto &mat : matrix)
    {
        std::vector<Type> row(mat);
        elements.push_back(row);
    }
}

template <typename Type>
Matrix<Type>::Matrix(unsigned int _rows, unsigned int _cols, Type _init)
    : rows(_rows), cols(_cols)
{
    elements.resize(_rows, std::vector<Type>(_cols, _init));
}

template <typename Type>
Matrix<Type>::Matrix(std::initializer_list<Type> matrix)
    : rows(1), cols(matrix.size())
{
    std::vector<Type> row(matrix);
    elements.push_back(row);
}

template <typename Type>
Matrix<Type>::Matrix(unsigned _size)
    : rows(_size), cols(_size)
{
    elements.resize(_size, std::vector<Type>(_size, Type{0}));

    for (unsigned i = 0; i < _size; i++)
        elements[i][i] = Type{1};
}

template <typename Type>
Matrix<Type>::Matrix(const Matrix<Type> &original)
    : elements(original.elements), rows(original.rows), cols(original.cols)
{
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(const Matrix<Type> &right)
{
    if (&right == this)
        return *this;

    unsigned int new_rows = right.rows;
    unsigned int new_cols = right.cols;

    elements = right.elements;
    rows = new_rows;
    cols = new_cols;

    return *this;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator+(const Matrix<Type> &right) const
{
    if (rows != right.rows || cols != right.cols)
        throw std::invalid_argument("Matrix addition requires matrices of the same dimensions.");

    Matrix result(rows, cols, elements[0][0]);

    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            result.elements[i][j] = elements[i][j] + right.elements[i][j];

    return result;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator+=(const Matrix<Type> &right)
{
    if (rows != right.rows || cols != right.cols)
        throw std::invalid_argument("Matrix addition requires matrices of the same dimensions.");

    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            elements[i][j] += right.elements[i][j];

    return *this;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator-(const Matrix<Type> &right) const
{
    if (rows != right.rows || cols != right.cols)
        throw std::invalid_argument("Matrix subtraction requires matrices of the same dimensions.");

    Matrix result(rows, cols, elements[0][0]);

    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            result.elements[i][j] = elements[i][j] - right.elements[i][j];

    return result;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator-=(const Matrix<Type> &right)
{
    if (rows != right.rows || cols != right.cols)
        throw std::invalid_argument("Matrix subtraction requires matrices of the same dimensions.");

    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            elements[i][j] -= right.elements[i][j];

    return *this;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator*(const Matrix<Type> &right) const
{
    if (cols != right.rows)
        throw std::invalid_argument("Matrices are incompatible for multiplication");

    Matrix result(rows, right.cols, elements[0][0]);

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < right.cols; j++)
        {
            Type sum = 0;

            for (unsigned int k = 0; k < cols; k++)
                sum += elements[i][k] * right.elements[k][j];

            result.elements[i][j] = sum;
        }
    }

    return result;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator*=(const Matrix<Type> &right)
{
    *this = *this * right;
    return *this;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator+(const Type &right) const
{
    Matrix result(rows, cols, elements[0][0]);

    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            result.elements[i][j] = this->elements[i][j] + right;

    return result;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator/(const Type &right) const
{
    if (right == 0)
        throw std::invalid_argument("Division by zero.");

    Matrix result(rows, cols, elements[0][0]);

    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            result.elements[i][j] = this->elements[i][j] / right;

    return result;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator-(const Type &right) const
{
    Matrix result(rows, cols, elements[0][0]);

    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            result.elements[i][j] = this->elements[i][j] - right;

    return result;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator*(const Type &right) const
{
    Matrix result(rows, cols, elements[0][0]);

    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            result.elements[i][j] = this->elements[i][j] * right;

    return result;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator+=(const Type &right)
{
    *this = *this + right;
    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator-=(const Type &right)
{
    *this = *this - right;
    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator*=(const Type &right)
{
    *this = *this * right;
    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator/=(const Type &right)
{
    *this = *this / right;
    return *this;
}

template <typename Type>
Type &Matrix<Type>::operator()(const unsigned &i, const unsigned &j)
{
    if (i >= rows || j >= cols)
    {
        throw std::out_of_range("Matrix index out of bounds!");
    }

    return elements[i][j];
}

template <typename Type>
void Matrix<Type>::print() const
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
            std::cout << elements[i][j] << " ";

        std::cout << std::endl;
    }
}

template <typename Type>
Type &Matrix<Type>::element(unsigned &i, unsigned &j)
{
    if (i >= rows || j >= cols)
    {
        throw std::out_of_range("Matrix index out of bounds! "
                                "Index (" + std::to_string(i) + ", " + std::to_string(j) + ")"
                                " exceeds matrix dimensions (" + std::to_string(rows) + ", " + std::to_string(cols) + ")"
                                " in file " + std::string(__FILE__) + " at line " + std::to_string(__LINE__));
    }
    if (rows == 0 || cols == 0)
    {
        throw std::runtime_error("Matrix is empty! "
                                 "Index (" + std::to_string(i) + ", " + std::to_string(j) + ")"
                                 " in file " + std::string(__FILE__) + " at line " + std::to_string(__LINE__));
    }
    return elements[i][j];
}

template <typename Type>
Type &Matrix<Type>::element(unsigned &i)
{
    if (rows > 1)
        throw std::invalid_argument("Incorrect use of index! matrix has more than one row\nuse Matrix::element(row, col); instead");

    if (i >= cols)
        throw std::out_of_range("Matrix index out of bounds! "
                                "Index (" + std::to_string(i) + ")"
                                " exceeds matrix dimensions (" + std::to_string(rows) + ", " + std::to_string(cols) + ")"
                                " in file " + std::string(__FILE__) + " at line " + std::to_string(__LINE__));

    if (rows == 0 && cols == 0)
        throw std::runtime_error("Matrix is empty! Index out of bounds!");

    return this->elements[0][i];
}

template <typename Type>
Type &Matrix<Type>::element(const unsigned &i, const unsigned &j)
{
    if (i >= rows || j >= cols)
    {
        throw std::out_of_range("Matrix index out of bounds! "
                                "Index (" + std::to_string(i) + ", " + std::to_string(j) + ")"
                                " exceeds matrix dimensions (" + std::to_string(rows) + ", " + std::to_string(cols) + ")"
                                " in file " + std::string(__FILE__) + " at line " + std::to_string(__LINE__));
    }
    if (rows == 0 || cols == 0)
    {
        throw std::runtime_error("Matrix is empty! "
                                 "Index (" + std::to_string(i) + ", " + std::to_string(j) + ")"
                                 " in file " + std::string(__FILE__) + " at line " + std::to_string(__LINE__));
    }
    return elements[i][j];
}

template <typename Type>
Type &Matrix<Type>::element(const unsigned &i)
{
    if (rows > 1)
        throw std::invalid_argument("Incorrect use of index! matrix has more than one row\nuse Matrix::element(row, col); instead");

    if (i >= cols)
        throw std::out_of_range("Matrix index out of bounds! "
                                "Index (" + std::to_string(i) + ")"
                                " exceeds matrix dimensions (" + std::to_string(rows) + ", " + std::to_string(cols) + ")"
                                " in file " + std::string(__FILE__) + " at line " + std::to_string(__LINE__));

    if (rows == 0 && cols == 0)
        throw std::runtime_error("Matrix is empty! Index out of bounds!");

    return this->elements[0][i];
}

template <typename Type>
Matrix<Type> Matrix<Type>::transpose() const
{
    Matrix<Type> result(cols, rows, elements[0][0]);

    for (unsigned int i = 0; i < rows; i++)
        for (unsigned int j = 0; j < cols; j++)
            result.elements[j][i] = elements[i][j];

    return result;
}

template <typename Type>
Matrix<Type> Matrix<Type>::power(unsigned n) const
{
    if (n == 0)
    {
        if (!is_square() || elements.empty())
        {
            throw std::invalid_argument("Matrix is incompatible for power() | rows != cols or matrix is empty\n");
        }
        
        Matrix result(rows);
        return result;
    }

    if (!is_square())
    {
        throw std::invalid_argument("Matrix is incompatible for power() | rows != cols\n");
    }

    Matrix result(rows, cols, elements[0][0]);
    result = *this;

    return result * result.power(n - 1);
}

template <typename Type>
unsigned Matrix<Type>::getRows() const
{
    return rows;
}

template <typename Type>
unsigned Matrix<Type>::getCols() const
{
    return cols;
}
