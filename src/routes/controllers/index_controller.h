#ifndef INDEX_CONTROLLER_H
#define INDEX_CONTROLLER_H

#include "crow.h"
#include "../../db.h"

void handlePapuRoute(const crow::request& req, crow::response& res, DatabaseConnection& dbConn);

#endif
