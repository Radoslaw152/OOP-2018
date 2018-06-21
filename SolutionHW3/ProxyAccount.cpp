#include "ProxyAccount.h"
#include <iostream>
Account * ProxyAccount::clone() const
{
	if (m_Account != nullptr)
	{
		return m_Account->clone();
	}
	return nullptr;
}

ProxyAccount::ProxyAccount(const std::string& Type,const std::string & IBAN, const std::string & Owner, const Money & Amount, const Money & Other)
	: Account{IBAN,Owner,Amount}
{
	m_Account = Account::factoryMethod(Type,IBAN, Owner, Amount, Other);
}

ProxyAccount::ProxyAccount(const ProxyAccount& rhs) : Account(rhs)
{
	m_Account = rhs.m_Account->clone();
}

ProxyAccount & ProxyAccount::operator=(const ProxyAccount & rhs)
{
	if (this != &rhs)
	{
		delete m_Account;
		if (rhs.m_Account != nullptr)
		{
			m_Account = rhs.m_Account->clone();
		}
		else
		{
			std::cerr << "Cannot clone this object!" << std::endl;
			m_Account = nullptr;
		}
	}
	return *this;
}

ProxyAccount::~ProxyAccount()
{
	delete m_Account;
}

void ProxyAccount::deposit(const Money & Amount)
{
	if (m_Account != nullptr)
	{
		m_Account->deposit(Amount);
	}
}

bool ProxyAccount::withdraw(const Money & Amount)
{
	if (m_Account != nullptr)
	{
		return m_Account->withdraw(Amount);
	}
	return false;
}

void ProxyAccount::display() const
{
	if (m_Account != nullptr)
	{
		m_Account->display();
	}
}
