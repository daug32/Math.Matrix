#include "Math.h"

namespace Math
{
    float Radians(float degrees) { return PI / 180.f * degrees; }
    float Degrees(float radians) { return 180.f / PI * radians; }
    
    Vector MatrixToVector(const Matrix& a)
    {
        Vector result;
        result.x = a.buffer[0][0];
        result.y = a.buffer[1][0];
        result.z = a.buffer[2][0];
        return result;
    }
    Matrix VectorToMatrix(const Vector& a)
    {
        Matrix result(3, 1);
        result[0][0] = a.x;
        result[1][0] = a.y;
        result[2][0] = a.x;
        return result;
    }
    
    Matrix RotationXY(float angle, int scale)
    {
        if(scale < 3) 
            throw std::invalid_argument("Matrix scale is less then 3");
        float sin = std::sin(angle);
        float cos = std::cos(angle);
        auto result = IdentityMatrix(scale);
        result[0][0] = cos;
        result[0][1] = -sin;
        result[1][0] = sin;
        result[1][1] = cos;
        return result;
    }
    Matrix RotationYZ(float angle, int scale)
    {
        if(scale < 3) 
            throw std::invalid_argument("Matrix scale is less then 3");
        float sin = std::sin(angle);
        float cos = std::cos(angle);
        auto result = IdentityMatrix(scale);
        result[1][1] = cos;
        result[1][2] = -sin;
        result[2][1] = sin;
        result[2][2] = cos;
        return result;
    }
    Matrix RotationXZ(float angle, int scale)
    {
        if(scale < 3) 
            throw std::invalid_argument("Matrix scale is less then 3");
        float sin = std::sin(angle);
        float cos = std::cos(angle);
        auto result = IdentityMatrix(scale);
        result[0][0] = cos;
        result[0][2] = sin;
        result[2][0] = -sin;
        result[2][2] = cos;
        return result;
    }
    Matrix IdentityMatrix(int size)
    {
        Matrix result(size, size, 0);
        for(int i = 0; i < result.Rows(); i++)
            result[i][i] = 1;
        return result;
    }
}