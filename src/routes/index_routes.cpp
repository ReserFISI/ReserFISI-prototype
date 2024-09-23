#include "index_routes.h"
#include "controllers/index_controller.h"
#include "../json_middleware.h"

void setupIndexRoutes(crow::App<JSONMiddleware>& app, DatabaseConnection& dbConn) {
    CROW_ROUTE(app, "/papu")
    ([&dbConn](const crow::request& req, crow::response& res) {
        handlePapuRoute(req, res, dbConn);
    });
}
