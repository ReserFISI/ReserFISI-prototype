#ifndef STUDENTS_ROUTES_H
#define STUDENTS_ROUTES_H

#include "../json_middleware.h"
#include "../cors_middleware.h"

#include "crow.h"

void setupStudentRoutes(crow::App<JSONMiddleware,CORS>& app);

#endif
