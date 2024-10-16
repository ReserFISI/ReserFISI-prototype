#include "src/routes/routes.h"

#include "src/middlewares/middlewares.h"

#include "src/services/db_services/db.h"

#include "src/services/email_services/email.h"

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
