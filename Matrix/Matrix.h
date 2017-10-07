//
//  Matrix.h
//  Matrix
//
//  Created by Daniel Solovich on 9/22/17.
//  Copyright © 2017 Daniel Solovich. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <random>
#include "TypesCheck.h"
#ifndef Matrix_h
#define Matrix_h


template<typename T> class Matrix {
private:
    size_t numberOfRows;
    size_t numberOfColumns;
    std::vector<std::vector<T>> matrix;
public:
    Matrix() = default;
    Matrix(size_t, size_t);
    size_t size1();
    size_t size2();
    void resizeMatrix(size_t rows, size_t columns);
    void resizeMatrix1(size_t rows);
    void resizeMatrix2(size_t columns);
    void insertVector(std::vector<T>* temp);
    void removeColumn(size_t index);
    T& operator()(size_t, size_t);
    void operator>>(Matrix<double>&);
    void operator=(T value);
    void operator+=(T& matrix);
};

template<typename T>
Matrix<T>::Matrix(size_t numOfRows, size_t numOfCols) : numberOfRows(numOfRows), numberOfColumns(numOfCols) {
    this->matrix.resize(numOfRows);
    for (size_t i = 0; i< this->matrix.size(); i++)
        this->matrix[i].resize(numOfCols);
}

template<typename T>
size_t Matrix<T>::size1() {
    return this->matrix.size();
}
template<typename T>
size_t Matrix<T>::size2() {
    return this->matrix[0].size();
}

template<typename T>
void Matrix<T>::resizeMatrix(size_t rows, size_t columns) {
    this->matrix.resize(rows);
    for (size_t i = 0; i < rows; i++)
        this->matrix[i].resize(columns);
}

template<typename T>
void Matrix<T>::resizeMatrix1(size_t rows) {
    this->matrix.resize(rows);
}
template<typename T>
void Matrix<T>::resizeMatrix2(size_t columns) {
    for (size_t i = 0; i < this->matrix.size(); i++)
        this->matrix[i].resize(columns);
}

template<typename T>
void Matrix<T>::insertVector(std::vector<T>* temp) {
    if (temp != nullptr)
        this->matrix.push_back(*temp);
    else
        std::cout << "ERROR: You pass pointer ot null object" << std::endl; 
}

template<typename T>
void Matrix<T>::removeColumn(size_t index) {
    for (size_t i = 0; i < this->matrix.size(); i++)
        this->matrix[i].erase(this->matrix[i].begin() + index); 
}

template<typename T>
T& Matrix<T>::operator()(size_t row, size_t col) {
    return this->matrix[row][col];
}

template<typename T>
void Matrix<T>::operator=(T value) {
    for (size_t i = 0; i < this->matrix.size(); i++) {
        for (size_t j = 0; j < this->matrix[i].size(); j++)
            this->matrix[i][j] = value;
    }
}

