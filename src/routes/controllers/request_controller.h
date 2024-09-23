#ifndef REQUEST_CONTROLLER_H
#define REQUEST_CONTROLLER_H

#include "crow.h"

void getRequest(crow::response& res);
void createRequest(const crow::request& req, crow::response& res);
void updateRequest(const crow::request& req, crow::response& res);
void deleteRequest(const crow::request& req, crow::response& res);
void getRequestById(int id, crow::response& res);

#endif