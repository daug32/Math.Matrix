#include "GraphicsUtils.h"
#include <cmath>
#include <math.h>
#include <stdexcept>

inline float Math::GraphicsUtils::Radians(float degrees)
{
	return Math::GraphicsUtils::PI / 180.f * degrees;
}

inline float Math::GraphicsUtils::Degrees(float radians)
{
	return 180.f / Math::GraphicsUtils::PI * radians;
}

Math::Matrix Math::GraphicsUtils::RotationXY(float angle, size_t scale)
{
	if (scale < 3)
	{
		throw std::invalid_argument("Matrix scale is less then 3");
	}

	float sin = std::sin(angle);
	float cos = std::cos(angle);

	auto result = Math::Matrix::IdentityMatrix(scale);

	result[0][0] = cos;
	result[0][1] = -sin;
	result[1][0] = sin;
	result[1][1] = cos;

	return result;
}

Math::Matrix Math::GraphicsUtils::RotationYZ(float angle, size_t scale)
{
	if (scale < 3)
	{
		throw std::invalid_argument("Matrix scale is less then 3");
	}

	float sin = std::sin(angle);
	float cos = std::cos(angle);

	auto result = Math::Matrix::IdentityMatrix(scale);

	result[1][1] = cos;
	result[1][2] = -sin;
	result[2][1] = sin;
	result[2][2] = cos;

	return result;
}

Math::Matrix Math::GraphicsUtils::RotationXZ(float angle, size_t scale)
{
	if (scale < 3)
	{
		throw std::invalid_argument("Matrix scale is less then 3");
	}

	float sin = std::sin(angle);
	float cos = std::cos(angle);

	auto result = Math::Matrix::IdentityMatrix(scale);

	result[0][0] = cos;
	result[0][2] = sin;
	result[2][0] = -sin;
	result[2][2] = cos;

	return result;
}