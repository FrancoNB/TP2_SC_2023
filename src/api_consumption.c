#include "api_consumption.h"

int create_socket(const char* hostname)
{
    struct sockaddr_in serv_addr;
    struct hostent *host = gethostbyname(hostname);

    if (host == NULL) 
    {
        perror("\nError al obtener la información del host");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in *host_addr = (struct sockaddr_in *)host->h_addr_list[0];
    char *ip_address = inet_ntoa(host_addr->sin_addr);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) 
    {
        perror("\nError al crear el socket");
        exit(EXIT_FAILURE);
    }
 
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    {
        perror("\nError al conectar con el servidor");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

char* http_get(int sockfd, const char* hostname, const char* path, const char* api_key, char* buffer, size_t buffer_size)
{
    char aux[1024];

    if(api_key)
        sprintf(aux, "GET %s HTTP/1.1\r\nHost: %s\r\napikey: %s\r\nConnection: close\r\n\r\n", path, hostname, api_key);
    else
        sprintf(aux, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
        
    if (send(sockfd, aux, strlen(aux), 0) < 0) {
        perror("\nError al enviar la solicitud\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, buffer_size);

    while (recv(sockfd, aux, sizeof(aux) - 1, 0) > 0)
    {
        strcat(buffer, aux);
        memset(aux, 0, sizeof(aux));
    }

    if (strstr(buffer, "200 OK") == NULL)
    {
        printf("\nError al obtener la información del servidor");
        exit(EXIT_FAILURE);
    }

    strcpy(aux, strstr(buffer, "\r\n\r\n"));
    strcpy(buffer, aux);

    return buffer;
}

usd_cryptocoins parse_coinlayer_data(const char* response)
{
    usd_cryptocoins result;
    char *aux;

    aux = strstr(response, "BTC") + 5;
    result.btc = (int)((float)atof(aux) * 100 + 0.5f) / 100.0f;

    aux = strstr(response, "ETH") + 5;
    result.eth = (int)((float)atof(aux) * 100 + 0.5f) / 100.0f;

    return result;
}

usd_exchanges parse_fixer(const char* response)
{
    usd_exchanges result;
    char *aux;

    aux = strstr(response, "ARS") + 6;
    result.ars = (int)((float)atof(aux) * 100 + 0.5f) / 100.0f;

    aux = strstr(response, "EUR") + 6;
    result.eur = (int)((float)atof(aux) * 100 + 0.5f) / 100.0f;

    return result;
}