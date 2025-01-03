#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BASE_DECIMAL "0123456789"
# define BASE_HEXA_LC "0123456789abcdef"
# define BASE_HEXA_UIPPER "0123456789ABCDEF"

typedef struct s_format
{
	int		minus;
	int		hashtag;
	int		plus;
	int		space;
	int		zero;
	int		width;
	int		precision;
	char	conversion;
}			t_format;

// Utils
int			is_conversion(char c);
int			is_flag(char c);
int			is_digit(char c);
int			perc_counter(char c, const char *str);
void		jump_index(const char *format, int *i);
int			count_digits(long long num);
int			count_hex_digits(unsigned int num);
int			count_memory_address_length(unsigned long long ptr);
void		space_writer(int spaces, int *count);
int			max(int a, int b);
void		zero_writer(int zeros, int *count);
void		free_structs(t_format **struct_array, const char *format);
void		initialize_struct(t_format *new_s);
int			count_udigits(unsigned int num);
int			ft_atoi(const char *str);

// Width precision and len calc
// int calculate_len(void *content, t_format *format);
int			ft_strlen(char *str);

//
int			ft_printf(const char *format, ...);

// Integer/Decimal paddings
void		left_padding(t_format *new_s, long long nb, int *count, int spaces);
void		right_padding(t_format *new_s, long long nb, int *count,
				int spaces);
void		no_padding(t_format *new_s, long long nb, int *count);
void		u_left_padding(t_format *new_s, unsigned int nb, int *count,
				int spaces);
void		u_right_padding(t_format *new_s, unsigned int nb, int *count,
				int spaces);
void		u_no_padding(t_format *new_s, unsigned int nb, int *count);
void		hexa_left_padding(t_format *new_s, unsigned int nb, int *count,
				int spaces);
void		hexa_right_padding(t_format *new_s, unsigned int nb, int *count,
				int spaces);
void		hexa_no_padding(t_format *new_s, unsigned int nb, int *count);
void		p_left_padding(t_format *new_s, unsigned long long nb, int *count,
				int spaces);
void		p_right_padding(t_format *new_s, unsigned long long nb, int *count,
				int spaces);
void		p_no_padding(t_format *new_s, unsigned long long nb, int *count);

// Handlers

void		string_handler(t_format *new_s, va_list args, int *count);
void		char_handler(t_format *new_s, va_list args, int *count);
void		int_handler(t_format *new_s, va_list args, int *count);
void		uint_handler(t_format *new_s, va_list args, int *count);
void		hexa_handler(t_format *new_s, va_list args, int *count);
void		p_handler(t_format *new_s, va_list args, int *count);
void		perc_handler(t_format *new_s, int *count);

// Printers
void		ft_print_pointer(uintptr_t nb, int *count, int flag);
void		ft_print_hexa(unsigned int nb, int *count, char c);
void		ft_printnb_count(long long nb, int *count);
void		ft_printunb_count(unsigned int nb, int *count);
void		ft_putstr_count(void *str2, int *count, t_format *new_s, int len);
void		ft_putchar_count(char c, int *count);
void		ft_putstr(char *str);

// Struct handleer
void		struct_to_string(t_format *new_s, va_list args, int *count);
t_format	*create_struct(const char *format);
t_format	**create_struct_array(const char *format);
void		get_flags(t_format *new_s, const char *format);
int			get_width(const char *format);
int			get_precision(const char *format);
void		get_conversion(const char *format, t_format *new_s);

// Util functions to remove
void		print_struct(t_format *new_s);
// atoi

#endif