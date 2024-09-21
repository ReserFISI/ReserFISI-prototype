#ifndef INDEX_ROUTES_H
#define INDEX_ROUTES_H

#include "crow.h"
#include "../db.h"

void setupIndexRoutes(crow::SimpleApp& app, DatabaseConnection& dbConn);

#endif
