#include "MatrixTest.cpp"

int main()
{
	bool successfull = MatrixTest::RunAll();
	if (successfull)
	{
		std::cout << "Tests are successfull" << std::endl;
		return 0;
	}

	return 1;
}
