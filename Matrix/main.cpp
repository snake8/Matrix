#include <iostream>
#include <random>
#include <vector>

#include "Matrix.h"




int main() {
    
    Matrix<int> matrix1 = {3, 3};
    Matrix<int> matrix2 = {2, 3};
    
    Matrix<int> matrix3 = matrix1 * matrix2;
    
    std::cout << matrix3 << std::endl;
    
    
    return 0;
}
