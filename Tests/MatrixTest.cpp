#include "../Core/Matrix.h"
#include <math.h>
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

			OptorMultipy_MultipiableMatrices_ValidMatrix();

			Transponse_RectangleMatrix_TransponedRectangledMatrix();
			Minor_BorderlineRowAndColumn_ValidMinor();
			Minor_NonExistingRowAndColumn_SameMatrix();
			Minor_NonBorderlineRowAndColumn_ValidMinor();
			Determinant_SquareMatrix_ValidDeterminator();
			Determinant_NotSquareMatrix_Exception();
			Inverse_SquareMatrixWithNonZeroDeterminant_ValidInverseMatrix();
			Inverse_NonSquareMatrixWithNonZeroDeterminant_Exception();
			Inverse_SquareMatrixWithZeroDeterminant_Exception();

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
	bool static ApproximateMatricesComparison(Matrix a, Matrix b)
	{
		if (a.Rows() != b.Rows() ||
			a.Columns() != b.Columns())
		{
			return false;
		}

		for (size_t y = 0; y < a.Rows(); y++)
		{
			for (size_t x = 0; x < a.Columns(); x++)
			{
				bool areEqual = fabs(a[y][x] - b[y][x]) < 0.000001f;
				if (!areEqual)
				{
					return false;
				}
			}
		}

		return true;
	}

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

		for (size_t y = 0; y < a.Rows(); y++)
		{
			for (size_t x = 0; x < a.Columns(); x++)
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

	static void OptorMultipy_MultipiableMatrices_ValidMatrix()
	{
		Matrix a({
			{2, -3, 1},
			{5, 4, -2}
		});

		Matrix b({
			{-7, 5},
			{2, -1},
			{4, 3}
		});

		Matrix expected({
			{-16, 16},
			{-35, 15}
		});

		auto result = a * b;
		if (result != expected)
		{
			throw TestException("Invalid multipying");
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
		catch (std::exception&)
		{
			return;
		}

		throw TestException(
			"Determinant can\'t be calculated for non square matrices, but no exceptions were thrown"
		);
	}

	static void Minor_BorderlineRowAndColumn_ValidMinor()
	{
		Matrix a({
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12}
		});

		int row = 2;
		int column = 3;

		Matrix expected({
			{1, 2, 3},
			{5, 6, 7}
		});

		auto result = a.Minor(row, column);

		if (result != expected)
		{
			throw TestException("Matrix\' minor is not valid");
		}
	}

	static void Minor_NonExistingRowAndColumn_SameMatrix()
	{
		Matrix a({
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12}
		});

		int row = -1;
		int column = 5;

		Matrix expected(a);

		auto result = a.Minor(row, column);
		if (result != expected)
		{
			throw TestException("Matrix\' minor is not valid");
		}
	}

	static void Minor_NonBorderlineRowAndColumn_ValidMinor()
	{
		Matrix a({
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
		});

		int row = 1;
		int column = 1;

		Matrix expected({
			{1, 3},
			{7, 9}
		});

		auto result = a.Minor(row, column);
		if (result != expected)
		{
			throw TestException("Matrix\' minor is not valid");
		}
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

	static void Inverse_SquareMatrixWithNonZeroDeterminant_ValidInverseMatrix()
	{
		Matrix a({
			{-1, 2, -2},
			{2, -1, 5},
			{3, -2, 4}
		});

		Matrix expected({
			{0.6f, -0.4f, 0.8f},
			{0.7f, 0.2f, 0.1f},
			{-0.1f, 0.4f, -0.3f}
		});

		auto result = a.Inverse();
		if (!ApproximateMatricesComparison(result, expected))
		{
			throw TestException("Inverse matrix is not valid");
		}

		result *= a;
		if (!ApproximateMatricesComparison(result, Matrix::IdentityMatrix(3)))
		{
			throw TestException("Inverse matrix is not valid");
		}
	}

	static void Inverse_NonSquareMatrixWithNonZeroDeterminant_Exception()
	{
		Matrix a({
			{-1, 2, -2},
			{2, -1, 5}
		});

		try
		{
			a.Inverse();
		}
		catch (std::exception&)
		{
			return;
		}

		throw TestException("Inverse matrix doesn't exists but it was calculated");
	}

	static void Inverse_SquareMatrixWithZeroDeterminant_Exception()
	{
		Matrix a({
			{-1, 2, -2},
			{-1, 2, -2},
			{3, -2, 4}
		});

		try
		{
			a.Inverse();
		}
		catch (std::exception&)
		{
			return;
		}

		throw TestException("Inverse matrix doesn't exists but it was calculated");
	}
};