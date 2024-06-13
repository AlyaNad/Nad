#pragma once
#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <vector>
#include "Hotelroom.h"

class Payment
{
public:

	std::string dateTime;
	int paymentId, user;

	std::vector<std::pair<Hotelroom, int>> items; // pair of product and its quantity, represents the transaction_item table

	Payment();
	void addProduct(Hotelroom room, int quantity);
	void insert();
	double total();
	int count();
};


#endif