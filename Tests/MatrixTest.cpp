#include "../Core/stdafx.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include "TestException.h"
using namespace Math;
using std::vector;

class MatrixTest
{
public:
	static bool Run()
	{
		try
		{
			Ctor_From2DArray_SuccessfullInitializationAndArraysIsNotModified();
			Transponse_RectangleMatrix_TransponedRectangledMatrix();
			Determinant_SquareMatrix_ValidDeterminator();
			Determinant_NotSquareMatrix_Exception();
			IdentityMatrix();
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
			return false;
		}

		return true;
	}

private:
	static void Ctor_From2DArray_SuccessfullInitializationAndArraysIsNotModified()
	{
		vector<vector<float>> matrixBuffer =
		{
			{-1, -4, 0, 0, -2},
			{0, 1, 1, 5, 4},
			{3, 1, 7, 1, 0},
			{0, 0, 2, 0, -3},
			{-1, 0, 4, 2, 2}
		};

		Matrix a(matrixBuffer);

		if (a.Rows() != matrixBuffer.size())
		{
			throw TestException(
				"Invalid matrix row number",
				std::to_string(a.Rows()),
				std::to_string(matrixBuffer.size())
			);
		}

		if (a.Columns() != matrixBuffer[0].size())
		{
			throw TestException(
				"Invalid matrix column number",
				std::to_string(a.Columns()),
				std::to_string(matrixBuffer[0].size())
			);
		}

		for (int y = 0; y < a.Rows(); y++)
		{
			for (int x = 0; x < a.Columns(); x++)
			{
				if (a[y][x] == matrixBuffer[y][x])
				{
					continue;
				}

				throw TestException(
					"Invalid matrix value",
					std::to_string(a.Columns()),
					std::to_string(matrixBuffer[0].size())
				);
			}
		}
	}

	static void Transponse_RectangleMatrix_TransponedRectangledMatrix()
	{
		Matrix a({
			{2, 1, 1, 1, 3},
			{3, 2, 2, 2, 4},
			{4, 3, 3, 3, 5},
		});

		Matrix expected({
			{2, 3, 4},
			{1, 2, 3},
			{1, 2, 3},
			{1, 2, 3},
			{3, 4, 5}
		});

		if (a.Transponse() != expected)
		{
			throw TestException("Matrices are not equal");
		}
	}

	static void Determinant_SquareMatrix_ValidDeterminator()
	{
		Matrix a({
			{1, 2, 3, 4},
			{23, -1, 0, 7},
			{9, 3, 9, 9},
			{7, 2, 7, 23}
		});

		float expected = -3135;

		float result = a.Determinant();

		if (expected != result)
		{
			throw TestException(
				"Determinant is not valid",
				std::to_string(expected),
				std::to_string(result)
			);
		}
	}

	static void Determinant_NotSquareMatrix_Exception()
	{
		Matrix a({
			{1, 2, 3, 4},
			{23, -1, 0, 7},
		});

		try
		{
			a.Determinant();
		}
		catch (std::exception& ex)
		{
			return;
		}

		throw TestException(
			"Determinant can\'t be calculated for non square matrices, but no exceptions were thrown"
		);
	}

	static void IdentityMatrix()
	{
		Matrix expected({
			{1, 0, 0}, 
			{0, 1, 0}, 
			{0, 0, 1}
		});

		auto result = Matrix::IdentityMatrix(3);

		if (expected != result)
		{
			throw TestException("Invalid identity matrix");
		}
	}
};