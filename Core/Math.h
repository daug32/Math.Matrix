#ifndef DG_MATH_H
#define DG_MATH_H
#include "Matrix.h"
#include "Vector.h"
#include <cmath>

namespace Math
{
    const float PI = 3.141592f;
    float Radians(float degrees);
    float Degrees(float radians);

    Vector MatrixToVector(const Matrix& a);
    Matrix VectorToMatrix(const Vector& a);

    Matrix IdentityMatrix(int size);
    Matrix RotationXY(float angle, int scale = 4);
    Matrix RotationYZ(float angle, int scale = 4);
    Matrix RotationXZ(float angle, int scale = 4);
}

#endif