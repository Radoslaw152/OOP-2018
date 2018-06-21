#pragma once
#include <string>
#include "Account.h"
class SavingsAccount : public Account
{
private:
	Money m_InterestRate;
public:
	Account* clone() const override;
public:
	SavingsAccount(const std::string& IBAN, const std::string& Owner, const Money& Amount, const Money& InterestRate);

	void deposit(const Money& Amount) override;
	bool withdraw(const Money& Amount) override;
	void display() const override;
};