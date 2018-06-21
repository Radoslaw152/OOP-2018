#include "SavingsAccount.h"
#include <iostream>
Account * SavingsAccount::clone() const
{
	Account* result = new SavingsAccount(*this);
	return result;
}

SavingsAccount::SavingsAccount(const std::string & IBAN, const std::string & Owner, const Money & Amount, const Money & InterestRate)
	: Account{IBAN,Owner,Amount},
	m_InterestRate(InterestRate)
{
}

void SavingsAccount::deposit(const Money & Amount)
{
	m_Amount += Amount;
}

bool SavingsAccount::withdraw(const Money & Amount)
{
	if (m_Amount < Amount)
	{
		std::cerr << "You cannot withdraw this amount!" << std::endl;
		return false;
	}
	m_Amount -= Amount;
	return true;
}

void SavingsAccount::display() const
{
	std::cout << "Type account: Savings Account" << std::endl;
	Account::display();
	std::cout << "Interest rate:" << m_InterestRate << std::endl;
}
