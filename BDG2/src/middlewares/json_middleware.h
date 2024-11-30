#ifndef JSON_MIDDLEWARE_H
#define JSON_MIDDLEWARE_H

#include "crow.h"

// Por qué chucha esto es una línea en js 

struct JSONMiddleware {
    struct context {
        crow::json::rvalue json_body;  //Se almacena el json aquí 
    };

    void before_handle(crow::request& req, crow::response&, context& ctx) {
        if (req.method == "POST"_method || req.method == "PUT"_method) {
            auto json_body = crow::json::load(req.body);
            
            if(json_body){
                ctx.json_body = std::move(json_body);} 
            else{
                req.body.clear();}}
    }

    void after_handle(crow::request&, crow::response&, context&) {}
};

#endif
