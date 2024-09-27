#include "controllers/index_controller.h"
#include "../json_middleware.h"
#include <json/json.h> 
#include "index_routes.h"

#include "../db_utilities.h"

void setupIndexRoutes(crow::App<JSONMiddleware>& app, DatabaseConnection& dbConn) {
    
    CROW_ROUTE(app, "/dbinfo")
    ([&dbConn](const crow::request& req, crow::response& res) {
        std::string dbInfo = getDatabaseInfo(dbConn);
        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(dbInfo);
        res.end();
    });

    CROW_ROUTE(app, "/status")
    .methods(crow::HTTPMethod::GET)
    ([&dbConn](const crow::request& req, crow::response& res) {
        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write("{\"status\": \"API is running\"}");
        res.end();
    });
}
