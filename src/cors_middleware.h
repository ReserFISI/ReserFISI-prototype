#ifndef CORS_MIDDLEWARE_H
#define CORS_MIDDLEWARE_H

#include "crow.h"

struct CORS {
    struct context {};
    
    void before_handle(crow::request& req, crow::response& res, context& ctx) {
        // ?? 
    }

    void after_handle(crow::request& req, crow::response& res, context& ctx) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
    }
};

#endif
