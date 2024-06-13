#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "DBConnection.h"

#include <string>

class Inventory
{
public://access specifier
	int inventoryId; //numerical attributes
	std::string productname, quantity, catogory; // text attributes


	Inventory(); // constructor method
	Inventory(int inventoryId, std::string productname, std::string quantity, std::string catogory);
	Inventory(sql::ResultSet* data);
	void insert();
	void update();
	void remove();
	static std::vector<Inventory> searchInventory(std::string productname, std::string quantity, std::string catogory, bool ascending);

	~Inventory(); //destructor method


};

#endif