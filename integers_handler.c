#include "ft_printf.h"

void	left_padding(t_format *new, long long num, int *count, int spaces)
{
	int precision = 0;
	if(new->precision > count_digits(num))
		precision = new->precision - count_digits(num);
	if (num < 0) // <-- Handle negative numbers
	{
		ft_putchar_count('-',count);
		num = -num;
		spaces--;
	}
	if(new->plus == 0 && new->space == 1 && num > 0) //<-- handle space flag
	{
		ft_putchar(' ',count);
		spaces--;
	}
	if(new->plus == 1 && num > 0) // <-- handle plus flag
	{
		ft_putchar_count('+',count);
		spaces--;
	}
	zero_writer(precision,count); // <-- Handle precision
	ft_printnb_count(num,count); // <-- Write number
	space_writer(spaces,count); // <-- Handle width
}

void	right_padding(t_format *new, long long num, int *count, int spaces)
{
	space_writer(spaces,count);
	ft_printnb_count(num,count);
}

void	no_padding(t_format *new, long long num, int *count)
{
	ft_printnb_count(num,count);
}

void	int_handler(t_format *new, va_list args, int *count)
{
	int	spaces;
	int num;

	num = va_arg(args, int);
	spaces = new->width - max(new->precision,count_digits(num));
	if(spaces > 0 && new->minus == 1)
		right_padding(new,num,count,spaces);
	else if (spaces > 0 && new->minus == 0)
		left_padding(new,num,count,spaces);
	else
		no_padding(new,num,count);
}