#include "db/db_setup.h"
#include "src/routes/routes.h"
#include "src/middlewares/middlewares.h"
#include "src/services/db_services/db.h"
#include "src/utils/config.h"

#include <dotenv.h>

int main() {
    
    dotenv::init("../.env");

    crow::App<JSONMiddleware,CORS> app; 
    int PORT = Config::getPort(); 

    setupDatabase(); 
    initDatabaseConnection();
    
    setupRequestRoutes(app);
    setupStudentRoutes(app);
    setupIndexRoutes(app, *db);
    
    app.port(PORT).multithreaded().run();

    cleanupDatabaseConnection();

    return 0;
}
