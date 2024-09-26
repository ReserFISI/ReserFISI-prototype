#include "db.h"
#include <iostream>
#include <dotenv.h>

DatabaseConnection* db = nullptr; 

DatabaseConnection::DatabaseConnection(const std::string& conninfo) {
    conn = PQconnectdb(conninfo.c_str());
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        conn = nullptr; 
    } else {
        std::cout << "Connected to the database!" << std::endl;
    }
}

DatabaseConnection::~DatabaseConnection() {
    if (conn) {
        PQfinish(conn);
    }
}

PGconn* DatabaseConnection::getConnection() const {
    return conn;
}

void initDatabaseConnection() {
    std::string dbName = std::getenv("DB_NAME");
    std::string dbUser = std::getenv("DB_USER");
    std::string dbPassword = std::getenv("DB_PASSWORD");
    std::string conninfo = "dbname=" + dbName + " user=" + dbUser + " password=" + dbPassword;
    std::cout << "Connection info: " << conninfo << std::endl; //Para test
    db = new DatabaseConnection(conninfo); //La fijaza era hacerlo un objeto
}
