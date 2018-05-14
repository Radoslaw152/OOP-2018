#include "Timestamp.h"

Timestamp::Timestamp() : m_Time(0)
{
	//m_Time = 0;
}
Timestamp::Timestamp(const unsigned long& Time) : m_Time(Time)
{
	// m_Time = Time;
}
void Timestamp::SetValue(const unsigned long& Time)
{
	m_Time = Time;
}
unsigned long Timestamp::GetValue() const
{
	return m_Time;
}
Timestamp& Timestamp::operator+=(const unsigned long& Time)
{
	m_Time += Time;
	return *this;
}
Timestamp Timestamp::operator+(const unsigned long& Time) const
{
	Timestamp temp(*this);
	return temp += Time;
}
std::istream& operator>>(std::istream& is, Timestamp& rhs)
{
	unsigned long temp;
	is >> temp;
	rhs.SetValue(temp);
	return is;
}
std::ostream& operator<<(std::ostream& os, const Timestamp& rhs)
{
	return os << rhs.GetValue();
}