#include "students_controller.h"
#include <sstream>
#include "../../db.h"
#include "../../db_operations.h"


DatabaseConnection db("dbname=reserfisi user=sebastianrojas password=1234");

void getStudents(crow::response& res) {
    try {
        PGconn* conn = db.getConnection();
        if (!conn) {
            throw std::runtime_error("Failed to connect to the database.");
        }

        DatabaseOperations dbOps(conn);
        std::string studentsJson = dbOps.getAllStudents();

        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(studentsJson);
    } catch (const std::runtime_error& e) {
        res.code = 500;
        res.write("Error: " + std::string(e.what()));
    }

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
        DatabaseOperations dbOps(conn);
        dbOps.insertStudent(id, nombre, correo, telefono);

        res.code = 200;
        res.write("Post success");
    } catch (const std::runtime_error& e) {
        res.code = 500;
        res.write("Error: " + std::string(e.what()));
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

void getStudentById(int id, crow::response& res) {
    try {
        DatabaseOperations dbOps(db.getConnection());
        std::string student = dbOps.getStudentById(id);

        if (student.empty()) {
            res.code = 404;
            res.write("Student not found");
        } else {
            res.code = 200;
            res.write(student);
        }
    } catch (const std::runtime_error& e) {
        res.code = 500;
        res.write("Database error: " + std::string(e.what()));
    }
    res.end();
}
