#include <iostream>
#include <cstdlib>
#include <cstring>

class Matrix_Exception : public std::domain_error
{
public:
    Matrix_Exception(const char* const message) : std::domain_error(message) {}
};


class Matrix
{
private:
    size_t cols;
    size_t rows;
    double* value;

public:
    Matrix();
    Matrix(size_t col, size_t row);
    Matrix(size_t col);
    Matrix(const Matrix& matrix);
    Matrix(Matrix&& matrix);
    ~Matrix();

    void matrix_print();
    void matrix_fill_random(int max_value);

    Matrix operator+(const Matrix& matrix) const;
    Matrix operator-(const Matrix& matrix) const;
    Matrix operator*(const Matrix& matrix) const;
    Matrix operator*(double number) const;
    Matrix operator=(Matrix& matrix);
    Matrix operator=(Matrix&& matrix);
    Matrix operator^(const int number) const;
    Matrix operator/(const double number) const;
    static Matrix  exp(const Matrix& A, const size_t accuracy);
    Matrix matrix_minor(Matrix& mat1);
    Matrix matrix_transp();
    double matrix_det(Matrix matrix);


};

Matrix::~Matrix() {
    delete[] value;
    cols = 0;
    rows = 0;
    value = nullptr;
}


Matrix::Matrix() {
    cols = 0;
    rows = 0;
    value = nullptr;
}


Matrix::Matrix(size_t col, size_t row) {
    cols = col;
    rows = row;
    value = new double[cols * rows];
}


Matrix::Matrix(const Matrix& matrix) {
    cols = matrix.cols;
    rows = matrix.rows;
    value = new double[rows * cols];
    memcpy(value, matrix.value, rows * cols * sizeof(double));
}


Matrix::Matrix(Matrix&& matrix) {
    cols = 0;
    rows = 0;
    value = matrix.value;
    matrix.value = nullptr;
}


void Matrix::matrix_print() {
    for (size_t row = 0; row < rows; ++row) {
        for (size_t col = 0; col < cols; ++col) {
            std::cout << value[row * cols + col] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


void Matrix::matrix_fill_random(int max_value = 10) {
    for (size_t index = 0; index < rows * cols; ++index) {
        value[index] = rand() % max_value;
    }
}


Matrix::Matrix(size_t col) {
    cols = col;
    rows = col;
    value = new double[cols * rows];

    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            value[row * cols + col] = (row == col) ? 1.0 : 0.0;

        }
    }
}


Matrix Matrix::operator+ (const Matrix& matrix) const {

    if (rows != matrix.rows) throw ("Make matrix square\n");
    Matrix result(matrix);

    for (size_t idx = 0; idx < matrix.cols * matrix.rows; idx++) {
        result.value[idx] += value[idx];
    }
    return result;
}


Matrix Matrix::operator- (const Matrix& matrix) const {
    if (rows != matrix.rows) throw ("Make matrix square\n");
    Matrix result(matrix);

    for (size_t idx = 0; idx < matrix.cols * matrix.rows; idx++) {
        result.value[idx] -= value[idx];
    }
    return result;
}


Matrix Matrix::operator* (const Matrix& matrix) const {
    if (rows != matrix.rows) throw ("Make matrix square\n");
    Matrix result(matrix);

    for (size_t row = 0; row < result.rows; row++) {
        for (size_t col = 0; col < result.cols; col++) {
            result.value[row * result.rows + col] = 0.00;
            for (size_t k = 0; k < result.cols; k++) {
                result.value[row * result.cols + col] += value[row * cols + k] * matrix.value[k * result.cols + col];
            }
        }
    }
    return result;
}


Matrix Matrix::operator* (const double coefficient) const {
    Matrix result(cols, rows);

    for (size_t idx = 0; idx < rows * cols; idx++) {
        result.value[idx] = value[idx] * coefficient;
    }
    return result;
}



Matrix Matrix::operator= (Matrix& matrix) {
    if (this == &matrix) {
        return *this;
    }
    rows = matrix.rows;
    cols = matrix.cols;
    if (rows * cols == matrix.rows * matrix.cols) {
        memcpy(value, matrix.value, rows * cols * sizeof(double));
    }
    else {
        delete[]value;
        value = new double[cols * rows];
        memcpy(value, matrix.value, rows * cols * sizeof(double));
    }
    return *this;
}


Matrix Matrix::operator= (Matrix&& matrix) {
    rows = 0;
    cols = 0;
    delete[]value;
    value = matrix.value;
    matrix.value = nullptr;
    return *this;
}


Matrix Matrix::operator^(int number) const {
    if (cols != rows) throw ("Make matrix square\n");
    Matrix result(*this);

    if (number == 0) {
        Matrix matrix(cols);
        return matrix;
    }

    if (number == 1) {
        return result;
    }

    const Matrix& start(result);

    for (size_t idx = 0; idx < number; idx++) {
        result = result * start;
    }
    return result;
}


Matrix Matrix::operator/(const double number) const {
    if (number == 0) throw ("Can't divide by zero\n");
    Matrix result(cols, rows);

    for (size_t idx = 0; idx < rows * cols; ++idx) {
        result.value[idx] = value[idx] / number;
    }
    return result;
}


Matrix Matrix::exp(const Matrix& A, const size_t accuracy = 30) {
    if (A.rows != A.cols) throw ("Make matrix square\n");
    Matrix result(A.cols);
    Matrix term(A.cols);
    double factorial = 1.0;

    for (int step = 1; step < accuracy; step++) {
        factorial *= step;
        term = term * A;
        result = result + term / factorial;
    }
    return result;
}



Matrix Matrix::matrix_minor(Matrix& A) {
   

    Matrix result = Matrix(A.rows, A.cols);
    size_t k = 0;

    for (size_t idx = 0; idx < rows * cols; idx++) {
        if ((idx % cols == A.cols) or (idx / cols == A.rows)) continue;
        result.value[k++] = A.value[idx];
    }

    return result;
}

Matrix Matrix::matrix_transp() {
    Matrix result = { cols, rows };

    for (size_t row = 0; row < result.rows; row++) {
        for (size_t col = 0; col < result.cols; col++) {
            result.value[row * result.cols + col] = value[col * result.cols + row];
        }
    }
    return result;
}




int main() {
    Matrix mat1(3, 3);
    mat1.matrix_fill_random();
    mat1.matrix_print();
    Matrix mat2(3, 3);
    mat2.matrix_fill_random();
    mat2.matrix_print();
    Matrix sum = mat1 + mat2;
    sum.matrix_print();
    Matrix sub = mat1 - mat2;
    sub.matrix_print();
    Matrix mult = mat1 * mat2;
    mult.matrix_print();
    Matrix mult_number = mat1 * 2;
    mult_number.matrix_print();
    Matrix pow = mat1 ^ 2;
    pow.matrix_print();
    Matrix exp = Matrix::exp(mat1);
    exp.matrix_print();
    return 0;
}  