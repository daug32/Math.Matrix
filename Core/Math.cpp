#include "Math.h"
#include <stdexcept>

namespace Math
{
	inline float Radians( float degrees )
	{
		return PI / 180.f * degrees;
	}

	inline float Degrees( float radians )
	{
		return 180.f / PI * radians;
	}

	Vector3 MatrixToVector( const Matrix& a )
	{
		Vector3 result;
		
		result.SetX( a.Buffer[0][0] );
		result.SetY( a.Buffer[1][0] );
		result.SetZ( a.Buffer[2][0] );

		return result;
	}

	Matrix VectorToMatrix( const Vector3& a )
	{
		Matrix result( 3, 1 );
		
		result[0][0] = a.GetX();
		result[1][0] = a.GetY();
		result[2][0] = a.GetZ();

		return result;
	}

	Matrix RotationXY( float angle, int scale )
	{
		if ( scale < 3 )
		{
			throw std::invalid_argument( "Matrix scale is less then 3" );
		}

		float sin = std::sin( angle );
		float cos = std::cos( angle );

		auto result = IdentityMatrix( scale );

		result[0][0] = cos;
		result[0][1] = -sin;
		result[1][0] = sin;
		result[1][1] = cos;

		return result;
	}

	Matrix RotationYZ( float angle, int scale )
	{
		if ( scale < 3 )
		{
			throw std::invalid_argument( "Matrix scale is less then 3" );
		}

		float sin = std::sin( angle );
		float cos = std::cos( angle );

		auto result = IdentityMatrix( scale );

		result[1][1] = cos;
		result[1][2] = -sin;
		result[2][1] = sin;
		result[2][2] = cos;

		return result;
	}

	Matrix RotationXZ( float angle, int scale )
	{
		if ( scale < 3 )
		{
			throw std::invalid_argument( "Matrix scale is less then 3" );
		}
		
		float sin = std::sin( angle );
		float cos = std::cos( angle );
		
		auto result = IdentityMatrix( scale );
		
		result[0][0] = cos;
		result[0][2] = sin;
		result[2][0] = -sin;
		result[2][2] = cos;

		return result;
	}

	Matrix IdentityMatrix( int size )
	{
		Matrix result( size, size, 0 );
		
		for ( int i = 0; i < result.Rows(); i++ )
		{
			result[i][i] = 1;
		}

		return result;
	}

}