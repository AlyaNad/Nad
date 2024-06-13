#pragma once
#ifndef HOTELROOM_H
#define HOTELROOM_H

#include <string>
#include <vector>
#include "DBConnection.h"

class Hotelroom
{
public:
	int roomId, capacity;
	std::string roomName;
	double price;

	Hotelroom();
	Hotelroom(sql::ResultSet* data);

	~Hotelroom();

	static Hotelroom findHotelroom(int roomId);

	static std::vector<Hotelroom> findHotelroom(int capacity, std::string roomName, std::string sortColumn, bool ascending);

};


#endif