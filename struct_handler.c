#include "ft_printf_bonus.h"

int get_width(const char *format)
{
    char width[11];
    int i = 0;
    int j = 0;

    if (format[i] == '%')
    {
        i++;
        while(is_flag(format[i]) && format[i] && format[i] != '%')
            i++;
        while(is_digit(format[i]) && format[i] && format[i] != '%')
            width[j++] = format[i++];
    }
    width[j] = '\0';
    return atoi(width);
}

int get_precision(const char *format)
{
    int i = 0;
    int j = 0;
    char precision[11];
    if (format[i] == '%')
        i++;
    while(is_flag(format[i]) && format[i] && format[i] != '%')
        i++;
    while(format[i] != '.' && format[i] && format[i] != '%')
        i++;
    if (format[i] == '.')
    {
        i++;
        while(is_digit(format[i]) && format[i] && format[i] != '%')
            precision[j++] = format[i++];
    }
    precision[j] = '\0';
    return atoi(precision);
}

//TO MAKE
void get_conversion(const char *format,t_format *new)
{
    int i = 0;
    if(format[i] == '%')
        i++;
    while(is_flag(format[i]) && format[i] && format[i] != '%')
        i++;
    while(format[i] && (format[i] == '.' || is_digit(format[i]) && format[i] != '%'))
        i++;
    if(is_conversion(format[i]))
        new->conversion = format[i];
}

void get_flags(t_format *new, const char *format)
{
    int i = 0;
    if(format[i] == '%')
        i++;
    while(is_flag(format[i]) && format[i] && format[i] != '%')
    {
        if(format[i] == '-')
            new->minus = 1;
        if(format[i] == '+')
            new->plus = 1;
        if(format[i] == '#')
            new->hashtag = 1;
        if(format[i] == ' ')
            new->space = 1;
        if(format[i] == '0')
            new->zero = 1;
        i++;
    }
}
/*Takes format string and makes a structure out of it, with all the relative infos.*/

t_format *create_struct(const char *format)
{
    t_format *new = (t_format *)malloc(sizeof(t_format));
    new->width = get_width(format);
    new->precision = get_precision(format);
    get_flags(new,format);
    get_conversion(format,new);
    return new;
}

/*Creates a struct array out of a format string. Each % is a structure.*/

t_format **create_struct_array(const char *format)
{
    int n_struct = 0;
    int i = 0;
    int struct_count = perc_counter('%',format);
    t_format **struct_array = (t_format **)malloc(sizeof(t_format *) * struct_count);
    while(format[i])
    {
        if(format[i] == '%')
        {
            i++;
            struct_array[n_struct] = create_struct(&(format[i]));
            jump_index(format,&i);
            n_struct++;
        }
        else
            i++;
    }
    return struct_array;
}

int main()
{
    t_format **struct_array = create_struct_array("%#-.3x %X %313.21s");
}