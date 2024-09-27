#include <libpq-fe.h>
#include <string>
#include <json/json.h>
#include "db_utilities.h"
#include "db.h"

std::string getDatabaseInfo(DatabaseConnection& dbConn) {
    PGconn* conn = dbConn.getConnection();
    if (!conn) {
        throw std::runtime_error("No database connection");}

    PGresult* result = PQexec(conn, "SELECT version();");

    if(PQresultStatus(result) != PGRES_TUPLES_OK){
        PQclear(result);
        throw std::runtime_error("Failed to execute query: " + std::string(PQerrorMessage(conn)));}

    std::string dbVersion = PQgetvalue(result, 0, 0);
    PQclear(result);

    Json::Value jsonData;
    jsonData["db_version"] = dbVersion;

    Json::StreamWriterBuilder writer;
    return Json::writeString(writer, jsonData);
}
