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
    
    void connect(const std::string& connectionString);
    void disconnect();

private:
    PGconn* conn;
};

extern DatabaseConnection* db;

void initDatabaseConnection(); 
void cleanupDatabaseConnection();

#endif