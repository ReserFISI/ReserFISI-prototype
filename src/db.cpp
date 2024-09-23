#include "db.h"
#include <iostream>

DatabaseConnection db("dbname=reserfisi user=sebastianrojas password=1234");

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

// Destructor de DatabaseConnection
DatabaseConnection::~DatabaseConnection() {
    if (conn) {
        PQfinish(conn);
    }
}

// Obtener la conexión
PGconn* DatabaseConnection::getConnection() const {
    return conn;
}
