#include "Vector.h"

namespace Math
{
	//-------------------------------------------
	// Contructors
	//-------------------------------------------
	Vector::Vector( float x, float y, float z )
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector::Vector( float value )
	{
		this->x = value;
		this->y = value;
		this->z = value;
	}

	Vector::Vector()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	//-------------------------------------------
	// Operators
	//-------------------------------------------
	void Vector::operator+=( Vector& const v )
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
	}

	void Vector::operator-=( Vector& const v )
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
	}

	void Vector::operator*=( float v )
	{
		this->x *= v;
		this->y *= v;
		this->z *= v;
	}

	void Vector::operator/=( float v )
	{
		this->x /= v;
		this->y /= v;
		this->z /= v;
	}

	Vector Vector::operator+( Vector& const a )
	{
		return {
			this->x + a.x,
			this->y + a.y,
			this->z + a.z
		};
	}

	Vector Vector::operator-( Vector& const a )
	{
		return {
			this->x - a.x,
			this->y - a.y,
			this->z - a.z
		};
	}

	Vector Vector::operator*( float a )
	{
		return {
			this->x * a,
			this->y * a,
			this->z * a
		};
	}

	Vector Vector::operator/( float a )
	{
		return {
			this->x / a,
			this->y / a,
			this->z / a
		};
	}

	//-------------------------------------------
	// Other 
	//-------------------------------------------
	Vector Vector::MeanPosition( std::vector<Vector>& const arr )
	{
		Vector result;

		int size = arr.size();
		for ( int i = 0; i < size; i++ )
		{
			result += arr[i];
		}

		result /= size;
		return result;
	}

	inline double Vector::GetSqLength( Vector& const v )
	{
		return v.x * v.x + v.y * v.y + v.z * v.z;
	}

	inline double Vector::GetSqDistance( Vector& const pos1, Vector& const pos2 )
	{
		return
			( pos1.x - pos2.x ) * ( pos1.x - pos2.x ) +
			( pos1.y - pos2.y ) * ( pos1.y - pos2.y ) +
			( pos1.z - pos2.z ) * ( pos1.z - pos2.z );
	}
}