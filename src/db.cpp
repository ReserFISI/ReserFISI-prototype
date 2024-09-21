#include "db.h"
#include <iostream>

DatabaseConnection::DatabaseConnection(const std::string& conninfo) {
    conn = PQconnectdb(conninfo.c_str());
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        conn = nullptr; 
    } else {
        std::cout << "Connected to the database!" << std::endl;}
}

DatabaseConnection::~DatabaseConnection() {
    if (conn) {
        PQfinish(conn);
    }
}

PGconn* DatabaseConnection::getConnection() const {
    return conn;
}
