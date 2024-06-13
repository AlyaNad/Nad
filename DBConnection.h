#pragma once
#ifndef DBConnection_H
#define DBConnection_H
#include <mysql/jdbc.h>
#include <string>
class DBConnection
{

public:
	DBConnection();
	~DBConnection();
	void prepareStatement(std::string query);
	sql::PreparedStatement* stmt;
	sql::ResultSet* res;
	void QueryStatement(); 
	void QueryResult(); 
	int getGeneratedId();

private:
	sql::Connection* connection;

};


#endif 