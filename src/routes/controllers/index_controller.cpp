#include "index_controller.h"
#include <libpq-fe.h>
#include <string>

void handlePapuRoute(const crow::request& req, crow::response& res, DatabaseConnection& dbConn) {
    PGconn* conn = dbConn.getConnection();
    if (!conn) {
        res = crow::response(500, "Error de conexión a la base de datos");
        return;
    }

    PGresult* result = PQexec(conn, "SELECT 2");
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        res = crow::response(500, "Error al ejecutar la consulta");
        PQclear(result);
        return;
    }

    std::string value = PQgetvalue(result, 0, 0);
    PQclear(result);

    res = crow::response(value);
    res.end();
}