#ifndef INDEX_CONTROLLER_H
#define INDEX_CONTROLLER_H

#include "crow.h"
#include "../../services/db_services/db.h"

std::string getDatabaseInfo(const DatabaseConnection& dbConn);

#endif
