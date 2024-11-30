#ifndef CORS_MIDDLEWARE_H
#define CORS_MIDDLEWARE_H

#include "crow.h"
#include <string>
#include <vector>

struct CORS {
    struct context {};
    
    std::vector<std::string> allowed_methods = {"GET", "POST", "PUT", "DELETE", "OPTIONS"};
    
    std::vector<std::string> allowed_headers = {"Content-Type"};

    void before_handle(crow::request& req, crow::response& res, context& ctx) {
        if (req.method == crow::HTTPMethod::OPTIONS) {
            res.set_header("Access-Control-Allow-Origin", "*");
            res.set_header("Access-Control-Allow-Methods", join_methods());
            res.set_header("Access-Control-Allow-Headers", join_headers());
            res.code = 204;
            res.end();
        }
    }

    void after_handle(crow::request& req, crow::response& res, context& ctx) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", join_methods());
        res.set_header("Access-Control-Allow-Headers", join_headers());}

private:
    std::string join_methods() {
        return join_strings(allowed_methods);
    }

    std::string join_headers() {
        return join_strings(allowed_headers);
    }

    std::string join_strings(const std::vector<std::string>& strings) {
        std::string result;
        for (size_t i = 0; i < strings.size(); ++i) {
            result += strings[i];
            if (i < strings.size() - 1) {
                result = result + " , ";}
        }
        return result;
    }
};

#endif
