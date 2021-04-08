#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char* argv[]) {
    CURL* req = curl_easy_init();
    CURLcode res;
    if (req) {
        curl_easy_setopt(req, CURLOPT_URL, "www.google.com");
        curl_easy_setopt(req, CURLOPT_FOLLOWLOCATION, 1L);
        res = curl_easy_perform(req);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_operation() failed : %s\n",
                curl_easy_strerror(res));
        }
    }
    curl_easy_cleanup(req);
    return 0;
}