#include "src/routes/request_routes.h"
#include "src/routes/students_routes.h"
#include "src/routes/index_routes.h"

#include "src/db.h"
#include "src/json_middleware.h"
#include "dotenv.h"

int main() {
    
    dotenv::init("../.env");
    initDatabaseConnection();

    crow::App<JSONMiddleware> app; 
    
    setupRequestRoutes(app);
    setupStudentRoutes(app);

    setupIndexRoutes(app, *db);

    app.port(18080).multithreaded().run();

    cleanupDatabaseConnection();

    return 0;
}
