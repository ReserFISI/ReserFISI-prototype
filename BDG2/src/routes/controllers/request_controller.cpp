#include "request_controller.h"
#include "../../services/db_services/db.h"
#include "../../services/db_services/db_operations.h"

void getRequest(crow::response& res) {
    try{DatabaseOperations dbOps(db->getConnection());
        std::string requests = dbOps.getAllRequests();

        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(requests);}

    catch(const std::runtime_error& e){
        res.code = 500;
        res.set_header("Content-Type", "application/json");
        res.write("{\"error\": \"" + std::string(e.what()) + "\"}");}
    res.end();
}

void createRequest(const crow::request& req, crow::response& res) {
    auto body = crow::json::load(req.body);
    if (!body) {
        res.code = 400;
        res.set_header("Content-Type", "application/json");
        res.write("{\"error\": \"Invalid JSON\"}");
        res.end();
        return;
    }

    try {
        int idAlumno = body["ID_Alumno"].i();      
        int idEspacio = body["ID_Espacio"].i();    
        int idUnidad = body.has("ID_Unidad") ? body["ID_Unidad"].i() : 0; 
        std::string fechaSolicitud = body["Fecha_Solicitud"].s(); 
        std::string fechaReserva = body["Fecha_Reserva"].s();    
        std::string estadoReserva = body["Estado_Reserva"].s();   

        DatabaseOperations dbOps(db->getConnection());
        dbOps.insertRequest(idAlumno, idEspacio, idUnidad, fechaSolicitud, fechaReserva, estadoReserva);

        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write("{\"message\": \"Post success\"}");
    } catch (const std::runtime_error& e) {
        res.code = 500;
        res.set_header("Content-Type", "application/json");
        res.write("{\"error\": \"" + std::string(e.what()) + "\"}");
    }
    res.end();
}

void updateRequest(const crow::request& req, crow::response& res, int id) {
    try {
        auto json = crow::json::load(req.body);
        if (!json) {
            res.code = 400;
            res.write("{\"error\": \"JSON inválido\"}");
        } else {
            int idEspacio = json["ID_Espacio"].i();
            int idUnidad = json["ID_Unidad"].i();
            std::string fechaSolicitud = json["Fecha_Solicitud"].s();
            std::string fechaReserva = json["Fecha_Reserva"].s();
            std::string estadoReserva = json["Estado_Reserva"].s();

            std::cout << "Datos recibidos: ID_Espacio: " << idEspacio
                      << ", ID_Unidad: " << idUnidad
                      << ", Fecha_Solicitud: " << fechaSolicitud
                      << ", Fecha_Reserva: " << fechaReserva
                      << ", Estado_Reserva: " << estadoReserva
                      << ", ID_Reserva: " << id << std::endl;

            DatabaseOperations dbOps(db->getConnection());
            dbOps.updateRequestById(id, idEspacio, idUnidad, fechaSolicitud, fechaReserva, estadoReserva);

            res.code = 200;
            res.write("{\"message\": \"Solicitud actualizada\"}");
        }
    } catch (const std::exception& e) {
        res.code = 500;
        res.write("{\"error\": \"" + std::string(e.what()) + "\"}");
    }
    res.end();
}


void deleteRequestById(const crow::request& req, crow::response& res, int id) {
    try {
        DatabaseOperations dbOps(db->getConnection());
        bool deleted = dbOps.removeRequestById(id);
        if (deleted) {
            res.code = 200;
            res.set_header("Content-Type", "application/json");
            res.write("{\"message\": \"Solicitud eliminada exitosamente\"}");
        } else {
            res.code = 404;
            res.set_header("Content-Type", "application/json");
            res.write("{\"error\": \"No se encontró la solicitud con el ID proporcionado\"}");
        }
    } catch (const std::runtime_error& e) {
        res.code = 500;
        res.set_header("Content-Type", "application/json");
        res.write("{\"error\": \"Database error: " + std::string(e.what()) + "\"}");
    }
    res.end();
}

void getRequestById(int id, crow::response& res) {
    try{
        DatabaseOperations dbOps(db->getConnection());
        std::string request = dbOps.getRequestById(id);

        if (request.empty()) {
            res.code = 404;
            res.write("{\"error\": \"Request not found\"}");} 
        else{
            res.code = 200;
            res.set_header("Content-Type", "application/json");
            res.write(request);}} 
    catch (const std::runtime_error& e){
        res.code = 500;
        res.write("{\"error\": \"" + std::string(e.what()) + "\"}");}
    res.end();
}
