#include "Bank.h"
#include <iostream>
Bank::Bank(const std::string & Name, const std::string & Address) : m_Name{Name},m_Address{Address}, m_Customers{}, m_Accounts{}
{
}

const std::string & Bank::getName() const
{
	return m_Name;
}

const std::string & Bank::getAddress() const
{
	return m_Address;
}

bool Bank::addCustomer(const std::string & customerId, const std::string & name, const std::string & address)
{
	for (unsigned int i = 0; i < m_Customers.size(); ++i)
	{
		if (m_Customers[i].getID() == customerId)
		{
			return false;
		}
	}
	Customer temp{ customerId,name, address };
	m_Customers.push_back(temp);
	return true;
	//Cool stuff down there
	//m_Customers.push_back({ name,address });
}

bool Bank::deleteCustomer(const std::string & customerId)
{
	unsigned int indexCustomer = -1;
	for (unsigned int i = 0; i < m_Customers.size(); ++i)
	{
		if (m_Customers[i].getID() == customerId)
		{
			indexCustomer = i;
			break;
		}
	}
	if (indexCustomer == -1)
	{
		return false;
	}

	for (unsigned int i = 0; i < m_Accounts.size(); ++i)
	{
		if (m_Accounts[i].getOwner() == customerId)
		{
			m_Accounts.erase(m_Accounts.begin() + i);
			--i;
		}
	}

	m_Customers.erase(m_Customers.begin() + indexCustomer);

	return true;


}

bool Bank::addAccount(const std::string & type, const std::string & customerID, const std::string & IBAN, const Money & amount, const Money & other)
{
	for (unsigned int i = 0; i < m_Accounts.size(); ++i)
	{
		if (m_Accounts[i].getIBAN() == IBAN)
		{
			std::cerr << "Error: this IBAN exists!" << std::endl;
			return false;
		}
	}
	bool foundCustomer = false;
	for (unsigned int i = 0; i < m_Customers.size(); ++i)
	{
		if (m_Customers[i].getID() == customerID)
		{
			foundCustomer = true;
			break;
		}
	}
	if (!foundCustomer)
	{
		std::cerr << "Error: this Customer ID does not exist!" << std::endl;
		return false;
	}
	ProxyAccount temp{ type,customerID,IBAN,amount,other };
	m_Accounts.push_back(temp);
	return true;
}

bool Bank::deleteAccount(const std::string & IBAN)
{
	unsigned int foundIBAN = -1;
	for (unsigned int i = 0; i < m_Accounts.size(); ++i)
	{
		if (m_Accounts[i].getIBAN() == IBAN)
		{
			foundIBAN = i;
			break;
		}
	}

	if (foundIBAN == -1)
	{
		std::cerr << "Error: this IBAN does not exist!" << std::endl;
		return false;
	}
	m_Accounts.erase(m_Accounts.begin() + foundIBAN);
	return true;
}

void Bank::listAccounts() const
{
	for (unsigned int i = 0; i < m_Accounts.size(); ++i)
	{
		m_Accounts[i].display();
	}
}

void Bank::listCustomers() const
{
	for (unsigned int i = 0; i < m_Customers.size(); ++i)
	{
		m_Customers[i].display();
	}
}


void Bank::display() const
{
	std::cout << "Number of accounts: " << m_Accounts.size() << std::endl;
	std::cout << "Number of customers: " << m_Customers.size() << std::endl;
}
