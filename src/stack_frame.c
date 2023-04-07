#include "stack_frame.h"

int main(void) 
{
    usd_cryptocoins cryptocoins = get_cryptocoins();
    usd_exchanges exchanges = get_exchanges();

    printf("\nCotizaciones de criptomonedas en pesos:\n");
    printf("    BTC: $ %.2f\n", asm_exchange(cryptocoins.btc, exchanges.ars));
    printf("    ETH: $ %.2f\n", asm_exchange(cryptocoins.eth, exchanges.ars));

    printf("\nCotizaciones de divisas en euros:\n");
    printf("    ARS: %.2f €\n", asm_exchange(cryptocoins.btc, exchanges.eur));
    printf("    ARS: %.2f €\n", asm_exchange(cryptocoins.eth, exchanges.eur));

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
    printf("    BTC: U$D %.2f\n", cryptocoins.btc);
    printf("    ETH: U$D %.2f\n", cryptocoins.eth);

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
    printf("    ARS: $ %.2f\n", exchanges.ars);
    printf("    EUR: %.2f €\n", exchanges.eur);

    close(fixer_sockfd);

    return exchanges;
}