#include "Hotelroom.h"
#include <vector> 
using namespace std;

Hotelroom::Hotelroom() {
	roomId = 0;
	roomName = "";
	price = 0;
}

Hotelroom::Hotelroom(sql::ResultSet* data) {
	roomId = data->getInt("roomId");
	roomName = data->getString("roomName");
} 

 vector<Hotelroom> Hotelroom::findHotelroom(string roomName, string sortColumn, bool ascending) {

	string query = "SELECT * FROM `hotelroom` WHERE "
		" (roomName LIKE ? OR capacity LIKE ?) AND capacity = ? "
		" ORDER BY " + sortColumn;
	if (ascending) {
		query += " ASC";
	}
	else {
		query += " DESC";
	}
	// 
	DBConnection db;
	db.prepareStatement(query);
	db.stmt->setString(1, "%" + roomName + "%");
	db.stmt->setString(2, "%" + roomName + "%");

	vector<Hotelroom> rooms;

	db.QueryResult();

	if (db.res->rowsCount() > 0) {

		while (db.res->next()) {
			Hotelroom tmpHotelroom(db.res);
			rooms.push_back(tmpHotelroom);

		}
	}

	db.~DBConnection();
	return rooms;
}


Hotelroom Hotelroom::findHotelroom(int roomId) {
	DBConnection db;
	db.prepareStatement("SELECT * FROM hotelroom WHERE roomId=?");
	db.stmt->setInt(1, roomId);
	db.QueryResult();

	Hotelroom result;
	if (db.res->rowsCount() == 1) {
		while (db.res->next()) {
			Hotelroom found(db.res);
			result = found;
		}
	}
	db.~DBConnection();
	return result;
}

Hotelroom::~Hotelroom() {

}