#pragma once
#include <string>
#include "Account.h"
class PrivilegeAccount : public Account
{
private:
	Money m_Overdraft;
public:
	Account* clone() const override;
public:
	PrivilegeAccount(const std::string& IBAN, const std::string& Owner, const Money& Amount,const Money& Overdraft);

	void deposit(const Money& Amount) override;
	bool withdraw(const Money& Amount) override;
	void display() const override;
};