#pragma once
#include <vector>
#include <string>

namespace Math
{
	class Matrix
	{
	private: 
		int m_width;
		int m_height;

		std::vector<std::vector<float>> m_buffer;

	public:
		Matrix( const std::vector<std::vector<float>>& arg );
		Matrix( int rows = 0, int columns = 0, float defaultValue = 0 );

		int Rows() const;
		int Columns() const;

		Matrix Transponse() const;
		float Determinator() const;
		Matrix Minor( int row, int column ) const;

		std::vector<std::vector<float>> GetBuffer() const;

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

