#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
void space_writer(int spaces, int *count);
int max(int a, int b);
void zero_writer(int zeros, int *count);

//Width precision and len calc
//int calculate_len(void *content, t_format *format);
int ft_strlen(char *str);

//
int ft_printf(const char *format, ...);

//Integer/Decimal paddings
void	left_padding(t_format *new, long long nb, int *count, int spaces);
void	right_padding(t_format *new, long long nb, int *count, int spaces);
void	no_padding(t_format *new, long long nb, int *count);

//Handlers

void string_handler(t_format *new, va_list args, int *count);
void char_handler(t_format *new, va_list args, int *count);
void int_handler(t_format *new, va_list args,int *count);

//Printers
void	ft_print_pointer(uintptr_t nb, int *count, int flag);
void	ft_print_hexa(unsigned int nb, int *count, char c);
void	ft_printnb_count(long long nb, int *count);
void	ft_putstr_count(void *str2, int *count, int precision,int len);
void	ft_putchar_count(char c, int *count);
void    ft_putstr(char *str);

//Struct handleer
void    struct_to_string(t_format *new,va_list args, int *count);
t_format *create_struct(const char *format);
t_format **create_struct_array(const char *format);
void    get_flags(t_format *new, const char *format);
int     get_width(const char *format);
int     get_precision(const char *format);
void    get_conversion(const char *format,t_format *new);

//Util functions to remove
void print_struct(t_format *new);
//atoi

#endif