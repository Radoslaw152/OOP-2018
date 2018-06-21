#include "Customer.h"
#include <iostream>
Customer::Customer(const std::string& ID, const std::string& Name, const std::string& Address) : m_ID{ID},
																								m_Name{Name},
																								m_Address{Address}
{
}

const std::string & Customer::getName() const
{
	return m_Name;
}

const std::string & Customer::getID() const
{
	return m_ID;
}

const std::string & Customer::getAddress() const
{
	return m_Address;
}

void Customer::display() const
{
	std::cout << "Name: " << m_Name << std::endl;
	std::cout << "ID: " << m_ID << std::endl;
	std::cout << "Address: " << m_Address << std::endl;
}
