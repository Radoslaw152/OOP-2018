#include "TimestampWithDescription.h"
#include <cstring>
#pragma warning(disable:4996)
TimestampWithDescription::TimestampWithDescription() : Timestamp()
{
	m_Name = new char[1];
	m_Name[0] = '\0';
}
TimestampWithDescription::TimestampWithDescription(const unsigned long& Time,const char* Name) : Timestamp(Time)
{
	m_Name = new char[strlen(Name) + 1];
	strcpy(m_Name, Name);
}
TimestampWithDescription::TimestampWithDescription(const TimestampWithDescription& rhs) : Timestamp(rhs)
{
	m_Name = new char[strlen(rhs.m_Name) + 1];
	strcpy(m_Name, rhs.m_Name);
}
TimestampWithDescription& TimestampWithDescription::operator=(const TimestampWithDescription& rhs)
{
	if (this != &rhs)
	{
		Timestamp::operator=(rhs);
		delete[] m_Name;
		m_Name = new char[strlen(rhs.m_Name) + 1];
		strcpy(m_Name, rhs.m_Name);
	}
	return *this;
}
TimestampWithDescription::~TimestampWithDescription()
{
	delete[] m_Name;
}

void TimestampWithDescription::SetDescription(const char* Name)
{
	delete[] m_Name;
	m_Name = new char[strlen(Name) + 1];
	strcpy(m_Name, Name);
}
const char* TimestampWithDescription::GetDesciption() const
{
	return m_Name;
}
std::istream& operator>>(std::istream& is, TimestampWithDescription& rhs)
{
	char buffer[1000];
	unsigned long temp;
	is >> temp;
	is.get();
	is.getline(buffer, 1000);
	rhs.SetValue(temp);
	rhs.SetDescription(buffer);
	return is;
}
std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& rhs)
{
	return os << rhs.GetValue() << " " << rhs.GetDesciption();
}