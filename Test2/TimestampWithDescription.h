#pragma once
#include "Timestamp.h"

class TimestampWithDescription : public Timestamp
{
private:
	char* m_Name;
public:
	TimestampWithDescription();
	TimestampWithDescription(const unsigned long&,const char*);
	TimestampWithDescription(const TimestampWithDescription&);
	TimestampWithDescription& operator=(const TimestampWithDescription&);
	~TimestampWithDescription();

	void SetDescription(const char*);
	const char* GetDesciption() const;
};

std::istream& operator>>(std::istream&, TimestampWithDescription&);
std::ostream& operator<<(std::ostream&, const TimestampWithDescription&);