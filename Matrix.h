#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
public:
    std::vector<std::vector<float>> buffer;
    
    Matrix(int rows, int columns, float defaultValue = 0);
    Matrix(std::vector<std::vector<float>> arg);
    
    int Rows();
    int Columns();
    
    Matrix operator* (Matrix b);
    inline std::vector<float>& operator[] (int n);
};
