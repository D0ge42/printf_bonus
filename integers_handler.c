#include "ft_printf.h"

void	left_padding(t_format *new, long long num, int *count, int spaces)
{
	int	precision;

	precision = new->precision - count_digits(num);
	if (num < 0)
		precision += 1;
	if (spaces > 0 && new->minus == 1)
	{
		if (new->plus == 1)
		{
			spaces -= 1;
			if (num > 0)
				ft_putchar_count('+', count);
		}
		if (precision > 0)
		{
			while (precision--)
				ft_putchar_count('0', count);
		}
		ft_printnb_count(num, count);
		if (new->zero == 1 && new->precision == 0)
			zero_writer(spaces, count);
		else
			space_writer(spaces, count);
	}
}

void	right_padding(t_format *new, long long num, int *count, int spaces)
{
	int	precision;

	if (num < 0 && new->zero == 1)
	{
		num *= -1;
		ft_putchar_count('-', count);
	}
	precision = new->precision - count_digits(num);
	if (num < 0)
		precision += 1;
	if (new->plus == 1)
	{
		spaces -= 1;
		if (num > 0)
			ft_putchar_count('+', count);
	}
	if (new->zero == 1 && precision <= 0)
		zero_writer(spaces, count);
	else
		space_writer(spaces, count);
	if (precision > 0)
	{
		while (precision--)
			ft_putchar_count('0', count);
	}
	ft_printnb_count(num, count);
}

void	no_padding(t_format *new, long long num, int *count)
{
	int	precision;

	precision = new->precision - count_digits(num);
	if (num < 0)
		precision += 1;
	if (new->plus == 1)
	{
		if (num >= 0)
			ft_putchar_count('+', count);
	}
	if (precision > 0)
	{
		if (num < 0)
		{
			ft_putchar_count('-', count);
			num *= -1;
		}
		while (precision--)
			ft_putchar_count('0', count);
	}
	if (new->space == 1 && new->plus == 0)
	{
		if (num >= 0)
			ft_putchar_count(' ', count);
	}
	ft_printnb_count(num, count);
}

void	int_handler(t_format *new, va_list args, int *count)
{
	int	spaces;
	int num;

	num = va_arg(args, int);
	spaces = new->width - max(new->precision,count_digits(num)); //max precision/num
	if (new->conversion == 'i' || new->conversion == 'd')
	{
		if (spaces > 0 && new->minus == 0)
			right_padding(new, num, count, spaces);
		else if (spaces > 0 && new->minus == 1)
			left_padding(new, num, count, spaces);
		else if (spaces <= 0)
			no_padding(new, num, count);
	}
}