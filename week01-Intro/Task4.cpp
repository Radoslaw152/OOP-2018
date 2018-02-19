#include <iostream>
#include <cstring>

int LengthOfNewString(const char* text, const char* what, const char* with)
{
	int timesOfWhat = 0;
	int lengthOfWhat = strlen(what);
	for (int i = 0; text[i] != '\0'; ++i)
	{
		if (strncmp(text + i, what, lengthOfWhat) == 0)
		{
			timesOfWhat++;
			i += lengthOfWhat;
		}
	}
	return strlen(text) + timesOfWhat * (strlen(with) - lengthOfWhat);
}
char* ReplaceAll(const char* text, const char* what, const char* with)
{
	int lengthOfNewString = LengthOfNewString(text, what, with);
	char* newString = new char[lengthOfNewString + 1];
	int lengthOfWhat = strlen(what);
	int lengthOfWith = strlen(with);
	for (int i = 0, k = 0; i < lengthOfNewString; ++i, ++k)
	{
		if (strncmp(text + k, what, lengthOfWhat) == 0)
		{
			for (int j = 0; j < lengthOfWith; ++j)
			{
				newString[i + j] = with[j];
			}
			i += lengthOfWith - 1;
			k += lengthOfWhat - 1;
		}
		else
		{
			newString[i] = text[k];
		}
	}
	newString[lengthOfNewString] = '\0';
	return newString;
}
int main()
{
	const char* str1 = "I have an exam tomorrow, but tomorrow is my birthday.";
	const char* str2 = "tomorrow";
	const char* str3 = "today";
	char* newString = ReplaceAll(str1, str2, str3);
	std::cout << newString << std::endl;
	delete[] newString;
	return 0;
}