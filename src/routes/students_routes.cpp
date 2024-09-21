// students.routes.cpp
#include "students.routes.h"

void setupStudentRoutes(crow::SimpleApp& app) {
    
    CROW_ROUTE(app, "/students")
    ([]() {
        return "obteniendo estudiantes"; 
    });

    CROW_ROUTE(app, "/students")
    .methods(crow::HTTPMethod::POST)
    ([]() {
        return "creando estudiantes"; });

    CROW_ROUTE(app, "/students")
    .methods(crow::HTTPMethod::PUT)
    ([]() {
        return "actualizando estudiantes";  
    });

    CROW_ROUTE(app, "/students")
    .methods(crow::HTTPMethod::DELETE)
    ([]() {
        return "eliminando estudiantes"; 
    });
}
