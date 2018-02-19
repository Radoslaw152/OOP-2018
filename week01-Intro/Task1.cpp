#include <iostream>
bool isTrion(const int* arr, int size)
{
	/*
	every sequence with size 2 or lower is a trion
	*/
	if (size <= 2)
	{
		return true;
	}
	
	bool biggerOnLeft = arr[0] > arr[1];

	for (int i = 0; i < size - 1; ++i)
	{
		if (biggerOnLeft)
		{
			if (arr[i] <= arr[i + 1])
			{
				return false;
			}
		}
		else
		{
			if (arr[i] >= arr[i + 1])
			{
				return false;
			}
		}
		biggerOnLeft = !biggerOnLeft;
	}
	return true;
}
int main()
{
	int length;
	std::cin >> length;
	int* mySequence = new int[length];
	for (int i = 0; i < length; ++i)
	{
		std::cin >> mySequence[i];
	}
	if (isTrion(mySequence, length))
	{
		std::cout << "Yes\n";
	}
	else
	{
		std::cout << "No\n";
	}
	delete[] mySequence;
	return 0;
}