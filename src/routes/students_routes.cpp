#include "students_routes.h"
#include "controllers/students_controller.h"

void setupStudentRoutes(crow::App<JSONMiddleware,CORS>& app) {
    CROW_ROUTE(app, "/students")
    .methods(crow::HTTPMethod::GET)
    ([](const crow::request& req, crow::response& res) {
        getStudents(res);
    });

    CROW_ROUTE(app, "/students")
    .methods(crow::HTTPMethod::POST)
    ([](const crow::request& req, crow::response& res) {
        createStudent(req, res);
    });

    CROW_ROUTE(app, "/students")
    .methods(crow::HTTPMethod::PUT)
    ([](const crow::request& req, crow::response& res) {
        updateStudent(req, res);
    });

    CROW_ROUTE(app, "/students")
    .methods(crow::HTTPMethod::DELETE)
    ([](const crow::request& req, crow::response& res) {
        deleteStudent(req, res);
    });

    CROW_ROUTE(app, "/students/<int>")
    .methods(crow::HTTPMethod::GET)
    ([](const crow::request& req, crow::response& res, int id) {
    getStudentById(id, res);
    });


}

