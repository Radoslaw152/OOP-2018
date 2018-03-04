#include <iostream>

//Функция, която копира един низ в друг до source[delim]
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

//Функция, която проверява дали даден чар е буква или пунктуационен знак
bool isLetter(const char& tempChar)
{
	return (tempChar >= 'a' && tempChar <= 'z') ||
		(tempChar >= 'A' && tempChar <= 'Z');
}

//Фунцкия, която изчислява колко думи имаме
unsigned int countWords(const char* string)
{
	char tempChar;
	unsigned int counter = 1;
	for (int i = 0; string[i] != '\0'; ++i)
	{
		//Искаме предишния символ да е буква, текущия да не е
		if (i > 0 && isLetter(string[i - 1]) && !isLetter(string[i]))
		{
			++counter;
		}
	}
	return counter;
}
char** getArrayOfStrings(const char* string, const unsigned int& wordsTotal)
{
	//заделяме толкова памет, колкото думи има
	char** arrayOfStrings = new char*[wordsTotal];
	// брояч на коя дума сме в момента
	int currentWord = 0;
	// брояч за колко букви има текущата дума
	int currentChar = 0;
	for (int i = 0; currentWord < wordsTotal; ++i)
	{
		if (i > 0 && !isLetter(string[i]) && isLetter(string[i-1]))
		{
			arrayOfStrings[currentWord] = new char[currentChar + 1];
			//Казваме, че искаме да копираме в arrayOfString[currentWord], низа, който започва от
			//i - currentChar мястото в string, и искаме да копираме точно currentChar символи
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

//Функция, която сравнява колко два низа, като пренебрегва разликата между голяма и малка буква
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

//Функция, която сортира нашите думи по лексикографска наредба
//Използва се алгоритъма за сортиране чрез вмъкване - Insertion Sort
//Разместваме само указатели
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
		//не искаме да print-ваме на конзолата повтарящи се думи
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
