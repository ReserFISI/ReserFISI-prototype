#ifndef INDEX_ROUTES_H
#define INDEX_ROUTES_H

#include "crow.h"
#include "../db.h"
#include "../json_middleware.h"

void setupIndexRoutes(crow::App<JSONMiddleware>& app, DatabaseConnection& dbConn);

#endif
