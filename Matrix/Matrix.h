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
    size_t size1() const;
    size_t size2() const;
    T getMaxValue() const;
    T getMinValue() const;
    size_t getStringIndexWithMaxValue() const;
    size_t getStringIndexWithMinValue() const;
    bool isValueInMatrix(const size_t row, const T value) const;
    T getStringWithMaxValue() const;
    T getStringWithMinValue() const;
    void resizeMatrix(const size_t rows, const size_t columns);
    void resizeMatrix1(const size_t rows);
    void resizeMatrix2(const size_t columns);
    void insertVector(const std::vector<T>* temp);
    void removeRow(const size_t index);
    T& operator()(const size_t, const size_t);
    void operator=(const T value);
    void operator+=(T& matrix);

};

template<typename T>
Matrix<T>::Matrix(size_t numOfRows, size_t numOfCols) : numberOfRows(numOfRows), numberOfColumns(numOfCols) {
    this->matrix.resize(numOfRows);
    for (size_t i = 0; i< this->matrix.size(); i++)
        this->matrix[i].resize(numOfCols);
}

template<typename T>
size_t Matrix<T>::size1() const {
    return this->matrix.size();
}
template<typename T>
size_t Matrix<T>::size2() const {
    return this->matrix[0].size();
}

template<typename T>
T get_max_element_in_vector(const std::vector<T>& vec) {
    auto max_iter_element = std::max_element(vec.begin(), vec.end());
    return vec[std::distance(vec.begin(), max_iter_element)];
}

template<typename T>
T Matrix<T>::getMaxValue() const {
    std::vector<T> maxElementsInEachString;
    for (size_t i = 0; i < this->matrix.size(); i++) {
        maxElementsInEachString.push_back(get_max_element_in_vector(this->matrix[i]));
    }
    auto maxIter = std::max_element(maxElementsInEachString.begin(), maxElementsInEachString.end());
    return maxElementsInEachString[std::distance(maxElementsInEachString.begin(), maxIter)];
}

template<typename T>
size_t Matrix<T>::getStringIndexWithMaxValue() const {
    std::vector<T> maxElementsInEachString;
    for (size_t i = 0; i < this->matrix.size(); i++) {
        maxElementsInEachString.push_back(get_max_element_in_vector(this->matrix[i]));
    }
    auto maxIter = std::max_element(maxElementsInEachString.begin(), maxElementsInEachString.end());
    return std::distance(maxElementsInEachString.begin(), maxIter);
}

template<typename T>
T get_min_element_in_vector(const std::vector<T>& vec) {
    auto min_iter_element = std::min_element(vec.begin(), vec.end());
    return vec[std::distance(vec.begin(), min_iter_element)];
}

template<typename T>
T Matrix<T>::getMinValue() const {
    std::vector<T> minElementsInEachString;
    for (size_t i = 0; i < this->matrix.size(); i++) {
        minElementsInEachString.push_back(get_min_element_in_vector(this->matrix[i]));
    }
    auto minIter = std::min_element(minElementsInEachString.begin(), minElementsInEachString.end());
    return minElementsInEachString[std::distance(minElementsInEachString.begin(), minIter)];
}

template<typename T>
size_t Matrix<T>::getStringIndexWithMinValue() const {
    std::vector<T> minElementsInEachString;
    for (size_t i = 0; i < this->matrix.size(); i++) {
        minElementsInEachString.push_back(get_min_element_in_vector(this->matrix[i]));
    }
    auto minIter = std::min_element(minElementsInEachString.begin(), minElementsInEachString.end());
    return std::distance(minElementsInEachString.begin(), minIter);
}

template<typename T>
bool binary_search(std::vector<T> data, T target, size_t low, size_t high) {
    if (low > high)
        return false;
    else {
        size_t mid = (low + high) / 2;
        if (target == data[mid])
            return true;
        else if (target < data[mid])
            return binary_search(data, target, low, mid - 1);
        else
            return binary_search(data, target, mid + 1, high);
    }
}

template<typename T>
bool Matrix<T>::isValueInMatrix(const size_t row, const T value) const {
    std::vector<T> data = this->matrix[row];
    std::sort(data.begin(), data.end());
    return binary_search(data, value, 0, data.size());
}




template<typename T>
void Matrix<T>::resizeMatrix(const size_t rows, const size_t columns) {
    this->matrix.resize(rows);
    for (size_t i = 0; i < rows; i++)
        this->matrix[i].resize(columns);
}

template<typename T>
void Matrix<T>::resizeMatrix1(const size_t rows) {
    this->matrix.resize(rows);
}
template<typename T>
void Matrix<T>::resizeMatrix2(const size_t columns) {
    for (size_t i = 0; i < this->matrix.size(); i++)
        this->matrix[i].resize(columns);
}

template<typename T>
void Matrix<T>::insertVector(const std::vector<T>* temp) {
    if (temp != nullptr)
        this->matrix.push_back(*temp);
    else
        std::cout << "ERROR: You pass pointer ot null object" << std::endl;
}

template<typename T>
void Matrix<T>::removeRow(const size_t index) {
    for (size_t i = 0; i < this->matrix.size(); i++)
        this->matrix[i].erase(this->matrix[i].begin() + index);
}

template<typename T>
T& Matrix<T>::operator()(const size_t row, const size_t col) {
    return this->matrix[row][col];
}

template<typename T>
void Matrix<T>::operator=(const T value) {
    for (size_t i = 0; i < this->matrix.size(); i++) {
        for (size_t j = 0; j < this->matrix[i].size(); j++)
            this->matrix[i][j] = value;
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
bool operator==(const Matrix<T>& matrix1, const Matrix<T>& matrix2) {
    return matrix1.size1() == matrix2.size1() && matrix1.size2() == matrix2.size2() ? true : false;
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
Matrix<T> matrix_mult(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    Matrix<T> multiplicationResult(matrix1.size1(), matrix2.size2());
    for (size_t i = 0; i < matrix1.size1(); i++) {
        for (size_t j = 0; j < matrix2.size2(); j++) {
            for (size_t k = 0; k < matrix1.size2(); k++)
                multiplicationResult(i, j) += matrix1(i, k) * matrix2(k, j);
        }
    }
    return multiplicationResult;
}

template<typename T>
Matrix<T> get_matrix_mult(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    if (IsTypeChar<T>::value || IsTypeString<T>::value) {
        throw "ERROR: Matrices type is uncorrect!";
    } else {
        if (matrix1.size2() == matrix2.size1())
            return matrix_mult(matrix1, matrix2);
        else
            throw "ERROR: Matrices are not equal!";
    }
}

template<typename T>
Matrix<T> operator*(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    Matrix<T> multiplicationResult(matrix1.size1(), matrix2.size2());
    try {
        multiplicationResult = get_matrix_mult(matrix1, matrix2);
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
void fillMatrixWithRandomValues(Matrix<T>& matrix, const size_t from, const size_t to) {
    if (IsTypeChar<T>::value || IsTypeString<T>::value)
        throw "ERROR: Matrix type is uncorrect!";
    else {
        std::random_device rd;
        std::mt19937 rng(rd());
        for (size_t i = 0; i < matrix.size1(); i++) {
            for (size_t j = 0; j < matrix.size2(); j++) {
                std::uniform_real_distribution<T> dist(from, to);
                matrix(i, j) = dist(rng);
            }
        }
    }
}

// TODO another solution possible
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

