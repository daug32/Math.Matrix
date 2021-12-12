#ifndef MATH_H
#define MATH_H
#include "Matrix.h"
#include "Vector.h"

namespace Math
{
    const float PI = 3.141592f;
    float Radians(float degrees) { return PI / 180.f * degrees; }
    float Degrees(float radians) { return 180.f / PI * radians; }
}

#endif