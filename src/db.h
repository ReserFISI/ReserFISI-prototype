#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <libpq-fe.h>
#include <string>

class DatabaseConnection {
public:
    DatabaseConnection(const std::string& conninfo);

    ~DatabaseConnection();

    PGconn* getConnection() const;

private:
    PGconn* conn; 
};

#endif 
