#include "ft_printf_bonus.h"

int is_flag(char c)
{
    if(c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
        return 1;
    return 0;
}

int is_conversion(char c)
{
    if (c == '%' || c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
        return 1;
    return 0;
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int perc_counter(char c, const char *str)
{
    int count = 0;
    while(*str)
    {
        if(c == *str)
            count++;
        str++;
    }
    return count;
}

void jump_index(const char *format, int *i)
{
    while(format[*i] != '%' && format[*i])
        (*i)++;

}

void print_struct(t_format *new)
{
    printf("ZERO = %i\n",new->zero);
    printf("MINUS = %i\n",new->minus);
    printf("PLUS = %i\n",new->plus);
    printf("HASH = %i\n",new->hashtag);
    printf("SPACE = %i\n",new->space);
    printf("WIDTH = %i\n",new->width);
    printf("PRECISION = %i\n",new->precision);
    printf("CONVERSION = %c\n",new->conversion);
}