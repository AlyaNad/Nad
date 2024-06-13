#pragma once
#ifndef CAT_H
#define CAT_H

#include <string>

class Cat
{
public://access specifier
	int catId, customerId; //numerical attributes
	std::string catName, catSpecies, catAge; // text attributes


	Cat(); // constructor method
	Cat(int catId, std::string catName, std::string catSpecies, std::string catAge, int customerId);

	int generatedcatId;
	int insertcat(); 
	void update();
	void remove();

	~Cat(); //destructor method


	static Cat older(Cat a, Cat b);


};

#endif