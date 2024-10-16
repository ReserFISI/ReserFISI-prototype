#include <curl/curl.h>
#include "email.h"

void sendEmail(const std::string& email, const std::string& nombre, int codigo) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:3000/send-email");

        std::string jsonData = "{\"email\":\"" + email + "\", \"nombre\":\"" + nombre + "\", \"codigo\":" + std::to_string(codigo) + "}";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    curl_global_cleanup();
}
