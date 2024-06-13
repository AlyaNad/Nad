#include "Customer.h"
#include <ctime>
#include "DBConnection.h" 
#include <vector>
#include <conio.h> 
using namespace std;

std::string Customer::getMaskedInput(const std::string& prompt)
{
	std::string input;
	std::cout << prompt;

	char c;
	while (true)
	{
		c = _getch();

		if (c == 13 || c == 10) // Enter key
			break;
		else if (c == 8) // Backspace key
		{
			if (!input.empty())
			{
				std::cout << "\b \b"; // Move the cursor back and erase the character
				input.pop_back(); // Remove the last character from the string
			}
		}
		else
		{
			std::cout << '*';
			input += c;
		}
	}

	std::cout << std::endl; // Move to the next line after entering the password
	return input;
}
Customer::Customer() { 
	//initialize
	customerId = 0;
	username = "";
	password = "";
	email = "";
	phoneNo = "";
}
Customer::Customer(int customerId, std::string username, std::string password, std::string email, std::string phoneNo) {
	this->customerId = customerId;
	this->username = username;
	this->password = password;
	this->email = email;
	this->phoneNo = phoneNo;
}
bool Customer::login() {

	DBConnection db;
	db.prepareStatement("SELECT * FROM customer WHERE username=? AND password=?");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.QueryResult();
	if (db.res->rowsCount() == 1) {
		while (db.res->next()) {
			customerId = db.res->getInt("customerId");
			username = db.res->getString("username");
			password = db.res->getString("password");
			email = db.res->getString("email");
		}
		db.~DBConnection();
		return true;
	}
	else {

		db.~DBConnection();
		return false;
	}
}
void Customer::insert() {

	DBConnection db;//instantiate
	db.prepareStatement("Insert into customer (username,password,email) VALUES (?,?,?)");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.stmt->setString(3, email);
	db.QueryStatement();
	db.~DBConnection();
}
void Customer::update() {

	DBConnection db;
	db.prepareStatement("UPDATE customer SET username=?, password=?, email=? WHERE staffId=?");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.stmt->setString(3, email);
	db.stmt->setInt(5, customerId);
	db.QueryStatement();
	db.~DBConnection();

}
void Customer::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM customer WHERE stafftId=?");
	db.stmt->setInt(1, customerId);
	db.QueryStatement();
	db.~DBConnection();
}



Customer::~Customer() { 

}


/*Account Account::older(Account a, Account b) {
	if (b.getAge() > a.getAge()) {
		return b;
	}
	return a;
}*/