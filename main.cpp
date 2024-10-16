#include "src/routes/request_routes.h"
#include "src/routes/students_routes.h"
#include "src/routes/index_routes.h"

#include "src/db.h"
#include "db/db_setup.h"

#include "src/cors_middleware.h"
#include "src/json_middleware.h"

#include "email_service/email.h"

#include "dotenv.h"

int main() {
    
    dotenv::init("../.env");
    
    initDatabaseConnection();

    crow::App<JSONMiddleware,CORS> app; 
    
    setupRequestRoutes(app);
    setupStudentRoutes(app);
    setupIndexRoutes(app, *db);

    //sendEmail("test@gmail.com", "test", 1234);
    
    app.port(18080).multithreaded().run();

    cleanupDatabaseConnection();

    return 0;
}
