#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>

namespace Math
{
    class Matrix {
    public:
        std::vector<std::vector<float>> buffer;
        
        Matrix(int rows, int columns, float defaultValue = 0);
        Matrix(std::vector<std::vector<float>> arg);
        
        int Rows();
        int Columns();

        float Determinator();
        Matrix Transform();

        void operator*= (Matrix b);
        void operator+= (Matrix b);
        void operator-= (Matrix b);
        
        Matrix operator* (Matrix b);
        Matrix operator+ (Matrix b);
        Matrix operator- (Matrix b);

        Matrix operator* (float k);
        Matrix operator/ (float k);
        void operator*= (float k);
        void operator/= (float k);

        inline std::vector<float>& operator[] (int n);
    };
}

#endif