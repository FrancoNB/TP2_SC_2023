#ifndef __MAIN_H__
#define __MAIN_H__

#include "api_consumption.h"
#include "asm_headers.h"
#include "utils.h"

#define RESPONSE_BUFFER_SIZE 2048

const char *fixer_api_key = "kTYJpcxCZWbB7To7NkrWa7ThqUvTNvP8";
const char *fixer_path = "/fixer/latest?symbols=EUR%2CARS&base=USD";

const char *coinlayer_path = "/live?access_key=1f6ac17f15dcf73bc231dd6213a141c3&symbols=BTC%2CETH";

const char *fixer_hostname = "api.apilayer.com";
const char *coinlayer_hostname = "api.coinlayer.com";

usd_cryptocoins get_cryptocoins(void);
usd_exchanges get_exchanges(void);

#endif // __MAIN_H__