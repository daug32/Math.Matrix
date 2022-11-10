#pragma once
#include <vector>
#include <string>

namespace Math
{
	class Matrix
	{
	public:
		std::vector<std::vector<float>> buffer;

		Matrix( int rows = 0, int columns = 0, float defaultValue = 0 );
		Matrix( const std::vector<std::vector<float>>& arg );
		Matrix( std::vector<std::vector<float>>& const arg );

		int Rows();
		int Columns();

		float Determinator();
		static Matrix Transponse( Matrix& const a );
		Matrix Minor( int row, int column );

		void operator*= ( Matrix& const b );
		void operator+= ( Matrix& const b );
		void operator-= ( Matrix& const b );

		Matrix operator* ( Matrix& const b );
		Matrix operator+ ( Matrix& const b );
		Matrix operator- ( Matrix& const b );

		void operator*= ( float k );
		void operator/= ( float k );
		Matrix operator* ( float k );
		Matrix operator/ ( float k );

		std::vector<float>& operator[] ( int n );
	};
}

