#include "db_operations.h"
#include <sstream>
#include <iostream>

DatabaseOperations::DatabaseOperations(PGconn* connection) : conn(connection) {}

void DatabaseOperations::insertStudent(int id, const std::string& nombre, const std::string& correo, const std::string& telefono) {
    if (!conn) {
        throw std::runtime_error("Database connection is not established.");
    }

    std::stringstream query;
    query << "INSERT INTO Alumnos (ID_Estudiante, Nombre, Correo_Electronico, Telefono) "
          << "VALUES (" << id << ", '" << nombre << "', '" << correo << "', '"
          << telefono << "');";
    
    PGresult* result = PQexec(conn, query.str().c_str());

    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));
    }

    PQclear(result);
}
