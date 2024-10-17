#include "db_setup.h"
#include "../src/utils/config.h"
#include <iostream>
#include <fstream>
#include <dotenv.h>

void setupDatabase(DatabaseConnection& dbConn) {
    PGconn* conn = dbConn.getConnection();
    if (!conn) {
        std::cerr << "Database connection is not established!" << std::endl;
        return;
    }

    const char* dbName = "reserfisi"; 
    PGresult* res = PQexec(conn, ("SELECT 1 FROM pg_database WHERE datname = '" + std::string(dbName) + "'").c_str());

    if (PQresultStatus(res) == PGRES_TUPLES_OK && PQntuples(res) > 0) {
        std::cout << "Database '" << dbName << "' already exists!" << std::endl;
    } else {
        PQclear(res);
        std::string createDbQuery = "CREATE DATABASE " + std::string(dbName);
        res = PQexec(conn, createDbQuery.c_str());
        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            std::cerr << "Error creating database: " << PQerrorMessage(conn) << std::endl;
            PQclear(res);
            return;
        }
        std::cout << "Database created successfully!" << std::endl;}

    PQclear(res); 

    std::string dbUser = Config::getDbUser();
    std::string dbPassword = Config::getDbPassword();

    if(dbUser.empty() || dbPassword.empty()) {
        std::cerr << "Usuario o contrasenia incorrecta" << std::endl;
        return;}

    std::string conninfo = "dbname=" + std::string(dbName) + " user=" + dbUser + " password=" + dbPassword;
    
    PGconn* newConn = PQconnectdb(conninfo.c_str());
    if(PQstatus(newConn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(newConn) << std::endl;
        PQfinish(newConn);
        return;}

    std::ifstream sqlFile("../db/database.sql");
    if(!sqlFile.is_open()){
        std::cerr << "No se abrio el sql!" << std::endl;
        PQfinish(newConn);
        return;}

    std::string sql((std::istreambuf_iterator<char>(sqlFile)), std::istreambuf_iterator<char>());
    res = PQexec(newConn, sql.c_str());

    if(PQresultStatus(res) != PGRES_COMMAND_OK){
        std::cerr << "Error executing SQL script: " << PQerrorMessage(newConn) << std::endl;}
    else{
        std::cout << "Database setup completed successfully!" << std::endl;}

    PQclear(res);
    PQfinish(newConn);
}

