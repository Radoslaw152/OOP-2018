int Strlen(const char* str)
{
	if (str == nullptr)
	{
		return -1;
	}
	int size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return size;
}
int Strcmp(const char* lhs, const char* rhs)
{
	if (lhs == nullptr || rhs == nullptr)
	{
		return -2;
	}
	int i;
	for (i = 0; lhs[i] != '\0' && rhs[i] != '\0'; ++i)
	{
		if (lhs[i] < rhs[i])
		{
			return -1;
		}
		if (lhs[i] > rhs[i])
		{
			return 1;
		}
	}
	if (lhs[i] != '\0' && rhs[i] == '\0')
	{
		return 1;
	}
	if (lhs[i] == '\0' && rhs[i] != '\0')
	{
		return -1;
	}
	return 0;
}

void Strcpy(char* destination, const char* source)
{
	if (destination == nullptr || source == nullptr)
	{
		return;
	}
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		++i;
	}
	destination[i] = '\0';
}


void Strcat(char* destination, const char* source)
{

	// MAGIC
	// We just want to copy the information in source
	// when destination ends
	Strcpy(destination + Strlen(destination), source);
}
