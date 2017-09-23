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
struct IsTypeString {
    static const bool value = false;
};
template<> struct IsTypeString<string> {
    static const bool value = true;
};
template<typename T>
struct IsTypeChar {
    static const bool value = false;
};
template<> struct IsTypeChar<char> {
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
    return this->matrix[0].size();
}
template<typename T>
T& Matrix<T>::operator()(size_t row, size_t col) {
    return this->matrix[row][col];
}
template<typename T>
ostream& operator<<(ostream& os, Matrix<T> matrix) {
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
Matrix<T> matrixSum(Matrix<T>& matrix1, Matrix<T> matrix2) {
    if (matrix1.size1() == matrix2.size1() && matrix1.size2() == matrix2.size2()) {
        Matrix<T> resultMatrix(matrix1.size1(), matrix2.size2());
        for (size_t i = 0; i < resultMatrix.size1(); i++) {
            for (size_t j = 0; j < resultMatrix.size2(); j++)
                resultMatrix(i, j) = matrix1(i, j) + matrix2(i, j);
        }
        return resultMatrix;
    } else
        throw "Matrixes are not equal!";
}
template<typename T>
Matrix<T> operator+(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    try {
        return matrixSum(matrix1, matrix2);
    } catch(char const* error) {
        cout << error << endl;
    }
}

template<typename T>
Matrix<T> matrixMultiplication(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    if (IsTypeChar<T>::value || IsTypeString<T>::value) {
        throw "Matrices of this type can't be multiplied!";
    } else {
        if (matrix1.size2() == matrix2.size1()) {
            Matrix<T> resultMatrix(matrix1.size1(), matrix2.size2());
            for (size_t i = 0; i < matrix1.size1(); i++) {
                for (size_t j = 0; j < matrix2.size2(); j++) {
                    for (size_t k = 0; k < matrix1.size2(); k++)
                        resultMatrix(i, j) += matrix1(i, k) * matrix2(k, j);
                }
            }
            return resultMatrix;
        } else
            throw "Matrices are not equal!";
    }
}
template<typename T>
Matrix<T> operator*(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    try {
        return matrixMultiplication(matrix1, matrix2);
    } catch (char const* error) {
        cout << error << endl; 
    }
}




#endif /* Matrix_h */
