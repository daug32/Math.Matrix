#pragma once
#include <vector>
#include <string>

namespace Math
{
	class Matrix
	{
	private: 
		int _width;
		int _height;

	public:
		std::vector<std::vector<float>> Buffer;

		Matrix( const std::vector<std::vector<float>>& arg );
		Matrix( int rows = 0, int columns = 0, float defaultValue = 0 );

		int Rows() const;
		int Columns() const;

		Matrix Transponse() const;
		float Determinator() const;
		Matrix Minor( int row, int column ) const;

		void operator*= ( const Matrix& b );
		void operator+= ( const Matrix& b );
		void operator-= ( const Matrix& b );

		Matrix operator* ( const Matrix& b ) const;
		Matrix operator+ ( const Matrix& b ) const;
		Matrix operator- ( const Matrix& b ) const;

		void operator*= ( float k );
		void operator/= ( float k );
		Matrix operator* ( float k ) const;
		Matrix operator/ ( float k ) const;

		bool operator== ( const Matrix& a ) const;
		bool operator!= ( const Matrix& a ) const;

		std::vector<float>& operator[] ( int n );
	};
}

