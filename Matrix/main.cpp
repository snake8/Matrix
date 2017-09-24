//
//  main.cpp
//  Matrix
//
//  Created by Daniel Solovich on 9/22/17.
//  Copyright © 2017 Daniel Solovich. All rights reserved.
//

#include "Matrix.h"




int main() {
    clock_t t1, t2;
    Matrix<double> mat1(2, 2);
    Matrix<double> mat2(2, 2);
    Matrix<double> mat3;
    t1 = clock();
    // you can test runtime here
    t2 = clock();
    float runTime = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;
    std::cout << "Program tuntime: " << runTime << std::endl;
    return 0;
}
