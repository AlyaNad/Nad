#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include <string>

class Admin
{
public://access specifier
	int adminId; //numerical attributes
	std::string username, password; // text attributes


	Admin(); // constructor method
	Admin(int adminId, std::string username, std::string password);

	bool login();
	void insert();
	void update();
	void remove();

	~Admin(); //destructor method
	static std::string getMaskedInput(const std::string& prompt);


};

#endif