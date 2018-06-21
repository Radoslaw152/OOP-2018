#pragma once
#include <string>
#include "Account.h"
class ProxyAccount : public Account
{
private:
	Account* m_Account;
private:
	Account* clone() const override;
public:
	ProxyAccount(const std::string& type, const std::string& IBAN, const std::string& Owner, const Money& Amount, const Money& other = 0);
	ProxyAccount(const ProxyAccount&);
	ProxyAccount& operator=(const ProxyAccount&);
	~ProxyAccount();
	void deposit(const Money& Amount) override;
	bool withdraw(const Money& Amount) override;
	void display() const override;
};