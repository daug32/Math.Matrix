#pragma once
#include "Matrix.h"
#include "Vector3.h"
#include <cmath>

namespace Math
{
    const float PI = 3.141592f;
    inline float Radians(float degrees);
    inline float Degrees(float radians);

    Vector3 MatrixToVector(const Matrix& a);
    Matrix VectorToMatrix(const Vector3& a);

    Matrix IdentityMatrix(int size);
    Matrix RotationXY(float angle, int scale = 4);
    Matrix RotationYZ(float angle, int scale = 4);
    Matrix RotationXZ(float angle, int scale = 4);
}
