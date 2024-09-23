#include "request_routes.h"
#include "controllers/request_controller.h"

void setupRequestRoutes(crow::App<JSONMiddleware>& app) {
    CROW_ROUTE(app, "/request")
    .methods(crow::HTTPMethod::GET)
    ([](const crow::request& req, crow::response& res) {
        getRequest(res);
    });

    CROW_ROUTE(app, "/request")
    .methods(crow::HTTPMethod::POST)
    ([](const crow::request& req, crow::response& res) {
        createRequest(req, res);
    });

    CROW_ROUTE(app, "/request")
    .methods(crow::HTTPMethod::PUT)
    ([](const crow::request& req, crow::response& res) {
        updateRequest(req, res);
    });

    CROW_ROUTE(app, "/request/<int>")
    .methods(crow::HTTPMethod::DELETE)
    ([](const crow::request& req, crow::response& res, int id) {
        deleteRequestById(req, res, id);
    });

    CROW_ROUTE(app, "/request/<int>")
    .methods(crow::HTTPMethod::GET)
    ([](const crow::request& req, crow::response& res, int id) {
        getRequestById(id, res);
    });


}
