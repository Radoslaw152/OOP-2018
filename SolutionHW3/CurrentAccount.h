#pragma once
#include <string>
#include "Account.h"
class CurrentAccount : public Account
{
public:
	Account* clone() const override;
public:
	CurrentAccount(const std::string& IBAN, const std::string& Owner, const Money& Amount);

	void deposit(const Money& Amount) override;
	bool withdraw(const Money& Amount) override;
	void display() const override;
};