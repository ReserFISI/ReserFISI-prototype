#include "db_operations.h"
#include <sstream>
#include <string>

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


std::string DatabaseOperations::getAllStudents() {
    if (!conn) {
        throw std::runtime_error("Database connection is not established.");
    }

    std::string query = "SELECT * FROM Alumnos;";
    PGresult* result = PQexec(conn, query.c_str());

    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));
    }

    std::stringstream json_response;
    json_response << "[";

    int rows = PQntuples(result);
    for (int i = 0; i < rows; ++i) {
        if (i > 0) json_response << ",";
        json_response << "{"
                      << "\"ID_Estudiante\": " << PQgetvalue(result, i, 0) << ","
                      << "\"Nombre\": \"" << PQgetvalue(result, i, 1) << "\","
                      << "\"Correo_Electronico\": \"" << PQgetvalue(result, i, 2) << "\","
                      << "\"Telefono\": \"" << PQgetvalue(result, i, 3) << "\""
                      << "}";
    }
    json_response << "]";

    PQclear(result);

    return json_response.str();
}


std::string DatabaseOperations::getStudentById(int id) {
    std::stringstream query;
    query << "SELECT * FROM Alumnos WHERE ID_Estudiante = " << id << ";";
    PGresult* result = PQexec(conn, query.str().c_str());

    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        PQclear(result);
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));
    }

    std::stringstream json_response;
    json_response << "[";

    int rows = PQntuples(result);
    if (rows > 0) {
        json_response << "{"
                      << "\"ID_Estudiante\": " << PQgetvalue(result, 0, 0) << ","
                      << "\"Nombre\": \"" << PQgetvalue(result, 0, 1) << "\","
                      << "\"Correo_Electronico\": \"" << PQgetvalue(result, 0, 2) << "\","
                      << "\"Telefono\": \"" << PQgetvalue(result, 0, 3) << "\""
                      << "}";
    }
    json_response << "]";

    PQclear(result);
    return json_response.str();
}
