#ifndef REQUEST_ROUTES_H
#define REQUEST_ROUTES_H

#include "../json_middleware.h"
#include "../cors_middleware.h"

#include "crow.h"

void setupRequestRoutes(crow::App<JSONMiddleware,CORS>& app);

#endif
