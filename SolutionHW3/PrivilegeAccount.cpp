#include "PrivilegeAccount.h"
#include <iostream>
Account* PrivilegeAccount::clone() const
{
	Account* result = new PrivilegeAccount(*this);
	return result;
}

PrivilegeAccount::PrivilegeAccount(const std::string & IBAN, const std::string & Owner, const Money & Amount, const Money & Overdraft) 
	: Account{IBAN, Owner, Amount},
	m_Overdraft{Overdraft}
{
}

void PrivilegeAccount::deposit(const Money & Amount)
{
	m_Amount += Amount;
}

bool PrivilegeAccount::withdraw(const Money & Amount)
{
	if (m_Amount + m_Overdraft < Amount)
	{
		std::cerr << "You cannot withdraw this amount of money!" << std::endl;
		return false;
	}
	m_Amount -= Amount;
	return m_Amount;
}

void PrivilegeAccount::display() const
{
	std::cout << "Type account: Privilege Account" << std::endl;
	Account::display();
	std::cout << "Overdraft:" << m_Overdraft << std::endl;
}
