#include "Admin.h"
#include <ctime>
#include "DBConnection.h" 
#include <vector>
#include <conio.h> 
using namespace std;

std::string Admin::getMaskedInput(const std::string& prompt)
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
Admin::Admin() {
	//initialize
	adminId = 0;
	username = "";
	password = "";
}
Admin::Admin(int adminId, std::string username, std::string password) {
	this->adminId = adminId;
	this->username = username;
	this->password = password;
}
bool Admin::login() {

	DBConnection db;
	db.prepareStatement("SELECT * FROM admin WHERE username=? AND password=?");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.QueryResult();
	if (db.res->rowsCount() == 1) {
		while (db.res->next()) {
			adminId = db.res->getInt("adminId");
			username = db.res->getString("username");
			password = db.res->getString("password");
		}
		db.~DBConnection();
		return true;
	}
	else {

		db.~DBConnection();
		return false;
	}
}
void Admin::insert() {

	DBConnection db;//instantiate
	db.prepareStatement("Insert into account (username,password,email,yearOfBirth) VALUES (?,?,?,?)");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.QueryStatement();
	db.~DBConnection();
}
void Admin::update() {

	DBConnection db;
	db.prepareStatement("UPDATE admin SET username=?, password=? WHERE adminId=?");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.stmt->setInt(3, adminId);
	db.QueryStatement();
	db.~DBConnection();

}
void Admin::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM account WHERE accountId=?");
	db.stmt->setInt(1, adminId);
	db.QueryStatement();
	db.~DBConnection();
}



Admin::~Admin() {

}


/*Account Account::older(Account a, Account b) {
	if (b.getAge() > a.getAge()) {
		return b;
	}
	return a;
}*/