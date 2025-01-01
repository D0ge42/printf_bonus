#include "ft_printf_bonus.h"

int ft_printf(char *format, ...)
{
    int i = 0;
    int count;
    va_list args;
    t_format **struct_array = create_struct_array(format);
    void *content;

    va_start(args, format);
    content = va_arg(args, void *);

    while(format[i])
    {
        if (format[i] == '%')
        {
            //struct_to_string --> Function to translate struct into string.
            jump_index(format,&i); //Skip to next % or end.
        }
        else
            ft_putchar_count(format[i++],&count);
    }
    va_end(args);
    return count;
}