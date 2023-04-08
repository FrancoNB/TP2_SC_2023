#include "utils.h"

char* format_currency(float number) 
{
    static char result[64];
    char buffer[64];
    int i, len, separador, j;

    memset(result, 0, sizeof(result));
    
    sprintf(buffer, "%.2f", number);

    len = (int)strlen(buffer);
    separador = len - 3;
    i = 0;

    while (separador > 0) 
    {
        separador -= 3;

        if (separador > 0) 
        {
            for (j = len; j >= separador; j--)
                buffer[j + 1] = buffer[j];

            buffer[separador] = ',';
            len++;
        }
    }

    for (j = 0; j < len; j++) 
        result[i++] = buffer[j];
    
    result[i] = '\0';

    return result;
}