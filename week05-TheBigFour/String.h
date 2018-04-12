#ifndef STRING_H_
#define STRING_H_
#include <cstring>

class String
{
private:
	char* m_String;
	unsigned int m_Size;
public:
	String();
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	unsigned int getSize() const;
	const char* getCString() const;
	void setString(const char*);

	void append(const char*);
	void append(const String&);
	String concat(const String&) const;
	String concat(const char*) const;
};
#endif