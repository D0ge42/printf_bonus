#include "ft_printf.h"

void	left_padding(t_format *new, long long num, int *count, int spaces)
{
	int precision = 0;
	if(new->precision > count_digits(num))
		precision = new->precision - count_digits(num);
	if(new->space == 1 && !new->plus && num > 0) // <-- Handle space
		ft_putchar_count(' ',count);
	if(new->plus == 1 && num > 0) // <-- Handle plus
	{
		ft_putchar_count('+',count);
		spaces--;
	}
	zero_writer(precision,count); // <-- Handle precision
	if(new->zero == 1 && spaces && new->precision == 0) //Handle 0 flag.
		zero_writer(spaces,count);
	else
		space_writer(spaces,count); // <-- Handle width
	ft_printnb_count(num,count); // <-- Write number
}

void	right_padding(t_format *new, long long num, int *count, int spaces)
{
	int precision = 0;
	if(new->precision > count_digits(num))
		precision = new->precision - count_digits(num);
	
	zero_writer(precision,count); // <-- Handle precision
	ft_printnb_count(num,count); // <-- Write number
	space_writer(spaces,count); // <-- Handle width

}

void	no_padding(t_format *new, long long num, int *count)
{
	int precision = 0;
	if(new->precision > count_digits(num))
		precision = new->precision - count_digits(num);

	zero_writer(precision,count); // <-- Handle precision
	ft_printnb_count(num,count); // <-- Write number
}

void	int_handler(t_format *new, va_list args, int *count)
{
	int	spaces;
	int num;

	num = va_arg(args, int);
	spaces = new->width - max(new->precision,count_digits(num));
	if(num < 0)
		spaces--;
	if(spaces > 0 && new->minus == 1)
		right_padding(new,num,count,spaces);
	else if (spaces > 0 && new->minus == 0)
		left_padding(new,num,count,spaces);
	else
		no_padding(new,num,count);
}