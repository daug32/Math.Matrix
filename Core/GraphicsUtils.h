#pragma once
#include "Matrix.h"

namespace Math
{
	namespace GraphicsUtils
	{
		const float PI = 3.141592f;

		inline float Radians(float degrees);
		inline float Degrees(float radians);

		Math::Matrix RotationXY(float angle, int scale = 4);
		Math::Matrix RotationYZ(float angle, int scale = 4);
		Math::Matrix RotationXZ(float angle, int scale = 4);
	};
}
