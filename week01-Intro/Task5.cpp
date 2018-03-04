#include <iostream>

//�������, ����� ������ ���� ��� � ���� �� source[delim]
void copyString(char* destination, const char* source, int delim)
{
	if (destination != nullptr && source != nullptr)
	{
		int size = 0;
		while (*source != '\0' && size < delim)
		{
			*destination = *source;
			destination++;
			source++;
			size++;
		}
		*destination = '\0';
	}
}

//�������, ����� ��������� ���� ����� ��� � ����� ��� ������������� ����
bool isLetter(const char& tempChar)
{
	return (tempChar >= 'a' && tempChar <= 'z') ||
		(tempChar >= 'A' && tempChar <= 'Z');
}

//�������, ����� ��������� ����� ���� �����
unsigned int countWords(const char* string)
{
	char tempChar;
	unsigned int counter = 1;
	for (int i = 0; string[i] != '\0'; ++i)
	{
		//������ ��������� ������ �� � �����, ������� �� �� �
		if (i > 0 && isLetter(string[i - 1]) && !isLetter(string[i]))
		{
			++counter;
		}
	}
	return counter;
}
char** getArrayOfStrings(const char* string, const unsigned int& wordsTotal)
{
	//�������� ������� �����, ������� ���� ���
	char** arrayOfStrings = new char*[wordsTotal];
	// ����� �� ��� ���� ��� � �������
	int currentWord = 0;
	// ����� �� ����� ����� ��� �������� ����
	int currentChar = 0;
	for (int i = 0; currentWord < wordsTotal; ++i)
	{
		if (i > 0 && !isLetter(string[i]) && isLetter(string[i-1]))
		{
			arrayOfStrings[currentWord] = new char[currentChar + 1];
			//�������, �� ������ �� �������� � arrayOfString[currentWord], ����, ����� ������� ��
			//i - currentChar ������� � string, � ������ �� �������� ����� currentChar �������
			copyString(arrayOfStrings[currentWord], string + i - currentChar, currentChar);
			currentWord++;
			currentChar = 0;
		}
		else if(isLetter(string[i]))
		{
			currentChar++;
		}
	}
	return arrayOfStrings;
}

//�������, ����� �������� ����� ��� ����, ���� ����������� ��������� ����� ������ � ����� �����
int compareStrings(const char* lhs, const char* rhs)
{
	char tempLeft;
	char tempRight;
	while (*lhs != '\0' && *rhs != '\0')
	{
		tempLeft = *lhs | 32;
		tempRight = *rhs | 32;
		if (tempLeft < tempRight)
		{
			return -1;
		}
		else if (tempLeft > tempRight)
		{
			return 1;
		}
		lhs++;
		rhs++;
	}
	tempLeft = *lhs | 32;
	tempRight = *rhs | 32;
	return tempLeft - tempRight;
}

//�������, ����� ������� ������ ���� �� �������������� �������
//�������� �� ���������� �� ��������� ���� �������� - Insertion Sort
//����������� ���� ���������
void sortArrayOfStrings(char** arrayOfStrings, const unsigned int& size)
{
	for (unsigned int i = 1; i < size; ++i)
	{
		char* min = arrayOfStrings[i];
		int index = i - 1;
		while (index >= 0 && compareStrings(arrayOfStrings[index], min) < 0)
		{
			arrayOfStrings[index + 1] = arrayOfStrings[index];
			index--;
		}
		arrayOfStrings[index + 1] = min;
	}
}

int main()
{
	int size;
	std::cin >> size;
	char* buffer = new char[size + 1];
	std::cin.get();
	std::cin.getline(buffer, size);
	int numberOfWords = countWords(buffer);
	char** arrayOfStrings = getArrayOfStrings(buffer, numberOfWords);
	delete[] buffer;


	sortArrayOfStrings(arrayOfStrings, numberOfWords);


	for (int i = 0; i < numberOfWords; ++i)
	{
		//�� ������ �� print-���� �� ��������� ��������� �� ����
		if (i > 0 && compareStrings(arrayOfStrings[i - 1], arrayOfStrings[i]) == 0)
		{
			continue;
		}
		std::cout << arrayOfStrings[i] << std::endl;
	}

	for (int i = 0; i < numberOfWords; ++i)
	{
		delete[] arrayOfStrings[i];
	}
	delete[] arrayOfStrings;
}