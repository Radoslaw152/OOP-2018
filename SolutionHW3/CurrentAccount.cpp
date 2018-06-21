#include "CurrentAccount.h"
#include <iostream>
Account * CurrentAccount::clone() const
{
	Account* result = new CurrentAccount(*this);
	return result;
}

CurrentAccount::CurrentAccount(const std::string & IBAN, const std::string & Owner, const Money & Amount) : Account{ IBAN,Owner,Amount }
{

}

void CurrentAccount::deposit(const Money & Amount)
{
	m_Amount += Amount;
}

bool CurrentAccount::withdraw(const Money & Amount)
{
	if (m_Amount < Amount)
	{
		std::cerr << "You cannot withdraw this amount!" << std::endl;
		return false;
	}
	m_Amount -= Amount;
	return true;
}

void CurrentAccount::display() const
{
	std::cout << "Type account: Current Account" << std::endl;
	Account::display();
}
