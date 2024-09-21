#include "index_routes.h"
#include "controllers/index_controller.h"

void setupIndexRoutes(crow::SimpleApp& app, DatabaseConnection& dbConn) {
    CROW_ROUTE(app, "/papu")
    ([&dbConn](const crow::request& req, crow::response& res) {
        handlePapuRoute(req, res, dbConn);
    });
}
