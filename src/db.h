#ifndef DB_H
#define DB_H

#include <libpq-fe.h>
#include <stdexcept>
#include <string>

class DatabaseConnection {
public:
    DatabaseConnection(const std::string& connectionString);
    ~DatabaseConnection();

    PGconn* getConnection() const;

private:
    PGconn* conn;
    void connect(const std::string& connectionString);
    void disconnect();
};

extern DatabaseConnection* db;

void initDatabaseConnection(); 

#endif