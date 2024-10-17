#include "db.h"
#include <iostream>
#include <dotenv.h>
#include "../../../db/db_setup.h"
#include "../../utils/config.h"

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
    if(conn){
        PQfinish(conn);
        conn = nullptr;
        std::cout << "Disconnected from the database successfully!" << std::endl;}
}

void initDatabaseConnection() {
    std::string dbConnectionString = Config::getDbConnectionString();

    DatabaseConnection initialDbConn(dbConnectionString);

    PGconn* conn = initialDbConn.getConnection();
    PGresult* res = PQexec(conn, "SELECT 1 FROM pg_database WHERE datname = 'reserfisi'");

    if (PQresultStatus(res) == PGRES_TUPLES_OK && PQntuples(res) > 0) {
        std::cout << "Database 'reserfisi' ya existe!" << std::endl;
    } else {
        setupDatabase(initialDbConn);}

    PQclear(res);
    PQfinish(conn);

    std::string conninfo = "dbname=reserfisi " + dbConnectionString;  
    std::cout << "Connecting to database: " << conninfo << std::endl;

    db = std::make_unique<DatabaseConnection>(conninfo);

    if (!db->getConnection()) {
        throw std::runtime_error("Failed to connect to database");
    }
}

void cleanupDatabaseConnection() {
    if (db) {
        db->disconnect();
        db.reset();
    }
}
