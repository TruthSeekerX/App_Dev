/* This project is meant for studying first year IT engineering course Application Development.
This is a testing for libcurl library. It grabs the html code from a website(in this case www.google.com) and print it out on the screen.
*/

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