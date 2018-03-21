#pragma once
const int ClientSize = 20;
const int IBANSize = 50;

class BankAccount
{
private:
	char m_ClientName[ClientSize + 1];
	char m_IBAN[IBANSize + 1];
	float m_Cash;
public:
	BankAccount();
	BankAccount(const char*, const char*, float);
	void PrintAccount() const;
	void Deposit(float);
	void Withdraw(float);
};