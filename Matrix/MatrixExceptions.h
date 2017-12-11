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


class IMatrixExceptions {
public:
    virtual std::string getError() = 0;
    std::string getBacktrace = Backtrace(0);
};


class MultiplicationError : public IMatrixExceptions {
private:
    const std::string error = "First matrix number of rows does not equal to second matrix number of strings.";
public:
    std::string getError() {
        return error;
    }
};

class SumOrMinError : public IMatrixExceptions {
private:
    const std::string error = "First matrix number of strings and rows does not equal to second matrix number of rows and strings.";
public:
    std::string getError() {
        return error; 
    }
};




#endif /* MatrixExceptions_h */
