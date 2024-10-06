/*
#include "db_setup.h"
#include <iostream>
#include <fstream>
#include <string>
#include <libpq-fe.h>

void setupDatabase(DatabaseConnection& dbConn) {
    PGconn* conn = dbConn.getConnection();
    if (!conn) {
        std::cerr << "Database connection is not established!" << std::endl;
        return;
    }

    const char* dbName = "Papulince";
    PGresult* res = PQexec(conn, "SELECT 1 FROM pg_database WHERE datname = 'Papulince'");
    
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        std::cout << "Database already exists!" << std::endl;
    } else {
        // Crear la base de datos
        PQclear(res);
        std::string createDbQuery = "CREATE DATABASE " + std::string(dbName);
        res = PQexec(conn, createDbQuery.c_str());
        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            std::cerr << "Error creating database: " << PQerrorMessage(conn) << std::endl;
            PQclear(res);
            return;
        } else {
            std::cout << "Database created successfully!" << std::endl;
        }
    }
    
    PQclear(res);

    PQfinish(conn);
    conn = PQconnectdb("dbname=Papulince user=sebastianrojas password=1234");
    
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        return;
    }

    std::ifstream sqlFile("../db/database.sql");
    if (!sqlFile.is_open()) {
        std::cerr << "Could not open SQL file!" << std::endl;
        return;
    }

    std::string sql((std::istreambuf_iterator<char>(sqlFile)), std::istreambuf_iterator<char>());
    res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Error executing SQL script: " << PQerrorMessage(conn) << std::endl;
    } else {
        std::cout << "Database setup completed successfully!" << std::endl;
    }

    PQclear(res);
    PQfinish(conn);
}
*/