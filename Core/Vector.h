#pragma once
#include <vector>

namespace Math
{
	class Vector
	{
	public:
		float x;
		float y;
		float z;

		Vector( float x, float y, float z = 0 );
		Vector( float value );
		Vector();

		void operator+=( Vector& const  v );
		void operator-=( Vector& const v );
		void operator*=( float v );
		void operator/=( float v );

		Vector operator+( Vector& const a );
		Vector operator-( Vector& const a );
		Vector operator*( float a );
		Vector operator/( float a );

		static Vector MeanPosition( std::vector<Vector>& const arr );
		static inline double GetSqLength( Vector& const v );
		static inline double GetSqDistance( Vector& const pos1, Vector& const pos2 );
	};
}
