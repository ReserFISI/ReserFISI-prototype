#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <cstdlib>
#include <stdexcept>

class Config {
public:
    static int getPort() {
        const char* env_p = std::getenv("PORT");
        if (!env_p) {
            throw std::runtime_error("El PORT no existe!");
        }
        return std::stoi(env_p);
    }

    static std::string getDbName() {
        const char* dbNameEnv = std::getenv("DB_NAME");
        if (!dbNameEnv) {
            throw std::runtime_error("La variable DB_NAME no existe!");
        }
        return std::string(dbNameEnv);
    }

    static std::string getDbUser() {
        const char* dbUserEnv = std::getenv("DB_USER");
        if (!dbUserEnv) {
            throw std::runtime_error("La variable DB_USER no existe!");
        }
        return std::string(dbUserEnv);
    }

    static std::string getDbPassword() {
        const char* dbPasswordEnv = std::getenv("DB_PASSWORD");
        if (!dbPasswordEnv) {
            throw std::runtime_error("La variable DB_PASSWORD no existe!");
        }
        return std::string(dbPasswordEnv);
    }

    static std::string getDbConnectionString() {
        return "dbname=" + getDbName() + " user=" + getDbUser() + " password=" + getDbPassword();
    }
};

#endif
