#pragma once
#include "Matrix.h"

namespace Math
{
	namespace GraphicsUtils
	{
		const float PI = 3.141592f;

		inline float Radians(float degrees);
		inline float Degrees(float radians);

		Math::Matrix RotationXY(float angle, size_t scale = 4);
		Math::Matrix RotationYZ(float angle, size_t scale = 4);
		Math::Matrix RotationXZ(float angle, size_t scale = 4);
	};
}
