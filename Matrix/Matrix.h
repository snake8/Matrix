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
#include <memory>
#include "MatrixExceptions.h"




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
    auto begin1() const;
    auto end1() const;
    auto begin2() const;
    auto end2() const;
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
    void insertVector(const std::vector<T>& temp);
    void removeRow(const size_t index);
    static void fillMatrix(Matrix<T> matrix, const size_t from, const size_t to);
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
auto Matrix<T>::begin1() const {
    return this->matrix.begin();
}

template<typename T>
auto Matrix<T>::end1() const {
    return this->matrix.end(); 
}

template<typename T>
auto Matrix<T>::begin2() const {
    return this->matrix[0].begin();
}

template<typename T>
auto Matrix<T>::end2() const {
    return this->matrix[0].end();
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
    size_t mid = (low + high) / 2;
    if (target == data[mid])
        return true;
    else if (target < data[mid])
        return binary_search(data, target, low, mid - 1);
    else
        return binary_search(data, target, mid + 1, high);
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
void Matrix<T>::insertVector(const std::vector<T>& temp) {
    this->matrix.push_back(temp);
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
Matrix<T> matrixSum(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    if (matrix1 == matrix2) {
        Matrix<T> resultMatrix(matrix1.size1(), matrix2.size2());
        for (size_t i = 0; i < resultMatrix.size1(); i++) {
            for (size_t j = 0; j < resultMatrix.size2(); j++)
                resultMatrix(i, j) = matrix1(i, j) + matrix2(i, j);
        }
        return resultMatrix;
    }
    throw MatrixExceptions("Error: Matrices are not equal");
}

template<typename T>
Matrix<T> operator+(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    try {
        return matrixSum(matrix1, matrix2);
    } catch(MatrixExceptions& e) {
        std::cout << e.backtrace << std::endl;
        std::cout << e.error << std::endl;
        exit(1);
    }
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
    if (matrix1 == matrix2) {
        Matrix<T> result = {matrix1.size1(), matrix1.size2()};
        for (size_t i = 0; i < matrix1.size1(); i++) {
            for (size_t j = 0; j < matrix1.size2(); j++)
                result(i, j) = matrix1(i, j) - matrix2(i, j);
        }
    }
    throw MatrixExceptions("Matrices are not equal!");
}

template<typename T>
Matrix<T> operator-(Matrix<T> matrix1, Matrix<T> matrix2) {
    try {
        return matrixMin(matrix1, matrix2);
    } catch (MatrixExceptions& e) {
        std::cout << e.backtrace << std::endl;
        std::cout << e.error << std::endl;
        exit(1);
    }
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
    if (matrix1.size2() == matrix2.size1())
        return matrix_mult(matrix1, matrix2);
    throw MatrixExceptions("Error: Number of strings in first matrix not equal to number of rows in second");
}

template<typename T>
Matrix<T> operator*(Matrix<T>& matrix1, Matrix<T>& matrix2) {
    try {
        return get_matrix_mult(matrix1, matrix2);
    } catch (MatrixExceptions& e) {
        std::cout << e.backtrace << std::endl;
        std::cout << e.error << std::endl;
        exit(1);
    }
}


template<typename T>
Matrix<T> transpose(Matrix<T> * const matrix) {
    Matrix<T> transposedMatrix = *matrix;
    for (size_t i = 0; i < matrix->size1(); i++) {
        for (size_t j =0; j < matrix->size2(); j++)
            transposedMatrix(j, i) = matrix->operator()(i)[j];
    }
    return transposedMatrix;
}

#endif /* Matrix_h */
