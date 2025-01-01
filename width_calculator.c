#include "ft_printf_bonus.h"
/*Function to calculate len of string, char, numbers,hexa and poiters.*/

int calculate_len(void *content, t_format *format)
{
    int len = 0;
    if (format->conversion == 'i' || format->conversion == 'u' || format->conversion == 'd')
        len = count_digits((long long)content,format->conversion);
    else if (format->conversion == 'c')
        len = 1;
    else if (format->conversion == 's')
        len = ft_strlen((char *)content);
    else if (format->conversion == 'x' || format->conversion == 'X')
        len = count_hex_digits((unsigned long long)content);
    else if (format->conversion == 'p')
        len = count_memory_address_length(content);
    else if (format->conversion == '%')
        len = 1;
    return len;
}

void struct_to_string(const char *format,t_format *new, void *content)
{
    int len = calculate_len(content,new);
    int spaces = new->width - len;
}