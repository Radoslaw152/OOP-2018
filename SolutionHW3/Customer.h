#pragma once
#include <string>
#include <vector>


class Customer
{
private:
	std::string m_ID;
	std::string m_Name;
	std::string m_Address;
public:
	Customer(const std::string& ID = "m_ID", const std::string& Name = "Unknown", const std::string& Address = "Invalid");

	const std::string& getName() const;
	const std::string& getID() const;
	const std::string& getAddress() const;

	void display() const;
};