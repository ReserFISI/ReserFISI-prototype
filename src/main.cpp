#include "./routes/request_routes.h"

#include "./routes/students_routes.h"

#include "./routes/controllers/students_controller.h"
#include "./routes/controllers/request_controller.h"

#include "./routes/index_routes.h"

#include "db.h"
#include "json_middleware.h"

int main() {
    crow::App<JSONMiddleware> app; 

    DatabaseConnection db("dbname=reserfisi user=sebastianrojas password=1234");

    setupRequestRoutes(app);
    setupStudentRoutes(app);

    setupIndexRoutes(app, db);

    app.port(18080).multithreaded().run();

    return 0;
}
