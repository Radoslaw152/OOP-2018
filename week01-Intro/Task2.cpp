#include <iostream>
bool isHole(int** matrix, int i, int j, int maxRows, int maxColumns)
{
	if (i - 1 >= 0)
	{
		if (matrix[i - 1][j] < matrix[i][j])
		{
			return false;
		}
		if (j - 1 >= 0 && matrix[i - 1][j - 1] < matrix[i][j])
		{
			return false;
		}
		if (j + 1 < maxColumns && matrix[i - 1][j + 1] < matrix[i][j])
		{
			return false;
		}
	}
	if (i + 1 < maxRows)
	{
		if (matrix[i + 1][j] < matrix[i][j])
		{
			return false;
		}
		if (j - 1 >= 0 && matrix[i + 1][j - 1] < matrix[i][j])
		{
			return false;
		}
		if (j + 1 < maxColumns && matrix[i + 1][j + 1] < matrix[i][j])
		{
			return false;
		}
	}
	if (j - 1 >= 0 && matrix[i][j - 1] < matrix[i][j])
	{
		return false;
	}
	if (j + 1 < maxColumns && matrix[i][j + 1] < matrix[i][j])
	{
		return false;
	}
	return true;
}


int main()
{
	int M, N;
	std::cin >> M >> N;
	int** matrix = new int*[M];
	for (int i = 0; i < M; ++i)
	{
		matrix[i] = new int[N];
		for (int j = 0; j < N; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}


	int howManyHoles = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (isHole(matrix, i, j, M, N))
			{
				howManyHoles++;
			}
		}
	}

	std::cout << howManyHoles << std::endl;
	for (int i = 0; i < M; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}