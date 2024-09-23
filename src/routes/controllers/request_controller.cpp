#include "request_controller.h"
#include "../../db.h"
#include "../../db_operations.h"
#include <sstream>

void getRequest(crow::response& res) {
    try {
        DatabaseOperations dbOps(db.getConnection());
        std::string requests = dbOps.getAllRequests();

        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(requests);
    } catch (const std::runtime_error& e) {
        res.code = 500;
        res.write("{\"error\": \"" + std::string(e.what()) + "\"}");
    }
    res.end();
}

void createRequest(const crow::request& req, crow::response& res) {
    auto body = crow::json::load(req.body);

    if (!body) {
        res.code = 400;
        res.write("{\"error\": \"Invalid JSON\"}");
        res.end();
        return;
    }

    int id = body["ID_Reserva"].i();
    std::string fechaSolicitud = body["Fecha_Solicitud"].s();
    std::string fechaReserva = body["Fecha_Reserva"].s();
    std::string estadoReserva = body["Estado_Reserva"].s();

    try {
        DatabaseOperations dbOps(db.getConnection());
        dbOps.insertRequest(id, fechaSolicitud, fechaReserva, estadoReserva);

        res.code = 200;
        res.write("{\"message\": \"Post success\"}");
    } catch (const std::runtime_error& e) {
        res.code = 500;
        res.write("{\"error\": \"" + std::string(e.what()) + "\"}");
    }
    res.end();
}

void updateRequest(const crow::request& req, crow::response& res) {
    res.code = 200;
    res.write("{\"message\": \"Actualizando solicitud\"}");
    res.end();
}

void deleteRequest(const crow::request& req, crow::response& res) {
    res.code = 200;
    res.write("{\"message\": \"Eliminando solicitud\"}");
    res.end();
}

void getRequestById(int id, crow::response& res) {
    try {
        DatabaseOperations dbOps(db.getConnection());
        std::string request = dbOps.getRequestById(id);

        if (request.empty()) {
            res.code = 404;
            res.write("{\"error\": \"Request not found\"}");
        } else {
            res.code = 200;
            res.set_header("Content-Type", "application/json");
            res.write(request);
        }
    } catch (const std::runtime_error& e) {
        res.code = 500;
        res.write("{\"error\": \"" + std::string(e.what()) + "\"}");
    }
    res.end();
}
