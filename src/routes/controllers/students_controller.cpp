#include "students_controller.h"
#include <sstream>

void getStudents(crow::response& res) {
    res.write("Obteniendo estudiantes");
    res.end();
}

void createStudent(const crow::request& req, crow::response& res) {
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
