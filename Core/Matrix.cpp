#include "Matrix.h"
#include <iostream>
#include <stdexcept>

namespace Math
{
	Matrix::Matrix( int rows, int columns, float defaultValue )
	{
		buffer.resize( rows );
		for ( auto& i : buffer )
		{
			i.resize( columns );
			for ( auto& j : i )
			{
				j = defaultValue;
			}
		}
	}

	Matrix::Matrix( const std::vector<std::vector<float>>& arg )
	{
		buffer = arg;
	}

	Matrix::Matrix( std::vector<std::vector<float>>& const arg )
	{
		buffer = arg;
	}

	//=============================
	//Methods
	//=============================
	int Matrix::Rows()
	{
		return buffer.size();
	}

	int Matrix::Columns()
	{
		return buffer[0].size();
	}

	float Matrix::Determinator()
	{
		int size = Rows();
		if ( size != Columns() )
		{
			throw std::invalid_argument( "Can't calculate determinator for not sqгare matrix" );
		}

		if ( size == 2 )
		{
			return
				buffer[0][0] * buffer[1][1] -
				buffer[1][0] * buffer[0][1];
		}

		float result = 0;
		float k = -1;

		Matrix a( *this );
		for ( int i = 0; i < Columns(); i++ )
		{
			result += ( k *= -1 ) * a[0][i] * a.Minor( 0, i ).Determinator();
		}

		return result;
	}

	Matrix Matrix::Transponse( Matrix& const a )
	{
		Matrix result( a.Columns(), a.Rows() );

		for ( int i = 0; i < a.Rows(); i++ )
		{
			for ( int j = 0; j < a.Columns(); j++ )
			{
				result[j][i] = a[i][j];
			}
		}

		return result;
	}

	Matrix Matrix::Minor( int row, int column )
	{
		int rowCount = Rows();
		int columnCount = Columns();

		if ( row < 0 || row > rowCount ||
			column < 0 || column > columnCount )
		{
			throw std::invalid_argument( "Can't find minor with those arguments" );
		}

		int targetRowCount = rowCount - 1;
		int targetColumnCount = columnCount - 1;
		Matrix result = Matrix( targetRowCount, targetColumnCount );

		int y = 0;
		for ( int i = 0; i < targetRowCount; i++ )
		{
			if ( y == row )
			{
				y++;
			}

			int x = 0;

			for ( int j = 0; j < targetColumnCount; j++ )
			{
				if ( x == column )
				{
					x++;
				}

				result[i][j] = buffer[y][x];
				x++;
			}

			y++;
		}

		return result;
	}

	//=============================
	//Operators
	//=============================
	Matrix Matrix::operator* ( Matrix& const b )
	{
		if ( Columns() != b.Rows() )
		{
			throw std::invalid_argument( "Impossible to multipy those matrices" );
		}

		Matrix r( Rows(), b.Columns() );

		for ( int fy = 0; fy < Rows(); fy++ )
		{
			for ( int sx = 0; sx < b.Columns(); sx++ )
			{
				for ( int fx = 0; fx < Columns(); fx++ )
				{
					r[fy][sx] += buffer[fy][fx] * b[fx][sx];
				}
			}
		}

		return r;
	}

	Matrix Matrix::operator+ ( Matrix& const b )
	{
		if ( Columns() != b.Columns() || Rows() != b.Rows() )
		{
			throw std::invalid_argument( "Matrices have different sizes" );
		}

		Matrix r( *this );

		for ( int y = 0; y < Rows(); y++ )
		{
			for ( int x = 0; x < Columns(); x++ )
			{
				r[y][x] += b[y][x];
			}
		}

		return r;
	}

	Matrix Matrix::operator- ( Matrix& const b )
	{
		if ( Columns() != b.Columns() || Rows() != b.Rows() )
		{
			throw std::invalid_argument( "Matrices have different sizes" );
		}

		Matrix r( *this );

		for ( int y = 0; y < Rows(); y++ )
		{
			for ( int x = 0; x < Columns(); x++ )
			{
				r[y][x] -= b[y][x];
			}
		}

		return r;
	}

	void Matrix::operator*= ( Matrix& const b )
	{
		*this = *this * b;
	}

	void Matrix::operator+= ( Matrix& const b )
	{
		*this = *this + b;
	}

	void Matrix::operator-= ( Matrix& const b )
	{
		*this = *this - b;
	}

	Matrix Matrix::operator* ( float k )
	{
		Matrix r( *this );

		for ( int y = 0; y < Rows(); y++ )
		{
			for ( int x = 0; x < Columns(); x++ )
			{
				r[y][x] *= k;
			}
		}

		return r;
	}
	Matrix Matrix::operator/ ( float k )
	{
		if ( k == 0 )
		{
			throw std::invalid_argument( "Can't devide by 0" );
		}

		Matrix r( *this );

		for ( int y = 0; y < Rows(); y++ )
		{
			for ( int x = 0; x < Columns(); x++ )
			{
				r[y][x] /= k;
			}
		}

		return r;
	}

	void Matrix::operator*= ( float k )
	{
		*this = *this * k;
	}

	void Matrix::operator/= ( float k )
	{
		*this = *this / k;
	}

	inline std::vector<float>& Matrix::operator[] ( int n )
	{
		return buffer[n];
	}
}
