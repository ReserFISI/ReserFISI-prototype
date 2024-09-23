#ifndef DB_OPERATIONS_H
#define DB_OPERATIONS_H

#include <libpq-fe.h>
#include <string>
#include <stdexcept>

class DatabaseOperations {
public:
    DatabaseOperations(PGconn* connection);

    void insertStudent(int id, const std::string& nombre, const std::string& correo, const std::string& telefono);
    std::string getAllStudents();
    std::string getStudentById(int id);

    void insertRequest(int id, const std::string& fechaSolicitud, const std::string& fechaReserva, const std::string& estadoReserva);
    std::string getAllRequests();
    std::string getRequestById(int id);
    bool removeRequestById(int id);

private:
    PGconn* conn;
};

#endif