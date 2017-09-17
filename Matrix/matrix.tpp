template<typename T> struct IsTypeInt {
	static const bool value = false;
};

template<> struct IsTypeInt<int> {
	static const bool value = true; 
};


template<typename T> Matrix<T>::Matrix(size_t numOfRows, size_t numOfColumns)
	: numOfRows(numOfRows)
	, numOfColumns(numOfColumns) {
	this->matrix.resize(numOfRows);
	for (size_t i = 0; i < this->matrix.size(); i++) {
		this->matrix[i].resize(numOfColumns);
	}
}

template<typename T> int Matrix<T>::size1() {
	return this->matrix.size();
}

template<typename T> int Matrix<T>::size2() {
	for (size_t i = 0; i < this->matrix.size(); i++) {
		return this->matrix[i].size(); 
	}
}

template<typename T> auto Matrix<T>::getMatrix() {
	for (size_t i = 0; i < this->matrix; i++) {
		for (size_t j = 0; j < this->matrix[i].size(); j++) {
			return this->matrix[i][j]; 
		}
	}
}

template<typename T> T& Matrix<T>::operator()(int i, int b) {
	return this->matrix[i][b]; 
}

template<typename T> ostream& operator<<(ostream& os, Matrix<T>& matrix) {
	for (int i = 0; i < matrix.size1(); i++) {
		for (int j = 0; j < matrix.size2(); j++) {
			os << matrix(i, j) << " ";
		}
		cout << endl; 
	}
	return os; 
}

template<typename T> Matrix<T> matrixMultiplication(Matrix<T>& mat1, Matrix<T>& mat2) {
	Matrix<T> resultMatrix(mat1.size2(), mat2.size1());
	for (int i = 0; i < resultMatrix.size1(); i++) {
		for (int j = 0; j < resultMatrix.size2(); j++) {
			resultMatrix(i, j) = 0;
			for (int k = 0; k < resultMatrix.size2(); k++) {
				resultMatrix(i, j) += mat1(i, k) * mat2(k, j);
			}
		}
	}
	return resultMatrix;
}

template<typename T> Matrix<T> operator*(Matrix<T>& mat1, Matrix<T>& mat2) {
	Matrix<T> finalResultMatrix(mat1.size1(), mat2.size2());
	if (mat1.size2() == mat2.size1()) {
		return matrixMultiplication(mat1, mat2);
	}
	else {
		cout << "Matrix is not equal!" << endl;
	}
}

template<typename T> void Matrix<T>::operator=(T value) {
	for (size_t i = 0; i < this->matrix.size(); i++)
		for (size_t j = 0; j < this->matrix[i].size(); j++)
			this->matrix[i][j] = value; 
}

template<typename T> Matrix<T> matrixSum(Matrix<T>& mat1, Matrix<T>& mat2) {
	Matrix<T> finalMatrix(mat1.size2(), mat2.size1());
	for (int i = 0; i < finalMatrix.size1(); i++) {
		for (int j = 0; j < finalMatrix.size2(); j++) {
			finalMatrix(i, j) = mat1(i, j) + mat2(i, j); 
		}
	}
	return finalMatrix;
}

template<typename T> Matrix<T> operator+(Matrix<T>& mat1, Matrix<T>& mat2) {
	if (mat1.size2() == mat2.size1()) {
		return matrixSum(mat1, mat2); 
	} else {
		cout << "Matrix is not equal" << endl; 
	}
}
