#include "main.h"

int main(void) 
{
    usd_cryptocoins cryptocoins = get_cryptocoins();
    usd_exchanges exchanges = get_exchanges();

    printf("\nRealizando converciones...\n");

    printf("\nCotizaciones de criptomonedas en pesos:\n");
    printf("    BTC: $ %s\n", format_currency(asm_exchange(cryptocoins.btc, exchanges.ars)));
    printf("    ETH: $ %s\n", format_currency(asm_exchange(cryptocoins.eth, exchanges.ars)));

    printf("\nCotizaciones de divisas en euros:\n");
    printf("    BTC: %s €\n", format_currency(asm_exchange(cryptocoins.btc, exchanges.eur)));
    printf("    ETH: %s €\n", format_currency(asm_exchange(cryptocoins.eth, exchanges.eur)));

    return 0;
}

usd_cryptocoins get_cryptocoins(void)
{
    char coinlayer_response[RESPONSE_BUFFER_SIZE];

    printf("\nObteniendo cotizaciones de criptomonedas...\n");

    int coinlayer_sockfd = create_socket(coinlayer_hostname);

    http_get(coinlayer_sockfd, coinlayer_hostname, coinlayer_path, NULL, coinlayer_response, RESPONSE_BUFFER_SIZE);

    usd_cryptocoins cryptocoins = parse_coinlayer_data(coinlayer_response);

    printf("\nCotizaciones obtenidas:\n");
    printf("    BTC: U$D %s\n", format_currency(cryptocoins.btc));
    printf("    ETH: U$D %s\n", format_currency(cryptocoins.eth));

    close(coinlayer_sockfd);

    return cryptocoins;
}

usd_exchanges get_exchanges(void)
{
    char fixer_response[RESPONSE_BUFFER_SIZE];

    printf("\nObteniendo cotizaciones de divisas...\n");

    int fixer_sockfd = create_socket(fixer_hostname);

    http_get(fixer_sockfd, fixer_hostname, fixer_path, fixer_api_key, fixer_response, RESPONSE_BUFFER_SIZE);

    usd_exchanges exchanges = parse_fixer(fixer_response);

    printf("\nCotizaciones obtenidas:\n");
    printf("    ARS: $ %s\n", format_currency(exchanges.ars));
    printf("    EUR: %s €\n", format_currency(exchanges.eur));

    close(fixer_sockfd);

    return exchanges;
}