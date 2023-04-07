#ifndef __API_CONSUMPTION_H__
#define __API_CONSUMPTION_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

typedef struct 
{
    float eth;
    float btc;
} usd_cryptocoins;

typedef struct
{
    float ars;
    float eur;
} usd_exchanges;

int create_socket(const char* hostname);
char* http_get(int sockfd, const char* hostname, const char* path, const char* api_key, char* buffer, size_t buffer_size);
usd_cryptocoins parse_coinlayer_data(const char* response);
usd_exchanges parse_fixer(const char* response);

#endif // __API_CONSUMPTION_H__