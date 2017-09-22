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

#ifndef Matrix_h
#define Matrix_h

using namespace std;

template<typename T> class Matrix {
private:
    size_t numberOfRows;
    size_t numberOfColumns;
    vector<vector<T>> matrix;
    
public:
    Matrix(size_t, size_t);
    size_t size1();
    size_t size2();
    T& operator()(size_t, size_t);
    void operator=(T);
    void operator+=(T);
};

template<typename T>
struct IsTypeInt {
    static const bool value = false;
};
template<> struct IsTypeInt<int> {
    static const bool value = true;
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
    for (size_t i = 0; i < this->matrix.size(); i++)
        return this->matrix[i].size();
}

template<typename T>
T& Matrix<T>::operator()(size_t row, size_t col) {
    return this->matrix[row][col];
}
template<typename T>
ostream& operator<<(ostream& os, Matrix<T>& matrix) {
    for (size_t i = 0; i < matrix.size1(); i++) {
        for (size_t j = 0; j < matrix.size2(); j++)
            os << matrix(i, j) << " ";
        cout << endl;
    }
    return os;
}
template<typename T>
void Matrix<T>::operator=(T value) {
    for (size_t i = 0; i < this->matrix.size(); i++) {
        for (size_t j = 0; j < this->matrix[i].size(); j++)
            this->matrix[i][j] = value;
    }
}
template<typename T>
void Matrix<T>::operator+=(T value) {
    for (size_t i = 0; i < this->matrix.size(); i++) {
        for (size_t j = 0; j < this->matrix[i].size(); j++)
            this->matrix[i][j] += value;
    }
}

// does not work with strings and chars
// TODO
template<typename T>
Matrix<T> matrixMultiplication(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    Matrix<T> resultMatrix(matrix1.size2(), matrix2.size1());
    for (size_t i = 0; i < resultMatrix.size1(); i++) {
        for (size_t j = 0; j < resultMatrix.size2(); j++) {
            resultMatrix = 0;
            for (size_t k = 0; k < resultMatrix.size2(); k++) {
                try {
                    resultMatrix += matrix1(i, k) * matrix2(k, j);
                } catch (std::exception& e) {
                    throw "Can't multiply matrix of this type:(";
                }
            }
        }
    }
    return resultMatrix;
}
template<typename T>
Matrix<T> operator*(Matrix<T> matrix1, Matrix<T> matrix2) {
    if (matrix1.size2() == matrix2.size1()) {
        return matrixMultiplication(matrix1, matrix2);
    }
}



#endif /* Matrix_h */
