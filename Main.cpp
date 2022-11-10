#include "stdafx.h"
using namespace Math;

void prtMatrix( Matrix a )
{
	for ( auto& i : a.Buffer )
	{
		for ( auto& j : i )
		{
			std::cout << j << ' ';
		}

		std::cout << std::endl;
	}

	std::cout << "=============\n";
}

int main()
{
	Matrix a(
		{
			{-1, -4, 0, 0, -2},
			{0, 1, 1, 5, 4},
			{3, 1, 7, 1, 0},
			{0, 0, 2, 0, -3},
			{-1, 0, 4, 2, 2}
		} );
	prtMatrix( a );

	auto b = a.Transponse();
	prtMatrix( b );

	std::cout << std::boolalpha << ( b.Determinator() == a.Determinator() ) << std::endl;

	std::cout << std::boolalpha << ( b != a ) << std::endl;

	b = b.Transponse();

	std::cout << std::boolalpha << ( b == a ) << std::endl;

	return 0;
}