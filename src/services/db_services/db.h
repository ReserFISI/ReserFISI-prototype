#ifndef DB_H
#define DB_H

#include <libpq-fe.h>
#include <string>
#include <memory>

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

extern std::unique_ptr<DatabaseConnection> db;

void initDatabaseConnection(); 
void cleanupDatabaseConnection();

#endif