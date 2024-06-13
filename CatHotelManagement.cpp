#include <iostream>  
#include <conio.h>
#include <iomanip>
#include <sstream>
#include <fstream>
// advanced
// include our custom class
#include "Admin.h"
#include "Staff.h"
#include "Customer.h"
#include "Account.h" 
#include "Menu.h"
#include "Cat.h"
#include "Inventory.h"
using namespace std;

void inv(Admin user);
void homepage(Staff user); 
void home(Customer user);
void hoteldetails();
void registerStaff();
void registerCust();
void loginAdmin();
void loginStaff();
void loginCust();
void inventory(Admin user);
void addProduct(Admin user);
char ch;
void displayRoomInfo(int roomType);
void book(Customer user);
int listStaff();
Staff removeStaff(Staff user); 
Cat booking(Customer customer, Cat cat);
void logout();

Account profile(Account user);

int main() {

	Menu mainmenu;
	mainmenu.header = "-  Welcome to Cat Hotel Management System  -"; 
	mainmenu.addOption("Login Admin");
	mainmenu.addOption("Login Staff");
	mainmenu.addOption("Login Customer");
	mainmenu.addOption("Register Staff");
	mainmenu.addOption("Register Customer");
	mainmenu.addOption("Exit");

	while (1) {
		switch (mainmenu.prompt())
		{
		case 1:
			loginAdmin();
			break;
		case 2:
			loginStaff();
			break;
		case 3:
			loginCust();
			break;
		case 4:
			registerStaff(); 
			break;
		case 5:
			registerCust(); 
			break;
		case 6:
			return 0;
		default:
			break;
		}
	}
}
void loginAdmin() {
	Menu loginMenu;
	loginMenu.header = "LOGIN ADMIN";
	loginMenu.addOption("username");
	loginMenu.addOption("password");
	loginMenu.addOption("Login");
	loginMenu.addOption("Back");

	Admin user;

	while (1) {
		switch (loginMenu.prompt())
		{
		case 1:
			cout << "Insert Username:";
			cin >> user.username;
			loginMenu.setValue(0, user.username);
			break;
		case 2:
			cout << "Insert Password: ";
			user.password = Admin::getMaskedInput(""); 
			loginMenu.setValue(1, std::string(user.password.length(), '*'));
			break;
		case 3:
			if (user.login()) {
				inv(user);   
			}
			else {
				cout << "Invalid Login";
				_getch();
			}
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}
void registerStaff() {
	Staff newstaff; 

	Menu rgMenu;
	rgMenu.header = "- Staff Registration -";
	rgMenu.addOption("Email");
	rgMenu.addOption("Phone Number");
	rgMenu.addOption("Create Username");
	rgMenu.addOption("Create Password");
	rgMenu.addOption("Register");
	rgMenu.addOption("Back");


	string tmpinput;
	bool valid = true;
	while (1) {

		switch (rgMenu.prompt()) {
		case 1:
			cout << "Insert Email:";
			cin >> newstaff.email;
			rgMenu.setValue(0, newstaff.email);
			break;
		case 2:
			cout << "Insert Phone Number:";
			cin >> newstaff.phoneNo;
			rgMenu.setValue(1, newstaff.phoneNo);
			break;
		case 3:
			cout << "Insert Username:";
			cin >> newstaff.username;
			rgMenu.setValue(2, newstaff.username);
			break; 
		case 4:
			cout << "Insert password:";
			cin >> tmpinput;
			if (tmpinput.length() < 7) {
				cout << "Password must be at least 7 character long";
				_getch();
			}
			else {
				newstaff.password = tmpinput;
				rgMenu.setValue(3, newstaff.password);
			}
			break;
		case 5:
			newstaff.insert();
			cout << "Registered successfully";
			_getch();
			break;
		case 6:
			return;
		default:
			break;
		}
	}

}
void registerCust() {
	Customer newcust; 

	Menu rgMenu;
	rgMenu.header = "- Customer Registration -";
	rgMenu.addOption("Email");
	rgMenu.addOption("Phone Number");
	rgMenu.addOption("Create Username");
	rgMenu.addOption("Create Password");
	rgMenu.addOption("Register");
	rgMenu.addOption("Back");


	string tmpinput;
	bool valid = true;
	while (1) {

		switch (rgMenu.prompt()) {
		case 1:
			cout << "Insert Email:";
			cin >> newcust.email;
			rgMenu.setValue(0, newcust.email);
			break;
		case 2:
			cout << "Insert Phone Number:";
			cin >> newcust.phoneNo;
			rgMenu.setValue(1, newcust.phoneNo);
			break;
		case 3:
			cout << "Insert Username:";
			cin >> newcust.username;
			rgMenu.setValue(2, newcust.username);
			break;
		case 4:
			cout << "Insert password:";
			cin >> tmpinput;
			if (tmpinput.length() < 7) {
				cout << "Password must be at least 7 character long";
				_getch();
			}
			else {
				newcust.password = tmpinput;
				rgMenu.setValue(3, newcust.password);
			}
			break;
		case 5:
			newcust.insert();
			cout << "Registered successfully";
			_getch();
			break;
		case 6:
			return;
		default:
			break;
		}
	}

}
void loginStaff() {
	Staff newstaff; 
	Menu loginMenu;
	loginMenu.header = "LOGIN STAFF";
	loginMenu.addOption("username");
	loginMenu.addOption("password");
	loginMenu.addOption("Login");
	loginMenu.addOption("Back");

	Staff user;
	string tmpinput; 
	while (1) {
		switch (loginMenu.prompt())
		{
		case 1:
			cout << "Insert Username:";
			cin >> user.username;
			loginMenu.setValue(0, user.username);
			break;
		case 2:
			cout << "Insert Password:";
			user.password = Staff::getMaskedInput(""); 
			loginMenu.setValue(1, std::string(user.password.length(), '*')); 
			break;
		case 3:
			if (user.login()) {
				homepage(user); 
			}
			else {
				cout << "Invalid Login";
				_getch();
			}
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}
void loginCust() {
	Menu loginMenu;
	loginMenu.header = "LOGIN CUSTOMER";
	loginMenu.addOption("username");
	loginMenu.addOption("password");
	loginMenu.addOption("Login");
	loginMenu.addOption("Back");

	Customer user; 

	while (1) {
		switch (loginMenu.prompt())
		{
		case 1:
			cout << "Insert Username:";
			cin >> user.username;
			loginMenu.setValue(0, user.username);
			break;
		case 2:
			cout << "Insert Password:";
			user.password = Customer::getMaskedInput("");
			loginMenu.setValue(1, std::string(user.password.length(), '*'));
			break;
		case 3:
			if (user.login()) {
				home(user);
			}
			else {
				cout << "Invalid Login";
				_getch();
			}
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}
void inv(Admin user) { 
	Menu adminpage;
	adminpage.addOption("Inventory"); 
	adminpage.addOption("List of staff"); 
	adminpage.addOption("Add product"); 
	adminpage.addOption("Logout"); 
	while (1) {
		adminpage.header = "Welcome, Admin";
		switch (adminpage.prompt())
		{
		case 1:
			inventory(user);
			break;
		case 2:
			listStaff();
			break;
		case 3:
			addProduct(user);
			break;
		case 4:
			logout();  
			break;
		default:
			break;
		}
	}
}
void inventory(Admin user){
	//view inv from database
	//Admin user;
	vector<Inventory> inventory;
	Inventory searchI;
	string displayI = ""; 

	int InventoryID = 0;
	string productname = "", quantity = " ", catogory = " ";
	bool asc = true;

	Menu searchIM;
	searchIM.header = "\n\n\t\tInventory\n";
	searchIM.addOption(" 1 > View By Product Name");
	searchIM.addOption(" 2 > View By Category");
	searchIM.addOption(" 3 > View All Product: ");
	searchIM.addOption(" 4 > Update Product's Quantity: ");
	searchIM.addOption(" 5 > Delete Product");
	searchIM.addOption(" 6 > Back");

	while (1)
	{
		if (asc)
		{
			searchIM.setValue(2, "Ascending");
		}
		else
		{
			searchIM.setValue(2, "Descending");
		}
		if (displayI == "")
		{
			displayI = "\n\tResult:\n\n";
			stringstream tmpS;

			tmpS << setw(10) << "\tInventory ID  | " << setw(36) << "\tProduct Name    | " << setw(16) << "\tQuantity  | " << setw(26) << "\tCategory      | " << "\n "
				<< endl;

			for (int i = 0; i < inventory.size(); i++)
			{
				tmpS << setw(10) << inventory[i].inventoryId << "\t  |" << setw(35) << inventory[i].productname << "\t  |" << setw(16) << inventory[i].quantity << "\t|" << setw(25) << inventory[i].catogory << "\t |" << endl;
			}
			displayI += tmpS.str();

			ofstream outputFile("inventory.txt");
			if (outputFile.is_open()) {
				outputFile << displayI;
				outputFile.close();
			}
			else {
				cerr << "Unable to open file for writing." << endl;
			}
		}
		searchIM.footer = displayI;

		switch (searchIM.prompt())
		{
		case 1:
			cout << " Insert Product Name: ";
			cin.ignore(); // Ignore newline character in the buffer
			getline(cin, productname);
			searchIM.setValue(0, productname);
			inventory = Inventory::searchInventory(productname, quantity, catogory, asc);
			displayI = "";
			break;
		case 2:
			cout << " Insert Category: ";
			cin.ignore(); // Ignore newline character in the buffer
			getline(cin, catogory);
			searchIM.setValue(1, catogory);
			inventory = Inventory::searchInventory(productname, quantity, catogory, asc);
			displayI = "";
			break;
		case 3:
			asc = !asc;
			inventory = Inventory::searchInventory("", "", "", asc); 
			displayI = "";
			break;
		case 4:
			cout << " Insert Inventory ID: ";
			cin.ignore(); // Ignore newline character in the buffer 
			cin >> searchI.inventoryId;
			searchIM.setValue(3, to_string(searchI.inventoryId));
			displayI = "";
			cout << " Insert new Quantity: ";
			cin.ignore(); // Ignore newline character in the buffer 
			cin >> searchI.quantity;
			searchIM.setValue(3, searchI.quantity);
			searchI.update();
			break;
		case 5:
			cout << " Insert Inventory ID to delete account: ";
			cin >> InventoryID;
			searchIM.setValue(4, to_string(InventoryID));
			for (Inventory& inventory : inventory) {
				if (inventory.inventoryId == InventoryID) {
					//removeInventory(inventory);
				}
			}
			break;
			break;
		case 6:
			inv(user);
			break;
		}
	}
}
//void removeInventory(inventory) {

//}
void addProduct(Admin user) {
	Inventory inv;

	Menu invMenu;
	invMenu.header = "- Insert new product -";
	invMenu.addOption("Product Name");
	invMenu.addOption("Quantity");
	invMenu.addOption("Category");
	invMenu.addOption("Save");
	invMenu.addOption("Back");


	string tmpinput;
	while (1) {

		switch (invMenu.prompt()) {
		case 1:
			cout << "Insert product name:";
			cin.ignore(); // Ignore newline character in the buffer
			getline(cin, inv.productname); 
			invMenu.setValue(0, inv.productname);
			break;
		case 2:
			cout << "Insert Quantity:";
			cin >> inv.quantity;
			invMenu.setValue(1, inv.quantity);
			break;
		case 3:
			cout << "Insert Product's Category:";
			cin >> inv.catogory;
			invMenu.setValue(2, inv.catogory);
			break;
		case 4:
			inv.insert();
			cout << "Registered successfully";
			_getch();
			break;
		case 5:
			return;
		default:
			break;
		}
	}
}
void product(Admin user) {
	//insert product
}
void homepage(Staff user) {
	Menu staffpage;
	staffpage.addOption("Hotel Room Details"); 
	staffpage.addOption("Update Hotel Room"); 
	staffpage.addOption("Payment Entry"); 
	staffpage.addOption("Logout"); 
	while (1) {
		staffpage.header = "Welcome "; 
		switch (staffpage.prompt()) 
		{
		case 1:
			hoteldetails();
			break;
		case 2:
			//updatehotel();
			break;
		case 3:
			logout();
			break;
		case 4:
			logout(); 
			break;
		default:
			break;
		}
	}
}
void hoteldetails() {
	Menu mainmenu;
	mainmenu.header = "-  Hotel Details  -";
	mainmenu.addOption("Hotel room type");
	mainmenu.addOption("Back");

	while (1) {
		switch (mainmenu.prompt())
		{
		case 1:
			std::cout << "\n\n1. Standard Room\n";
			std::cout << "3 Feet(L) X 2.5 Feet(W)\n";
			std::cout << "RM30/Night\n";
			std::cout << "Max 2 cat\n\n";

			std::cout << "2. Deluxe Room\n";
			std::cout << "RM40/Night\n";
			std::cout << "2-6 cat\n";
			std::cout << "6 Feet(L) X 2.5 Feet(W)\n\n";

			std::cout << "-> Food and Litter provided\n";
			std::cout << "-> Additional RM15 for second cat\n";
			_getch();
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}
void updatehotel() {

}
void home(Customer user) { 
	Menu homeMenu; 
	Cat cat; 
	homeMenu.addOption("Add new Cat"); 
	homeMenu.addOption("booking"); 
	homeMenu.addOption("Hotel room details");
	homeMenu.addOption("Payment"); 
	homeMenu.addOption("Logout"); 
	while (1) {
		homeMenu.header = "Welcome " + user.username; 
		switch (homeMenu.prompt()) 
		{
		case 1:
			booking(user, cat);    
			break;
		case 2:
			//reservation(user, cat);
			break;
		case 3:
			hoteldetails();
			break;
		case 4:
			//payment();
			break;
		case 5:
			logout(); 
			break;
		default:
			break;
		}
	}
}
Cat booking(Customer user, Cat cat) {
	Cat newcat = cat;
	newcat.customerId = user.customerId;
	Menu homeMenu;
	homeMenu.header = "Insert Details";
	homeMenu.addOption("Cat name");
	homeMenu.addOption("Cat species/colour");
	homeMenu.addOption("Cat age (year)");
	homeMenu.addOption("Save details");
	homeMenu.addOption("back");
	while (1) {
		switch (homeMenu.prompt())
		{
		case 1:
			cout << "Write your cat's name:";
			getline(cin, newcat.catName);
			homeMenu.setValue(0, newcat.catName);
			break;
		case 2:
			cout << "Cat's species or color:";
			getline(cin, newcat.catSpecies);
			homeMenu.setValue(1, newcat.catSpecies);
			break;
		case 3:
			cout << "Cat's Age:";
			cin >> newcat.catAge;
			homeMenu.setValue(2, newcat.catAge);
			break;
		case 4:
			newcat.insertcat();
			cout << "saved";
			_getch();
			break;
		case 5:
			return cat;
			break;
		default:
			break;
		}
	}
}

/*void book(Customer user) {
	Payment room; //initialize a transaction to hold product values
	room.user = user.customerId; // put currently logge in user id into the transaction

	Menu shopMenu;
	shopMenu.footer = "Enter Booking details";
	shopMenu.addOption("Room");
	shopMenu.addOption("Cat Name");
	shopMenu.addOption("Duration");
	shopMenu.addOption("Add a cat");
	shopMenu.addOption("Back");
	while (1) {
		shopMenu.header = "SHOP\nselected details:" + to_string(room.count()) + "  \nTotal Price: " + to_string(room.total());
		switch (shopMenu.prompt())
		{
		case 1:
			room = Hotelroom(user, 1, room);
			break;
		case 2:
			room = Hotelroom(user, 2, room);
			break;
		case 3:
			room = products(user, 3, room); 
			break;
		case 4:
			room = roomMenu(user, room);
			break;
		case 5:
			return;
			break;
		}
	}
}
*/

/*void reservation(Customer user, Cat cat) {
	char confirmCat; 
	Cat newroom = cat; 
	//Cat = cat;
	//newcat.customerId = user.customerId;
	Menu homeMenu; 
	homeMenu.header = "\n\nInsert Details To Book Hotel"; 
	homeMenu.addOption("Cat name");
	homeMenu.addOption("Hotel Room");
	homeMenu.addOption("Duration");
	homeMenu.addOption("Save booking");
	homeMenu.addOption("back");
	while (1) {
		switch (homeMenu.prompt())
		{
		case 1:
			cout << "Write your cat's name:";
			confirmCat = _getch();  
			if (confirmCat == catName) {
				homeMenu.setValue(0, catName); 
			}
			else {
				cout << "\n\n\t Please register your cat first. \n\n\t Press any key to continue. ";
				_getch();
				return;
			}
			homeMenu.setValue(0, newcat.catName);
			break;
		case 2:
			cout << "Choose a hotel room:"; 
			getline(cin, newroom.room);
			homeMenu.setValue(1, newroom.catRoom); 
			break;
		case 3:
			cout << "Enter Duration (Night):";
			cin >> newroom.duration;
			homeMenu.setValue(2, newroom.duration);
			break;
		case 4:
			newroom.insertcat();
			cout << "reservation successful";
			_getch();
			break;
		case 5:
			return;
			break;
		default:
			break;
		}
	}

// list of staff
int listStaff()
{
	Admin user; 
	//Appointment book;
	//Payment pay;
	vector<Staff> staff;
	Staff searchS;
	string displayS = "";

	int StaffID = 0;
	string username = "", email = " ", phoneNo = " ";
	bool asc = true;

	ofstream outputFile("view.txt");

	Menu searchSM;
	searchSM.header = "\n\n\t\tList of Staff \n";
	searchSM.addOption(" 1 > View By Name");
	searchSM.addOption(" 2 > View By Email");
	searchSM.addOption(" 3 > View All Staff: ");
	searchSM.addOption(" 4 > Update Staff's Phone Number: ");
	searchSM.addOption(" 5 > Delete Staff Account");
	searchSM.addOption(" 6 > Back");

	while (1)
	{
		if (asc)
		{
			searchSM.setValue(2, "Ascending");
		}
		else
		{
			searchSM.setValue(2, "Descending");
		}
		if (displayS == "")
		{
			displayS = "\n\tResult:\n\n";
			stringstream tmpS;

			tmpS << setw(10) << "\tStaff ID  | " << setw(36) << "\tStaff Username    | " << setw(16) << "\tStaff Email  | " << setw(26) << "\tStaff Phone Number      | " << "\n "
				<< endl;

			for (int i = 0; i < staff.size(); i++)
			{
				tmpS << setw(10) << staff[i].staffId << "\t  |" << setw(35) << staff[i].username << "\t  |" << setw(16) << staff[i].email << "\t|" << setw(25) << staff[i].phoneNo << "\t |" << endl;
				//outputFile << staff[i].staffId << " " << staff[i].username << " " << staff[i].email << " " << staff[i].phoneNo;
			
			}
			displayS += tmpS.str();

			ofstream outputFile("view.txt");
			if (outputFile.is_open()) {
				outputFile << displayS;
				outputFile.close();
			}
			else {
				cerr << "Unable to open file for writing." << endl;
			}
		}
		searchSM.footer = displayS;

		switch (searchSM.prompt())
		{
		case 1:
			cout << " Insert Staff Userame: ";
			//cin.ignore(); // Ignore newline character in the buffer
			getline(cin, username);
			searchSM.setValue(0, username);
			staff = Staff::searchStaff(username, email, asc);
			displayS = "";
			break;
		case 2:
			cout << " Insert Email: ";
			//cin.ignore(); // Ignore newline character in the buffer
			getline(cin, email);
			searchSM.setValue(1, email);
			staff = Staff::searchStaff(username, email, asc);
			displayS = "";
			break;
		case 3:
			asc = !asc;
			staff = Staff::searchStaff("", "", asc); // View all staff, no criteria
			displayS = "";
			break;
		case 4:
			cout << " Insert Staff ID: ";
			cin.ignore(); // Ignore newline character in the buffer 
			cin >> searchS.staffId; 
			searchSM.setValue(3, to_string(searchS.staffId)); 
			displayS = ""; 
			cout << " Insert new Phone Number: ";
			cin.ignore(); // Ignore newline character in the buffer 
			cin >> searchS.phoneNo;
			searchSM.setValue(3, searchS.phoneNo);
			searchS.update(); 
			break;
		case 5:
			cout << " Insert Staff ID to delete account: ";
			cin >> StaffID;
			searchSM.setValue(5, to_string(StaffID));
			for (Staff& staff : staff) {
				if (staff.staffId == StaffID) {
					removeStaff(staff);
				}
			}
			break;
		case 6:
			inv(user);
			break;
		}
	}
}
Staff removeStaff(Staff user)
{
	//Staff temp = user;
	Menu deleteCM;
	char confirm;

	cout << "\n\tAre you sure want to delete your account? (y/n)\n";
	confirm = _getch();
	if (confirm == 'Y' || confirm == 'y')
	{
		//user = temp; 
		user.remove();
		cout << "\n\t Staff account deleted.";
		_getch();
		listStaff();
	}
	else
	{
		cout << "\n\n\t Account saved. \n\n\t Press any key to continue. ";
		_getch();
		listStaff();
	}
	return user;
}
void logout() {
	char confirm; 
	
	std::cout << "Are you sure you want to logout? (y/n)" << std::endl; 
	confirm = _getch();
	if (confirm == 'Y' || confirm == 'y'){
		std::cout << "You have been logged out." << std::endl;
		_getch();
		main();
	}
	else {
		cout << "\n\n\t Failed to logout. \n\n\t Press any key to continue. ";
		_getch();
		return;
	}
}
/*void reservation() {
	Menu rsvMenu;
	rsvMenu.header = "- Insert new booking -";
	rsvMenu.addOption("Choose hotel room");
	rsvMenu.addOption("How long");
	rsvMenu.addOption("How many cat?");
	rsvMenu.addOption("Save");
	rsvMenu.addOption("Back");


	string tmpinput;
	while (1) {

		switch (rsvMenu.prompt()) {
		case 1:
			cout << "Insert room type (Standard/Deluxe):";
			cin.ignore(); // Ignore newline character in the buffer
			cin >> rsv.roomtype;
			rsvMenu.setValue(0, rsv.roomtype);
			break;
		case 2:
			cout << "Insert how many night your cat will stay:";
			cin >> rsv.duration;
			rsvMenu.setValue(1, rsv.duration);
			break;
		case 3:
			cout << "Insert cat's quantity:";
			cin >> rsv.cat;
			rsvMenu.setValue(2, rsv.cat);
			break;
		case 4:
			//inv.insert();
			cout << "Registered successfully";
			_getch();
			break;
		case 5:
			return;
		default:
			break;
		}
	}
}
}*/
/*void hotel(Customer user) {
	//Transaction cart; //initialize a transaction to hold product values
	//cart.user = user.customerId; // put currently logge in user id into the transaction

	Menu rsvMenu;
	rsvMenu.footer = "Select Hotel Room Category";
	rsvMenu.addOption("Standard");
	rsvMenu.addOption("Deluxe");
	rsvMenu.addOption("View Cart");
	rsvMenu.addOption("Back");
	while (1) {
		rsvMenu.header = "HOTEL ROOM\nItems in reservation:" + to_string(reservation.count()) + "  \nTotal Price: " + to_string(reservation.total());
		switch (rsvMenu.prompt())
		{
		case 1:
			reservation = rooms(user, 1, reservation);
			break;
		case 2:
			reservation = rooms(user, 2, reservation);
			break;
		case 3:
			reservation = roomMenu(user, reservation);
			break;
		case 4:
			return;
			break;
		}
	}
}

/Transaction products(Account user, int category, Transaction cart) {
	vector<Product> products;
	string displayString = "";

	string keyWord = "", sortColumn = "price";
	bool ascending = true;
	double minPrice = 0, maxPrice = 999999;


	Menu productMenu;
	productMenu.header = "Search Option";
	productMenu.addOption("Key Word");
	productMenu.addOption("Minimum Price");
	productMenu.addOption("Maximum Price");
	productMenu.addOption("Sort By");
	productMenu.addOption("Ordering");
	productMenu.addOption("Search");
	productMenu.addOption("Select");
	productMenu.addOption("Back");

	Menu sortingSubMenu;
	sortingSubMenu.header = "Select Sort category";
	sortingSubMenu.addOption("Price");
	sortingSubMenu.addOption("Name");

	while (1)
	{
		productMenu.setValue(3, sortColumn);
		if (ascending) {
			productMenu.setValue(4, "Ascending");
		}
		else {
			productMenu.setValue(4, "Descending");
		}

		if (displayString == "") {
			displayString = "\nSearch Result:\n";
			stringstream tmpString;
			tmpString << fixed << setprecision(2) << setw(5) << "ID" << "|" << setw(20) << "Name"
				<< "|" << setw(10) << "Price" << "|" << setw(20) << "Description" << "|" << endl;

			for (int i = 0; i < products.size(); i++) {
				tmpString << setw(5) << products[i].productId << "|" << setw(20) << products[i].name
					<< "|" << setw(10) << products[i].price << "|" << setw(20) << products[i].description << "|" << endl;
			}
			displayString += tmpString.str();
		}
		productMenu.footer = displayString;

		switch (productMenu.prompt()) {

			/// the case will modify the variable used as parameter to call the search method
		case 1:
			cout << "Insert Key Word: ";
			getline(cin, keyWord);
			productMenu.setValue(0, keyWord);
			break;
		case 2:
			cout << "Insert Min Price: ";
			cin >> minPrice;
			productMenu.setValue(1, to_string(minPrice));
			break;
		case 3:
			cout << "Insert Max Price: ";
			cin >> maxPrice;
			productMenu.setValue(2, to_string(maxPrice));
			break;
		case 4:
			switch (sortingSubMenu.prompt())
			{
			case 1:
				sortColumn = "price";
				break;
			case 2:
				sortColumn = "name";
				break;
			}
			break;
		case 5:
			ascending = !ascending;
			break;
		case 6:

			products = Product::findProduct(category, keyWord, minPrice, maxPrice, sortColumn, ascending);
			displayString = "";
			break;
		case 7:
			cout << "Insert Product Id to Select:";
			int productId;
			cin >> productId;
			cart = productDetail(user, productId, cart);
			break;
		case 8:
			return cart;
			break;

		}
	};

}

/Transaction productDetail(Account user, int productId, Transaction cart) {
	Product product = Product::findProduct(productId);
	if (product.productId == 0) {
		// default id, which mean product doesn't exist since no 0 id in database
		cout << "Product not found";
		_getch();
		return cart;
	}

	Menu productMenu;
	productMenu.header = "Action:";
	productMenu.addOption("Add to cart");
	productMenu.addOption("Back");
	productMenu.footer = "Product Details:\n"
		"\nName\t: " + product.name
		+ "\nDescription\t: " + product.description
		+ "\nPrice\t: " + to_string(product.price);
	while (1) {
		switch (productMenu.prompt())
		{
		case 1:
			cout << "Insert Quantity :";
			int qty;
			cin >> qty;
			if (qty > 0) {
				cart.addProduct(product, qty);
			}
			cout << endl << "Product Added into cart";
			_getch();
			break;
		case 2:
			return cart;
			break;
		}
	}

}

/Transaction cartMenu(Account user, Transaction cart) {
	Menu cartM;
	cartM.header = "Actions";
	cartM.addOption("Checkout");
	cartM.addOption("Empty Cart");
	cartM.addOption("Back");
	stringstream ss;
	ss << fixed << setprecision(2) << setw(20) << "Product|" << setw(20) << "Price|" << setw(20)
		<< "Quantity|" << setw(20) << "Subtotal|" << endl;
	for (int i = 0; i < cart.items.size(); i++) {
		ss << setw(20) << cart.items[i].first.name << setw(20) << cart.items[i].first.price << setw(20)
			<< cart.items[i].second << setw(20) << (cart.items[i].first.price * cart.items[i].second) << endl;
	}
	ss << setw(20) << "SUM" << setw(20) << "" << setw(20) << cart.count() << setw(20) << cart.total();
	cartM.footer = "Cart Items\n" + ss.str();
	char confirm;
	while (1)
	{
		switch (cartM.prompt())
		{
		case 1:
			cout << "Check out? (y/n)";
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y') {
				cart.insert();
				cout << "Transaction saved";
				_getch();
				shop(user); // go back to shop with empty cart
			}
			break;
		case 2:
			cout << "Clear your cart? (y/n)";
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y') {
				shop(user); // go back to shop with empty cart
			}
			break;
		case 3:
			return cart;
		}

	}
}*/
