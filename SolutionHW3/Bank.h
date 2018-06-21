#pragma once
#include "ProxyAccount.h"
#include "Customer.h"
#include <vector>
#include <string>
class Bank
{
private:
	std::string m_Name;
	std::string m_Address;
	std::vector<Customer> m_Customers;
	std::vector<ProxyAccount> m_Accounts;
public:
	Bank(const std::string& m_Name, const std::string& m_Address);
	
	const std::string& getName() const;
	const std::string& getAddress() const;

	bool addCustomer(const std::string& customerId, const std::string& name, const std::string& address);
	bool deleteCustomer(const std::string& customerId);

	bool addAccount(const std::string& customerId, const std::string& name, const std::string& address, const Money&, const Money&);
	bool deleteAccount(const std::string& IBAN);

	void listAccounts() const;
	void listCustomers() const;

	void display() const;
};
