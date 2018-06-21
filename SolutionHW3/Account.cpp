#include "Account.h"
#include <iostream>
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
Account::Account(const std::string & IBAN, const std::string & Owner, const Money & Amount) : m_IBAN{IBAN},
																							  m_Owner{Owner},
																							  m_Amount{Amount}
{

}

void Account::display() const
{
	std::cout << "IBAN: " << m_IBAN << std::endl;
	std::cout << "Owner: " << m_Owner << std::endl;
	std::cout << "Amount: " << m_Amount << std::endl;
}

const std::string & Account::getIBAN() const
{
	return m_IBAN;
}

const std::string & Account::getOwner() const
{
	return m_Owner;
}

const Money & Account::getAmount() const
{
	return m_Amount;
}

Account * Account::factoryMethod(const std::string & Type, const std::string & IBAN, const std::string & Owner, 
																		const Money & Amount, const Money& Other)
{
	// Let's make the type case insensitive
	std::string caseInsensitive = Type;
	for (int i = 0; i < caseInsensitive.length(); ++i)
	{
		caseInsensitive[i] |= 32;
	}


	Account* result = nullptr;
	if (caseInsensitive == "savings")
	{
		result = new SavingsAccount{ IBAN, Owner, Amount, Other };
	}
	else if(caseInsensitive == "privilege")
	{
		result = new PrivilegeAccount{ IBAN, Owner, Amount, Other };
	}
	else if (caseInsensitive == "current")
	{
		result = new CurrentAccount{ IBAN,Owner,Amount };
	}
	return result;
}
