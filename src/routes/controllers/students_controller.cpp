#include "students_controller.h"
#include <sstream>
#include <iostream>

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

    std::cout << "Received JSON body: " << body << std::endl;

    res.code = 200;
    res.write("Creando estudiante");
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
