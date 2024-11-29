#include "db_setup.h"
#include "../src/utils/config.h"
#include <iostream>
#include <fstream>

void setupDatabase() {
    std::string conninfo = "dbname=postgres user=" + Config::getDbUser() + " password=" + Config::getDbPassword();
    PGconn* conn = PQconnectdb(conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to 'postgres' failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return;
    }

    PGresult* res = PQexec(conn, "SELECT 1 FROM pg_database WHERE datname = 'reserfisi'");
    if (PQresultStatus(res) != PGRES_TUPLES_OK || PQntuples(res) == 0) {
        std::cout << "Database 'reserfisi' does not exist. Creating..." << std::endl;
        PGresult* createDbRes = PQexec(conn, "CREATE DATABASE reserfisi");
        if (PQresultStatus(createDbRes) != PGRES_COMMAND_OK) {
            std::cerr << "Failed to create database: " << PQerrorMessage(conn) << std::endl;
            PQclear(createDbRes);
            PQfinish(conn);
            return;
        }
        PQclear(createDbRes);
        std::cout << "Database 'reserfisi' created successfully." << std::endl;
    }
    
    PQclear(res);
    PQfinish(conn);

    std::string conninfo_reserfisi = "dbname=reserfisi user=" + Config::getDbUser() + " password=" + Config::getDbPassword();
    PGconn* newConn = PQconnectdb(conninfo_reserfisi.c_str());

    if (PQstatus(newConn) != CONNECTION_OK) {
        std::cerr << "Connection to 'reserfisi' failed: " << PQerrorMessage(newConn) << std::endl;
        PQfinish(newConn);
        return;
    }

    std::ifstream sqlFile("../db/database.sql");
    if (!sqlFile.is_open()) {
        std::cerr << "Failed to open SQL file!" << std::endl;
        PQfinish(newConn);
        return;
    }

    std::string sql((std::istreambuf_iterator<char>(sqlFile)), std::istreambuf_iterator<char>());
    PGresult* sqlRes = PQexec(newConn, sql.c_str());

    if (PQresultStatus(sqlRes) != PGRES_COMMAND_OK && PQresultStatus(sqlRes) != PGRES_TUPLES_OK) {
        std::cerr << "Error executing SQL script: " << PQerrorMessage(newConn) << std::endl;
    } else {
        std::cout << "Database setup completed successfully!" << std::endl;
    }

    PQclear(sqlRes);
    PQfinish(newConn);
}
