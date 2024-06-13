#pragma once
#ifndef STAFF_H
#define STAFF_H
#include <vector>
#include "DBConnection.h"

#include <string>

class Staff
{
public://access specifier
	int staffId; //numerical attributes
	std::string username, password, email, phoneNo; // text attributes


	Staff(); // constructor method
	Staff(int staffId, std::string username, std::string password, std::string email, std::string phoneNo);
	Staff(sql::ResultSet* data); 
	bool login();
	void insert();
	void update();
	void remove();
	static std::vector<Staff> searchStaff(std::string username, std::string email, bool ascending);

	~Staff(); //destructor method
	static std::string getMaskedInput(const std::string& prompt);

	static Staff older(Staff a, Staff b);


};

#endif