#pragma once
#include<iostream>
class Timestamp
{
private:
	unsigned long m_Time;
public:
	Timestamp();
	Timestamp(const unsigned long& Time);
	void SetValue(const unsigned long& Time);
	unsigned long GetValue() const;
	Timestamp& operator+=(const unsigned long& Time);
	Timestamp operator+(const unsigned long& Time) const;
};

std::istream& operator>>(std::istream&, Timestamp&);
std::ostream& operator<<(std::ostream&, const Timestamp&);