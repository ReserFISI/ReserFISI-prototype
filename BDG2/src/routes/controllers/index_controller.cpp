#include "index_controller.h"
#include <libpq-fe.h>
#include <string>
#include <json/json.h> 

std::string getDatabaseInfo(const DatabaseConnection& dbConn) {
    PGconn* conn = dbConn.getConnection();
    if (!conn) {
        return "{\"error\": \"No connection to database\"}";
    }

    PGresult* result = PQexec(conn, "SELECT version()");
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        PQclear(result);
        return "{\"error\": \"Failed to retrieve database info\"}";
    }

    std::string dbVersion = PQgetvalue(result, 0, 0);
    PQclear(result);

    Json::Value jsonData;
    jsonData["database_version"] = dbVersion;

    Json::StreamWriterBuilder writer;
    return Json::writeString(writer, jsonData);
}