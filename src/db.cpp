#include "db.h"
#include <iostream>
#include <dotenv.h>

std::unique_ptr<DatabaseConnection> db = nullptr;

DatabaseConnection::DatabaseConnection(const std::string& connectionString) : conn(nullptr) {
    connect(connectionString);
}

DatabaseConnection::~DatabaseConnection() {
    disconnect();
}

PGconn* DatabaseConnection::getConnection() const {
    return conn;
}

void DatabaseConnection::connect(const std::string& connectionString) {
    if (conn) {
        std::cerr << "Already connected to the database!" << std::endl;
        return;
    }
    
    conn = PQconnectdb(connectionString.c_str());

    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        conn = nullptr;
        throw std::runtime_error("Failed to connect to database");
    }

    std::cout << "Connected to the database successfully!" << std::endl;
}

void DatabaseConnection::disconnect() {
    if (conn) {
        PQfinish(conn);
        conn = nullptr;
        std::cout << "Disconnected from the database successfully!" << std::endl;
    }
}


void initDatabaseConnection() {
    std::string dbName = std::getenv("DB_NAME");
    std::string dbUser = std::getenv("DB_USER");
    std::string dbPassword = std::getenv("DB_PASSWORD");
    std::string conninfo = "dbname=" + dbName + " user=" + dbUser + " password=" + dbPassword;
    std::cout << "Connection info: " << conninfo << std::endl; //Para test
    db = std::make_unique<DatabaseConnection>(conninfo); // cambiado para el uso de smart pointers
}

void cleanupDatabaseConnection() {
    if (db) {
        db.reset(); // Esto limpiará la conexión de manera segura
    }
}