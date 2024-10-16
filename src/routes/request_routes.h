#ifndef REQUEST_ROUTES_H
#define REQUEST_ROUTES_H

#include "../middlewares/json_middleware.h"
#include "../middlewares/cors_middleware.h"

#include "crow.h"

void setupRequestRoutes(crow::App<JSONMiddleware,CORS>& app);

#endif
