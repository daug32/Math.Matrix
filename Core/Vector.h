#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H
#include <vector>

namespace Math
{
	class Vector {
	public:
		float x;
		float y;
		float z;

		Vector(float x, float y, float z = 0);
		Vector(float value);
		Vector();

		void operator+=(Vector v);
		void operator-=(Vector v);
		void operator*=(float v);
		void operator/=(float v);

		Vector operator+(Vector a);
		Vector operator-(Vector a);
		Vector operator*(float a);
		Vector operator/(float a);

		static Vector MeanPosition(std::vector<Vector> arr);
		static inline double GetSqLength(Vector v);
		static inline double GetSqDistance(Vector pos1, Vector pos2);
	};
}

#endif