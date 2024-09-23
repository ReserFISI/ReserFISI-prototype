#include "students_controller.h"
#include <sstream>
#include <iostream>
#include "../../db.h"

DatabaseConnection db("dbname=reserfisi user=sebastianrojas password=1234");

void getStudents(crow::response& res) {
    res.write("Obteniendo estudiantes");
    res.end();
}

void createStudent(const crow::request& req, crow::response& res) {
    auto body = crow::json::load(req.body);
    
    if (!body) {
        res.code = 400;
        res.write("Invalid JSON");
        res.end();
        return;
    }

    int id = body["ID_Estudiante"].i(); 
    std::string nombre = body["Nombre"].s(); 
    std::string correo = body["Correo_Electronico"].s(); 
    std::string telefono = body["Telefono"].s();

    try {
        PGconn* conn = db.getConnection(); 

        if (!conn) {
            res.code = 500;
            res.write("Failed to connect to the database.");
            res.end();
            return;
        }

        std::stringstream query;
        query << "INSERT INTO Alumnos (ID_Estudiante, Nombre, Correo_Electronico, Telefono) "
              << "VALUES (" << id << ", '" << nombre << "', '" << correo << "', '"
              << telefono << "');";
        
        PGresult* result = PQexec(conn, query.str().c_str());
        
        if (PQresultStatus(result) != PGRES_COMMAND_OK) {
            res.code = 500;
            res.write("Database error: " + std::string(PQerrorMessage(conn)));
        } else {
            res.code = 200;
            res.write("Post success");
        }
        
        PQclear(result);
    } catch (const std::runtime_error& e) {
        res.code = 500;
        res.write("Database connection error: " + std::string(e.what()));
    }

    res.end();
}

void updateStudent(const crow::request& req, crow::response& res) {
    res.write("Actualizando estudiante");
    res.end();
}

void deleteStudent(const crow::request& req, crow::response& res) {
    res.write("Eliminando estudiante");
    res.end();
}
