#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{
public://access specifier
	int customerId; //numerical attributes
	std::string username, password, email, phoneNo; // text attributes


	Customer(); // constructor method
	Customer(int customerId, std::string username, std::string password, std::string email, std::string phoneNo);

	bool login();
	void insert();
	void update();
	void remove();

	~Customer(); //destructor method
	static std::string getMaskedInput(const std::string& prompt);

	static Customer older(Customer a, Customer b);


};

#endif