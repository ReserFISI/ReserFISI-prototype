#include "../db.h"
#include "crow.h"

//Routes db

void setupIndexRoutes(crow::SimpleApp& app, DatabaseConnection& dbConn) {
    CROW_ROUTE(app, "/papu")([&dbConn]() {
        PGconn* conn = dbConn.getConnection();
        if (!conn) {
            return crow::response(500, "Error de conexión a la base de datos");
        }

        PGresult* res = PQexec(conn, "SELECT 2");
        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            PQclear(res);
            return crow::response(500, "Error al ejecutar la consulta");
        }

        std::string result = PQgetvalue(res, 0, 0);
        PQclear(res);

        return crow::response(result);
    });
}
