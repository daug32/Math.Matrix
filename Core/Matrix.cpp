#include "Matrix.h"
#include <iostream>
#include <stdexcept>

namespace Math
{
	Matrix::Matrix( int rows, int columns, float defaultValue )
	{
		_height = rows;
		_width = columns;

		Buffer.resize( rows );

		for ( auto& row : Buffer )
		{
			row.resize( columns, defaultValue );
		}
	}

	Matrix::Matrix( const std::vector<std::vector<float>>& arg )
	{
		_height = arg.size();
		_width = _height > 0 ? arg[0].size() : 0;

		Buffer = arg;
	}

	//=============================
	//Methods
	//=============================
	int Matrix::Rows() const
	{
		return _height;
	}

	int Matrix::Columns() const
	{
		return _width;
	}

	float Matrix::Determinator() const
	{
		if ( _height != _width )
		{
			throw std::invalid_argument( "Can't calculate determinator for not sqгare matrix" );
		}

		if ( _height == 2 )
		{
			return
				Buffer[0][0] * Buffer[1][1] -
				Buffer[1][0] * Buffer[0][1];
		}

		float result = 0;
		float k = -1;

		Matrix a( *this );
		for ( int i = 0; i < _width; i++ )
		{
			result += ( k *= -1 ) * a[0][i] * a.Minor( 0, i ).Determinator();
		}

		return result;
	}

	Matrix Matrix::Transponse() const
	{
		Matrix result( _width, _height );

		for ( int y = 0; y < _height; y++ )
		{
			for ( int x = 0; x < _width; x++ )
			{
				result[x][y] = Buffer[y][x];
			}
		}

		return result;
	}

	Matrix Matrix::Minor( int row, int column ) const
	{
		if ( row < 0 || row > _height ||
			column < 0 || column > _width )
		{
			throw std::invalid_argument( "Can't find minor with those arguments" );
		}

		int targetRowCount = _height - 1;
		int targetColumnCount = _width - 1;
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

				result[i][j] = Buffer[y][x];
				x++;
			}

			y++;
		}

		return result;
	}

	//=============================
	//Operators
	//=============================
	Matrix Matrix::operator* ( const Matrix& b ) const
	{
		if ( _width != b._height )
		{
			throw std::invalid_argument( "Impossible to multipy those matrices" );
		}

		Matrix r( _height, b._width );

		for ( int firstY = 0; firstY < _height; firstY++ )
		{
			for ( int secondX = 0; secondX < b._width; secondX++ )
			{
				for ( int firstX = 0; firstX < _width; firstX++ )
				{
					r[firstY][secondX] += 
						Buffer[firstY][firstX] * 
						b.Buffer[firstX][secondX];
				}
			}
		}

		return r;
	}

	Matrix Matrix::operator+ ( const Matrix& b ) const
	{
		if ( _width != b._width || _height != b._height )
		{
			throw std::invalid_argument( "Matrices have different sizes" );
		}

		Matrix r( *this );

		for ( int y = 0; y < _height; y++ )
		{
			for ( int x = 0; x < _width; x++ )
			{
				r[y][x] += b.Buffer[y][x];
			}
		}

		return r;
	}

	Matrix Matrix::operator- ( const Matrix& b ) const
	{
		if ( _width != b._width || _height != b._height )
		{
			throw std::invalid_argument( "Matrices have different sizes" );
		}

		Matrix r( *this );

		for ( int y = 0; y < _height; y++ )
		{
			for ( int x = 0; x < _width; x++ )
			{
				r[y][x] -= b.Buffer[y][x];
			}
		}

		return r;
	}

	void Matrix::operator*= ( const Matrix& b )
	{
		*this = *this * b;
	}

	void Matrix::operator+= ( const Matrix& b )
	{
		*this = *this + b;
	}

	void Matrix::operator-= ( const Matrix& b )
	{
		*this = *this - b;
	}

	Matrix Matrix::operator* ( float k ) const
	{
		Matrix r( *this );

		for ( int y = 0; y < _height; y++ )
		{
			for ( int x = 0; x < _width; x++ )
			{
				r[y][x] *= k;
			}
		}

		return r;
	}
	Matrix Matrix::operator/ ( float k ) const
	{
		if ( k == 0 )
		{
			throw std::invalid_argument( "Can't devide by 0" );
		}

		Matrix r( *this );

		for ( int y = 0; y < _height; y++ )
		{
			for ( int x = 0; x < _width; x++ )
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
		return Buffer[n];
	}

	bool Matrix::operator== ( const Matrix& a ) const
	{
		if ( a._width != _width || a._height != _height )
		{
			return false;
		}

		for ( int y = 0; y < _height; y++ )
		{
			for ( int x = 0; x < _width; x++ )
			{
				if ( a.Buffer[y][x] != Buffer[y][x] )
				{
					return false;
				}
			}
		}

		return true;
	}

	bool Matrix::operator!= ( const Matrix& a ) const
	{
		return !this->operator==( a );
	}
}
