#pragma once
#include <string>
#include <vector>

typedef long long Money;

class Account
{
protected:
	std::string m_IBAN;
	std::string m_Owner;
	Money m_Amount;
public:
	virtual Account* clone() const = 0;
public:
	Account(const std::string& IBAN, const std::string& Owner, const Money& Amount);
	virtual ~Account() {};
	
	virtual void deposit(const Money& Amount) = 0;
	virtual bool withdraw(const Money& Amount) = 0;
	virtual void display() const = 0;

	const std::string& getIBAN() const;
	const std::string& getOwner() const;
	const Money& getAmount() const;

	static Account* factoryMethod(const std::string&, const std::string&, const std::string&, const Money&, const Money& = 0);

	
};
