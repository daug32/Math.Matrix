#include "Vector3.h"

namespace Math
{
	//-------------------------------------------
	// Contructors
	//-------------------------------------------
	Vector3::Vector3( float x, float y, float z )
	{
		_buffer = { x, y, z };
	}

	Vector3::Vector3( float value )
	{
		_buffer = { value, value, value };
	}

	Vector3::Vector3()
	{
		_buffer = { 0, 0, 0 };
	}

	//-------------------------------------------
	// Getters and setters
	//-------------------------------------------
	float Vector3::GetX() const
	{
		return _buffer[0];
	}

	void Vector3::SetX( float x )
	{
		_buffer[0] = x;
	}

	float Vector3::GetY() const
	{
		return _buffer[1];
	}

	void Vector3::SetY( float y )
	{
		_buffer[1] = y;
	}

	float Vector3::GetZ() const
	{
		return _buffer[2];
	}

	void Vector3::SetZ( float z )
	{
		_buffer[2] = z;
	}

	//-------------------------------------------
	// Operators
	//-------------------------------------------
	void Vector3::operator+=( const Vector3& v )
	{
		_buffer[0] += v.GetX();
		_buffer[1] += v.GetY();
		_buffer[2] += v.GetZ();
	}

	void Vector3::operator-=( const Vector3& v )
	{
		_buffer[0] -= v.GetX();
		_buffer[1] -= v.GetY();
		_buffer[2] -= v.GetZ();
	}

	void Vector3::operator*=( float v )
	{
		_buffer[0] *= v;
		_buffer[1] *= v;
		_buffer[2] *= v;
	}

	void Vector3::operator/=( float v )
	{
		_buffer[0] /= v;
		_buffer[1] /= v;
		_buffer[2] /= v;
	}

	Vector3 Vector3::operator+( const Vector3& a ) const
	{
		return Vector3(
			_buffer[0] + a.GetX(),
			_buffer[1] + a.GetY(),
			_buffer[2] + a.GetZ()
		);
	}

	Vector3 Vector3::operator-( const Vector3& a ) const
	{
		return Vector3(
			_buffer[0] - a.GetX(),
			_buffer[1] - a.GetY(),
			_buffer[2] - a.GetZ()
		);
	}

	Vector3 Vector3::operator*( float a ) const
	{
		return Vector3(
			_buffer[0] * a,
			_buffer[1] * a,
			_buffer[2] * a
		);
	}

	Vector3 Vector3::operator/( float a ) const
	{
		return Vector3(
			_buffer[0] / a,
			_buffer[1] / a,
			_buffer[2] / a
		);
	}

	//-------------------------------------------
	// Other 
	//-------------------------------------------
	Vector3 Vector3::MeanPosition( const std::vector<Vector3>& arr )
	{
		Vector3 result;

		size_t size = arr.size();
		for ( int i = 0; i < size; i++ )
		{
			result += arr[i];
		}

		return result / size;
	}

	inline double Vector3::GetSqLength( const Vector3& v )
	{
		float x = v.GetX();
		float y = v.GetY();
		float z = v.GetZ();

		return x * x + y * y + z * z;
	}

	inline double Vector3::GetSqDistance( const Vector3& pos1, const Vector3& pos2 )
	{
		float xDiff = pos1.GetX() - pos2.GetX();
		float yDiff = pos1.GetY() - pos2.GetY();
		float zDiff = pos1.GetZ() - pos2.GetZ();

		return xDiff * xDiff + yDiff * yDiff + zDiff * zDiff;
	}
}