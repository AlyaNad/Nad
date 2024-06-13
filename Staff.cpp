#include "Staff.h"
#include <ctime>
#include "DBConnection.h" 
#include <vector>
#include <conio.h> 
using namespace std;

std::string Staff::getMaskedInput(const std::string& prompt)
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
Staff::Staff() {
	//initialize
	staffId = 0;
	username = "";
	password = "";
	email = "";
	phoneNo = ""; 
}
Staff::Staff(int staffId, std::string username, std::string password, std::string email, std::string phoneNo) {
	this->staffId = staffId;
	this->username = username;
	this->password = password;
	this->email = email;
	this->phoneNo = phoneNo;
}
Staff::Staff(sql::ResultSet* data)
{
	DBConnection db;
	db.prepareStatement("SELECT * FROM staff");
	staffId = data->getInt("staffId");
	username = data->getString("username");
	password = data->getString("password");
	email = data->getString("email");
	phoneNo = data->getString("phoneNo");
}
bool Staff::login() {

	DBConnection db;
	db.prepareStatement("SELECT * FROM staff WHERE username=? AND password=?");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.QueryResult();
	if (db.res->rowsCount() == 1) {
		while (db.res->next()) {
			staffId = db.res->getInt("staffId");
			username = db.res->getString("username");
			password = db.res->getString("password");
			email = db.res->getString("email");
			phoneNo = db.res->getString("phoneNo");
		}
		db.~DBConnection();
		return true;
	}
	else {

		db.~DBConnection();
		return false;
	}
}
void Staff::insert() {

	DBConnection db;//instantiate
	db.prepareStatement("Insert into staff (username,password,email,phoneNo) VALUES (?,?,?,?)");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.stmt->setString(3, email);
	db.stmt->setString(4, phoneNo);
	db.QueryStatement();
	db.~DBConnection();
}
void Staff::update() {

	DBConnection db;
	db.prepareStatement("UPDATE staff SET phoneNo=? WHERE staffId=?");
	db.stmt->setString(1, phoneNo);
	db.stmt->setInt(2, staffId);
	db.QueryStatement();
	db.~DBConnection();

}
void Staff::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM staff WHERE staffId=?");
	db.stmt->setInt(1, staffId);
	db.QueryStatement();
	db.~DBConnection();
}
std ::vector<Staff> Staff::searchStaff(string userame, string email, bool ascending)
{
	string query = "SELECT * FROM staff WHERE"
		" username LIKE ? AND email LIKE ?"
		" ORDER BY staffID ";

	if (ascending)
	{
		query += " ASC";
	}
	else
	{
		query += " DESC";
	}

	DBConnection db;
	db.prepareStatement(query);
	db.stmt->setString(1, "%" + userame + "%");
	db.stmt->setString(2, "%" + email + "%");

	std ::vector<Staff> user;

	db.QueryResult();

	if (db.res->rowsCount() > 0)
	{
		while (db.res->next())
		{
			Staff tmpStaff(db.res);
			user.push_back(tmpStaff);
		}
	}

	return user;
}


Staff::~Staff() { 

}


