#include "db.h"
#include <iostream>
#include <dotenv.h>
#include "../../utils/config.h"
#include "../../../db/db_setup.h"

std::unique_ptr<DatabaseConnection> db = nullptr;

DatabaseConnection::DatabaseConnection(const std::string& connectionString) : conn(nullptr) {
    connect(connectionString);
}

DatabaseConnection::~DatabaseConnection() {}

PGconn* DatabaseConnection::getConnection() const {
    return conn;
}

void DatabaseConnection::connect(const std::string& connectionString) {
    conn = PQconnectdb(connectionString.c_str());

    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        conn = nullptr;
        throw std::runtime_error("Failed to connect to database");
    }

    std::cout << "Conexion establecida!" << std::endl;
}

void DatabaseConnection::disconnect() {
    if (conn) {
        PQfinish(conn);
        conn = nullptr;
        std::cout << "Disconnected from the database successfully!" << std::endl;
    }
}

void initDatabaseConnection() {
    std::string conninfo = Config::getDbConnectionString();
    
    db = std::make_unique<DatabaseConnection>(conninfo);
    PGconn* conn = db->getConnection();

    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        throw std::runtime_error("Failed to connect to database");
    }

    std::cout << "Successfully connected to the database." << std::endl;
}


void cleanupDatabaseConnection() {
    if (db) {
        db->disconnect();
        db.reset();
    }
}
