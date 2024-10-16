#ifndef INDEX_ROUTES_H
#define INDEX_ROUTES_H

#include "crow.h"

#include "../services/db_services/db.h"

#include "../middlewares/json_middleware.h"
#include "../middlewares/cors_middleware.h"

void setupIndexRoutes(crow::App<JSONMiddleware, CORS>& app, DatabaseConnection& dbConn);

#endif
