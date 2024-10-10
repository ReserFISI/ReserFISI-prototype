#include "db_operations.h"
#include <sstream>
#include <string>

DatabaseOperations::DatabaseOperations(PGconn* connection) : conn(connection) {}

void DatabaseOperations::insertStudent(int id, const std::string& nombre, const std::string& correo, const std::string& telefono) {
    if(!conn){
        throw std::runtime_error("Database connection is not established.");}

    const char* paramValues[4] = { std::to_string(id).c_str(), nombre.c_str(), correo.c_str(), telefono.c_str() };
    PGresult* result = PQexecParams(conn, 
        "INSERT INTO Alumnos (ID_Estudiante, Nombre, Correo_Electronico, Telefono) VALUES ($1, $2, $3, $4);",
        4, 
        nullptr, paramValues, nullptr, nullptr, 0);

    if(PQresultStatus(result) != PGRES_COMMAND_OK){
        PQclear(result);
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));}
    PQclear(result);
}

std::string DatabaseOperations::getAllStudents(){
    if(!conn){
        throw std::runtime_error("Database connection is not established.");}

    std::string query = "SELECT * FROM Alumnos;";
    PGresult* result = PQexec(conn, query.c_str());

    if(PQresultStatus(result) != PGRES_TUPLES_OK){
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));}

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
                      << "}";}
    json_response << "]";

    PQclear(result);

    return json_response.str();
}


std::string DatabaseOperations::getStudentById(int id){
    if (!conn) {
        throw std::runtime_error("Database connection is not established.");}

    const char* paramValues[1] = { std::to_string(id).c_str() };
    PGresult* result = PQexecParams(conn, 
        "SELECT * FROM Alumnos WHERE ID_Estudiante = $1;", 
        1, nullptr, paramValues, nullptr, nullptr, 0);

    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        PQclear(result);
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));
    }

    std::stringstream json_response;
    if (PQntuples(result) > 0) {
        json_response << "{"
                      << "\"ID_Estudiante\": " << PQgetvalue(result, 0, 0) << ","
                      << "\"Nombre\": \"" << PQgetvalue(result, 0, 1) << "\","
                      << "\"Correo_Electronico\": \"" << PQgetvalue(result, 0, 2) << "\","
                      << "\"Telefono\": \"" << PQgetvalue(result, 0, 3) << "\""
                      << "}";} 
    else{
        json_response << "{}";}

    PQclear(result);
    return json_response.str();
}

/*

    ==========================================================
                            Requests                
    ==========================================================

*/


std::string DatabaseOperations::getAllRequests() {
    if (!conn) {
        throw std::runtime_error("Database connection is not established.");
    }

    std::string query = "SELECT * FROM Reserva;";
    PGresult* result = PQexec(conn, query.c_str());
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        PQclear(result);
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));
    }

    std::stringstream json_response;
    json_response << "[";

    int rows = PQntuples(result);
    for (int i = 0; i < rows; ++i) {
        if (i > 0) json_response << ",";
        json_response << "{"
                      << "\"ID_Reserva\": " << PQgetvalue(result, i, 0) << ","
                      << "\"Fecha_Solicitud\": \"" << PQgetvalue(result, i, 1) << "\","
                      << "\"Fecha_Reserva\": \"" << PQgetvalue(result, i, 2) << "\","
                      << "\"Estado_Reserva\": \"" << PQgetvalue(result, i, 3) << "\""
                      << "}";
    }
    json_response << "]";

    PQclear(result);
    return json_response.str();}

std::string DatabaseOperations::getRequestById(int id) {
    if(!conn){
        throw std::runtime_error("Database connection is not established.");}

    std::stringstream query;
    query << "SELECT * FROM Reserva WHERE ID_Reserva = " << id << ";";

    PGresult* result = PQexec(conn, query.str().c_str());
    if(PQresultStatus(result) != PGRES_TUPLES_OK){
        PQclear(result);
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));}

    std::stringstream json_response;
    json_response << "[";

    int rows = PQntuples(result);
    if (rows > 0) {
        json_response << "{"
                      << "\"ID_Reserva\": " << PQgetvalue(result, 0, 0) << ","
                      << "\"Fecha_Solicitud\": \"" << PQgetvalue(result, 0, 1) << "\","
                      << "\"Fecha_Reserva\": \"" << PQgetvalue(result, 0, 2) << "\","
                      << "\"Estado_Reserva\": \"" << PQgetvalue(result, 0, 3) << "\""
                      << "}";}
    json_response << "]";

    PQclear(result);
    return json_response.str();}

void DatabaseOperations::insertRequest(int id, const std::string& fechaSolicitud, const std::string& fechaReserva, const std::string& estadoReserva) {
    std::stringstream query;
    query << "INSERT INTO Reserva (ID_Reserva, Fecha_Solicitud, Fecha_Reserva, Estado_Reserva) "
          << "VALUES (" << id << ", '" << fechaSolicitud << "', '" << fechaReserva << "', '"
          << estadoReserva << "');";

    PGresult* result = PQexec(conn, query.str().c_str());

    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        throw std::runtime_error(PQerrorMessage(conn));}

    PQclear(result);
}


bool DatabaseOperations::removeRequestById(int id){
    std::string query = "DELETE FROM Reserva WHERE ID_Reserva = " + std::to_string(id) + ";";

    PGresult* result = PQexec(conn, query.c_str());

    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        PQclear(result);
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));
    }

    int affectedRows = std::stoi(PQcmdTuples(result));
    PQclear(result);

    return affectedRows > 0;
}

void DatabaseOperations::updateRequestById(int id, const std::string& fechaSolicitud, const std::string& fechaReserva, const std::string& estadoReserva) {
    std::stringstream query;
    query << "UPDATE Reserva SET Fecha_Solicitud = '" << fechaSolicitud
          << "', Fecha_Reserva = '" << fechaReserva
          << "', Estado_Reserva = '" << estadoReserva
          << "' WHERE ID_Reserva = " << id << ";";

    PGresult* result = PQexec(conn, query.str().c_str());

    if(PQresultStatus(result) != PGRES_COMMAND_OK){
        PQclear(result);
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));}

    PQclear(result);
}
