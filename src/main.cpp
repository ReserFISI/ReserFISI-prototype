#include "./routes/students.routes.h"
#include "./routes/index_routes.h"
#include "db.h"


int main() {
    crow::SimpleApp app;

    DatabaseConnection dbConn("dbname=hola user=sebastianrojas password=1234");

    setupStudentRoutes(app);

    setupIndexRoutes(app, dbConn);

    app.port(18080).multithreaded().run();

    return 0;
}
