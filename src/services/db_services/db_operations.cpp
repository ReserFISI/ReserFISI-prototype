#include "db_operations.h"
#include <sstream>
#include <stdexcept>

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
        "SELECT * FROM alumnos WHERE \"ID_Alumno\" = $1;", 
        1, nullptr, paramValues, nullptr, nullptr, 0);

    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        PQclear(result);
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));
    }

    std::stringstream json_response;
    if (PQntuples(result) > 0) {
        json_response << "{"
                      << "\"ID_Alumno\": " << PQgetvalue(result, 0, 0) << ","
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

    std::string query = "SELECT \"ID_Reserva\", \"ID_Alumno\", \"ID_Espacio\", \"ID_Unidad\", "
                        "\"Fecha_Solicitud\", \"Fecha_Reserva\", \"Estado_Reserva\" FROM reserva;";
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
                      << "\"ID_Alumno\": " << PQgetvalue(result, i, 1) << ","
                      << "\"ID_Espacio\": " << PQgetvalue(result, i, 2) << ","
                      << "\"ID_Unidad\": " << (PQgetisnull(result, i, 3) ? "null" : PQgetvalue(result, i, 3)) << ","
                      << "\"Fecha_Solicitud\": \"" << PQgetvalue(result, i, 4) << "\","
                      << "\"Fecha_Reserva\": \"" << PQgetvalue(result, i, 5) << "\","
                      << "\"Estado_Reserva\": \"" << PQgetvalue(result, i, 6) << "\""
                      << "}";
    }
    json_response << "]";

    PQclear(result);
    return json_response.str();
}

std::string DatabaseOperations::getRequestById(int id) {
    if (!conn) {
        throw std::runtime_error("Database connection is not established.");
    }

    const char* paramValues[1] = { std::to_string(id).c_str() };
    PGresult* result = PQexecParams(conn,
        "SELECT \"ID_Reserva\", \"ID_Alumno\", \"ID_Espacio\", \"ID_Unidad\", "
        "\"Fecha_Solicitud\", \"Fecha_Reserva\", \"Estado_Reserva\" "
        "FROM reserva WHERE \"ID_Reserva\" = $1;",
        1,          
        nullptr,     
        paramValues, 
        nullptr,     
        nullptr,     
        0            
    );

    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        PQclear(result);
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));
    }

    std::stringstream json_response;

    int rows = PQntuples(result);
    if (rows > 0) {
        json_response << "{"
                      << "\"ID_Reserva\": " << PQgetvalue(result, 0, 0) << ","
                      << "\"ID_Alumno\": " << PQgetvalue(result, 0, 1) << ","
                      << "\"ID_Espacio\": " << PQgetvalue(result, 0, 2) << ","
                      << "\"ID_Unidad\": " << (PQgetisnull(result, 0, 3) ? "null" : PQgetvalue(result, 0, 3)) << ","
                      << "\"Fecha_Solicitud\": \"" << PQgetvalue(result, 0, 4) << "\","
                      << "\"Fecha_Reserva\": \"" << PQgetvalue(result, 0, 5) << "\","
                      << "\"Estado_Reserva\": \"" << PQgetvalue(result, 0, 6) << "\""
                      << "}";
    } else {
        json_response << "{}"; 
    }

    PQclear(result);
    return json_response.str();
}

void DatabaseOperations::insertRequest(int idAlumno, int idEspacio, int idUnidad,
                                       const std::string& fechaSolicitud,
                                       const std::string& fechaReserva,
                                       const std::string& estadoReserva) {
    if (!conn) {
        throw std::runtime_error("Database connection is not established.");
    }

    const char* paramValues[6] = {
        std::to_string(idAlumno).c_str(),
        std::to_string(idEspacio).c_str(),
        idUnidad != 0 ? std::to_string(idUnidad).c_str() : nullptr,
        fechaSolicitud.c_str(),
        fechaReserva.c_str(),
        estadoReserva.c_str()
    };

    const int paramFormats[6] = { 0, 0, 0, 0, 0, 0 }; 

    PGresult* result = PQexecParams(
        conn,
        "INSERT INTO \"reserva\" (\"ID_Alumno\", \"ID_Espacio\", \"ID_Unidad\", \"Fecha_Solicitud\", \"Fecha_Reserva\", \"Estado_Reserva\") "
        "VALUES ($1, $2, $3, $4, $5, $6);",
        6,               
        nullptr,        
        paramValues,    
        nullptr,        
        paramFormats,    
        0);

    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        std::string errorMsg = "Database error: " + std::string(PQerrorMessage(conn));
        PQclear(result);
        throw std::runtime_error(errorMsg);
    }

    PQclear(result);
}

bool DatabaseOperations::removeRequestById(int id) {
    const char* paramValues[1] = { std::to_string(id).c_str() };
    PGresult* result = PQexecParams(conn,
        "DELETE FROM reserva WHERE \"ID_Reserva\" = $1;",
        1,
        nullptr,
        paramValues,
        nullptr,
        nullptr,
        0
    );

    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        PQclear(result);
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));
    }

    int affectedRows = std::stoi(PQcmdTuples(result));
    PQclear(result);

    return affectedRows > 0;
}

void DatabaseOperations::updateRequestById(int id, int idEspacio, int idUnidad, const std::string& fechaSolicitud, const std::string& fechaReserva, const std::string& estadoReserva) {
    const char* paramValues[6] = {
        std::to_string(idEspacio).c_str(),
        std::to_string(idUnidad).c_str(),
        fechaSolicitud.c_str(),
        fechaReserva.c_str(),
        estadoReserva.c_str(),
        std::to_string(id).c_str()
    };
    PGresult* result = PQexecParams(conn,
        "UPDATE reserva SET \"ID_Espacio\" = $1, \"ID_Unidad\" = $2, \"Fecha_Solicitud\" = $3, \"Fecha_Reserva\" = $4, \"Estado_Reserva\" = $5 WHERE \"ID_Reserva\" = $6;",
        6,
        nullptr,
        paramValues,
        nullptr,
        nullptr,
        0
    );

    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        PQclear(result);
        throw std::runtime_error("Database error: " + std::string(PQerrorMessage(conn)));
    }

    PQclear(result);
}