#include "Cat.h"
#include <ctime>
#include "DBConnection.h" 
#include "Customer.h"
using namespace std;

Cat::Cat() {
	//initialize
	catId = 0;
	customerId = 0; 
	catName = "";
	catSpecies = "";
	catAge = "";
}
Cat::Cat(int catId, std::string catName, std::string catSpecies, std::string catAge, int customerId) {
	this->catId = catId;
	this->catName = catName;
	this->catSpecies = catSpecies;
	this->catAge = catAge;
	this->customerId = customerId;
}
int Cat::insertcat() {

	// Nanti untuk client, tukar query dia ikut attribute dalam database
	//string something = user.user_id <- tukarkan jadi string

	DBConnection db;//instantiate
	db.prepareStatement("Insert into cat (customerId, catName, catSpecies, catAge) VALUES (?,?,?,?)"); // <-- Ni nama dia query
	db.stmt->setInt(1, customerId);
	db.stmt->setString(2, catName);
	db.stmt->setString(3, catSpecies);
	db.stmt->setString(4, catAge);
	db.QueryStatement();
	generatedcatId = db.getGeneratedId();
	db.~DBConnection();
	return generatedcatId;
}

void Cat::update() {

	DBConnection db;
	db.prepareStatement("UPDATE cat SET catName=?, catSpecies=?, catAge=? WHERE catId=?");
	db.stmt->setString(1, catName);
	db.stmt->setString(2, catSpecies);
	db.stmt->setString(3, catAge);
	db.stmt->setInt(5, catId);
	db.QueryStatement();
	db.~DBConnection();

}
void Cat::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM cat WHERE stafftId=?");
	db.stmt->setInt(1, catId);
	db.QueryStatement();
	db.~DBConnection();
}



Cat::~Cat() {

}


/*Account Account::older(Account a, Account b) {
	if (b.getAge() > a.getAge()) {
		return b;
	}
	return a;
}*/