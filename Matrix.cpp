#include "Matrix.h"

Matrix::Matrix(int rows, int columns, float defaultValue)
{
    buffer.resize(rows);
    for(auto &i : buffer)
    {
        i.resize(columns);
        for(auto &j : i) j = defaultValue;
    }
}
Matrix::Matrix(std::vector<std::vector<float>> arg) 
{
    buffer = arg;
}

//=============================
//Methods
//=============================
int Matrix::Rows() 
{
    return buffer.size();
}
int Matrix::Columns() 
{
    return buffer[0].size();
}

//=============================
//Operator
//=============================
Matrix Matrix::operator* (Matrix b)
{
    if(Columns() != b.Rows()) 
        throw std::invalid_argument("Impossible to multipy those matrices");
        
    Matrix r(Rows(), b.Columns());
    
    for(int fy = 0; fy < Rows(); fy++)
    {
        for(int sx = 0; sx < b.Columns(); sx++)
            for(int fx = 0; fx < Columns(); fx++)
                r[fy][sx] += buffer[fy][fx] * b[fx][sx];
    }
    
    return r;
}
inline std::vector<float>& Matrix::operator[] (int n)
{
    if(n >= buffer.size() || n < 0) 
        throw std::invalid_argument("n is out of range");
    return buffer[n];
}
