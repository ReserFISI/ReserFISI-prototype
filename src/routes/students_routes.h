#ifndef STUDENTS_ROUTES_H
#define STUDENTS_ROUTES_H

#include "../middlewares/json_middleware.h"
#include "../middlewares/cors_middleware.h"

#include "crow.h"

void setupStudentRoutes(crow::App<JSONMiddleware,CORS>& app);

#endif
