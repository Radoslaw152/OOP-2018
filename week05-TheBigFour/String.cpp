#include "String.h"

String::String()
{
	m_Size = 0;
	m_String = new char[m_Size + 1];
	m_String[0] = '\0';
}
String::String(const char* rhs)
{
	m_Size = strlen(rhs);
	m_String = new char[m_Size + 1];
	strcpy(m_String, rhs);
}
String::String(const String& rhs)
{
	m_Size = rhs.m_Size;
	m_String = new char[m_Size + 1];
	strcpy(m_String, rhs.m_String);
}
String& String::operator=(const String& rhs)
{
	if (this != &rhs)
	{
		delete[] m_String;
		m_Size = rhs.m_Size;
		m_String = new char[m_Size + 1];
		strcpy(m_String, rhs.m_String);
	}
	return *this;
}
String::~String()
{
	delete[] m_String;
}

const char* String::getCString() const
{
	return m_String;
}
void String::setString(const char* rhs)
{
	delete[] m_String;
	m_Size = strlen(rhs);
	m_String = new char[m_Size + 1];
	strcpy(m_String, rhs);
}

void String::append(const char* rhs)
{
	int newSize = m_Size + strlen(rhs);
	char* oldString = m_String;
	m_String = new char[newSize + 1];
	strcpy(m_String, oldString);
	delete[] oldString;
	strcpy(m_String + m_Size, rhs);
	m_Size = newSize;
}
void String::append(const String& rhs)
{
	append(rhs.m_String);
}
String String::concat(const String& rhs)
{
	String newString(*this);
	newString.append(rhs);
	return newString;
}
String String::concat(const char* rhs)
{
	String newString(*this);
	newString.append(rhs);
	return newString;
}