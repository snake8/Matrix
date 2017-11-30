//
//  MatrixExceptions.h
//  Matrix
//
//  Created by Daniel Solovich on 11/30/17.
//  Copyright © 2017 Daniel Solovich. All rights reserved.
//

#ifndef MatrixExceptions_h
#define MatrixExceptions_h
#include "stacktrace.h"


class MatrixExceptions : public std::runtime_error {
public:
    MatrixExceptions(const char* msg) : std::runtime_error(msg) { }
    std::string error = std::runtime_error::what();
    std::string backtrace = Backtrace(1);
};


#endif /* MatrixExceptions_h */
