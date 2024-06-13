#include "Inventory.h"
#include <ctime>
#include "DBConnection.h" 
#include <vector>
#include <conio.h> 
using namespace std;

Inventory::Inventory() {
	//initialize
	inventoryId = 0;
	productname = "";
	quantity = "";
	catogory = "";

}
Inventory::Inventory(int inventoryId, std::string productname, std::string quantity, std::string catogory) {
	this->inventoryId = inventoryId;
	this->productname = productname;
	this->quantity = quantity;
	this->catogory = catogory;
}
Inventory::Inventory(sql::ResultSet* data) 
{
	DBConnection db;
	db.prepareStatement("SELECT * FROM inventory");
	inventoryId = data->getInt("inventoryId");
	productname = data->getString("productname");
	quantity = data->getString("quantity");
	catogory = data->getString("catogory");
}
void Inventory::insert() {

	DBConnection db;//instantiate
	db.prepareStatement("Insert into inventory (productname,quantity,catogory) VALUES (?,?,?)");
	db.stmt->setString(1, productname);
	db.stmt->setString(2, quantity);
	db.stmt->setString(3, catogory);
	db.QueryStatement();
	db.~DBConnection();
}
void Inventory::update() {

	DBConnection db;
	db.prepareStatement("UPDATE inventory SET productname=?, quantity=?, catogory=? WHERE inventoryId=?");
	db.stmt->setString(1, productname);
	db.stmt->setString(2, quantity);
	db.stmt->setString(3, catogory);
	db.stmt->setInt(4, inventoryId);
	db.QueryStatement();
	db.~DBConnection();

}
void Inventory::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM inventory WHERE inventoryId=?");
	db.stmt->setInt(1, inventoryId);
	db.QueryStatement();
	db.~DBConnection();
}

std::vector<Inventory> Inventory::searchInventory(string productname, string quantity, string catogory, bool ascending)
{
	string query = "SELECT * FROM inventory WHERE"
		" productname LIKE ? AND quantity LIKE ? AND catogory LIKE?"
		" ORDER BY inventoryId ";

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
	db.stmt->setString(1, "%" + productname + "%");
	db.stmt->setString(2, "%" + quantity + "%");
	db.stmt->setString(3, "%" + catogory + "%");

	std::vector<Inventory> inventory;

	db.QueryResult();

	if (db.res->rowsCount() > 0)
	{
		while (db.res->next())
		{
			Inventory tmpStaff(db.res);
			inventory.push_back(tmpStaff);
		}
	}

	return inventory;
}

Inventory::~Inventory() {

}
