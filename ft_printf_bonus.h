#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

# define BASE_DECIMAL "0123456789"
# define BASE_HEXA_LC "0123456789abcdef"
# define BASE_HEXA_UIPPER "0123456789ABCDEF"

typedef struct s_format
{
    int minus;
    int hashtag;
    int plus;
    int space;
    int zero;
    int width;
    int precision;
    char conversion;
}   t_format;

//Utils
int is_conversion(char c);
int is_flag(char c);
int is_digit(char c);
int perc_counter(char c, const char *str);
void jump_index(const char *format, int *i);
int count_digits(long long num,char format);
int count_hex_digits(unsigned long long num);
int count_memory_address_length(void *ptr);

//Width precision and len calc
int calculate_len(void *content, t_format *format);
int ft_strlen(char *str);


//Printing functions
void	ft_print_pointer(uintptr_t nb, int *count, int flag);
void	ft_print_hexa(unsigned int nb, int *count, char c);
void	ft_printnb_count(long long nb, int *count);
void	ft_putstr_count(va_list args, int *count);
void	ft_putchar_count(char c, int *count);
void    ft_putstr(char *str);

//Struct handleer
t_format *create_struct(const char *format);
t_format **create_struct_array(const char *format);
void    get_flags(t_format *new, const char *format);
int     get_width(const char *format);
int     get_precision_and_conversion(const char *format);

//Util functions to remove
void print_struct(t_format *new);
//atoi

#endif