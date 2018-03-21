#include "BankAccount.h"
#include <cstring>
#include <iostream>
BankAccount::BankAccount()
{
	strcpy(m_ClientName, "Unknown");
	strcpy(m_IBAN, "Unknown");
	m_Cash = 0; 
}
BankAccount::BankAccount(const char* clientName, const char* IBAN, float cash)
{
	strcpy(m_ClientName, clientName);
	strcpy(m_IBAN, IBAN);
	m_Cash = cash;
}
void BankAccount::PrintAccount() const
{
	std::cout << "Client name: " << m_ClientName << std::endl;
	std::cout << "IBAN: " << m_IBAN << std::endl;
	std::cout << "Available cash: " << m_Cash << std::endl;
}
void BankAccount::Deposit(float cash)
{
	m_Cash += cash;
}
void BankAccount::Withdraw(float cash)
{
	m_Cash -= cash;
}