template<typename T>
void Matrix<T>::operator>>(Matrix<double>& matrix) {
    matrix.resizeMatrix(this->matrix.size(), this->matrix[0].size());
    for (size_t i = 0; i < this->matrix.size(); i++) {
        for (size_t j = 0; j < this->matrix[i].size(); j++)
            matrix(i, j) = this->matrix[i][j]; 
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Matrix<T> matrix) {
    for (size_t i = 0; i < matrix.size1(); i++) {
        for (size_t j = 0; j < matrix.size2(); j++)
            os << matrix(i, j) << " ";
        std::cout << std::endl;
    }
    std::cout << "Number of rows: " << matrix.size1() << std::endl;
    std::cout << "Number of columns: " << matrix.size2() << std::endl;
    return os;
}


template<typename T>
bool operator==(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    const bool value = matrix1.size1() == matrix2.size1() && matrix1.size2() == matrix2.size2() ? true : false;
    return value;
}

template<typename T>
Matrix<T> matrixSum(Matrix<T>& matrix1, Matrix<T> matrix2) {
    if (matrix1 == matrix2) {
        Matrix<T> resultMatrix(matrix1.size1(), matrix2.size2());
        for (size_t i = 0; i < resultMatrix.size1(); i++) {
            for (size_t j = 0; j < resultMatrix.size2(); j++)
                resultMatrix(i, j) = matrix1(i, j) + matrix2(i, j);
        }
        return resultMatrix;
    } else
        throw "ERROR: Matrixes are not equal!";
}

template<typename T>
Matrix<T> operator+(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    Matrix<T> sumResult(matrix1.size1(), matrix2.size2());
    try {
        sumResult = matrixSum(matrix1, matrix2);
    } catch(char const* error) {
        std::cout << error << std::endl;
    }
    return sumResult;
}

template<typename T>
void Matrix<T>::operator+=(T& value) {
    for (size_t i = 0; i < this->matrix.size(); i++) {
        for (size_t j = 0; j < this->matrix[i].size(); j++)
            this->matrix[i][j] += value;
    }
}


template<typename T>
Matrix<T> matrixMin(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    if (IsTypeChar<T>::value || IsTypeString<T>::value) {
        throw "ERROR: Matrices type is uncorrect!";
    } else {
        if (matrix1 == matrix2) {
            Matrix<T> minResult(matrix1.size1(), matrix2.size2());
            for (size_t i = 0; i < minResult.size1(); i++) {
                for (size_t j = 0; j < minResult.size2(); j++)
                    minResult(i, j) = matrix1(i, j) - matrix2(i, j);
            }
            return minResult;
        } else
            throw "ERROR: Matrices are not equal!bzzz";
    }
}
template<typename T>
Matrix<T> operator-(Matrix<T> matrix1, Matrix<T> matrix2) {
    Matrix<T> minResult(matrix1.size1(), matrix2.size2());
    try {
        minResult = matrixMin(matrix1, matrix2);
    } catch (char const* error) {
        std::cout << error << std::endl;
    }
    return minResult;
}

template<typename T>
Matrix<T> matrixMultiplication(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    if (IsTypeChar<T>::value || IsTypeString<T>::value) {
        throw "ERROR: Matrices type is uncorrect!";
    } else {
        if (matrix1.size2() == matrix2.size1()) {
            Matrix<T> multiplicationResult(matrix1.size1(), matrix2.size2());
            for (size_t i = 0; i < matrix1.size1(); i++) {
                for (size_t j = 0; j < matrix2.size2(); j++) {
                    for (size_t k = 0; k < matrix1.size2(); k++)
                        multiplicationResult(i, j) += matrix1(i, k) * matrix2(k, j);
                }
            }
            return multiplicationResult;
        } else
            throw "ERROR: Matrices are not equal!";
    }
}

template<typename T>
Matrix<T> operator*(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    Matrix<T> multiplicationResult(matrix1.size1(), matrix2.size2());
    try {
        multiplicationResult = matrixMultiplication(matrix1, matrix2);
    } catch(char const* error) {
        std::cout << error << std::endl;
    }
    return multiplicationResult;
}

template<typename T>
Matrix<T> transpose(Matrix<T>* matrix) {
    Matrix<T>* transposedMatrix = new Matrix<T>(matrix->size2(), matrix->size1());
    for (auto i = 0; i < matrix->size1(); i++) {
        for (auto j = 0; j < matrix->size2(); j++)
            transposedMatrix->operator()(j, i) = matrix->operator()(i, j);
    }
    return *transposedMatrix; 
}

template<typename T>
void randomMatrixValuesGenerator(Matrix<T>& matrix, T from, T to) {
    if (IsTypeChar<T>::value || IsTypeString<T>::value)
        throw "ERROR: Matrix type is uncorrect!";
    else {
        std::random_device rd;
        std::mt19937 rng(rd());
        for (size_t i = 0 ; i < matrix.size1(); i++) {
            for (size_t j = 0; j < matrix.size2(); j++) {
                std::uniform_real_distribution<T> dist(from, to);
                matrix(i, j) = dist(rng);
            }
        }
    }
}

template<typename T>
Matrix<T> multiplyMatrixValueByValue(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    Matrix<T> resultMatrix(matrix1.size1(), matrix2.size2());
    if (matrix1 == matrix2) {
        for (size_t i = 0; i < matrix1.size1(); i++) {
            for (size_t j = 0; j < matrix1.size2(); j++)
                resultMatrix(i, j) = matrix1(i, j) * matrix2(i, j);
        }
        return resultMatrix;
    } else {
        std::cout << "ERROR: Matrices are not equal!" << std::endl;
        return resultMatrix;
    }
}




#endif /* Matrix_h */
