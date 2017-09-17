#include "stdafx.h"

template<typename T> class Matrix {
private:
	int numOfRows, numOfColumns;
	vector<vector<T>> matrix;
	auto getMatrix();
public:
	Matrix() = default;
	Matrix(size_t, size_t);
	int size1();
	int size2();
	T& operator()(int, int);
	// making all values in matrix equal specific value 
	void operator=(T); 
};



#include "matrix.tpp"

