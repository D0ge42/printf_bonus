#include "ft_printf.h"

void	left_padding(t_format *new, long long num, int *count, int spaces)
{
	int	precision;

	precision = new->precision - count_digits(num, new->conversion);
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
	precision = new->precision - count_digits(num, new->conversion);
	if (new->conversion == 'i')
	{
		if (spaces > 0 && new->minus == 0)
		{
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
	}
}

void	no_padding(t_format *new, long long num, int *count)
{
	int	precision;

	precision = new->precision - count_digits(num, new->conversion);
	if (new->plus == 1)
	{
		if (num > 0)
			ft_putchar_count('+', count);
	}
	if (precision > 0)
	{
		while (precision--)
			ft_putchar_count('0', count);
	}
	if (new->space == 1 && new->plus == 0)
	{
		if (num > 0)
			ft_putchar_count(' ', count);
	}
	ft_printnb_count(num, count);
}

void	int_handler(t_format *new, va_list args, int *count)
{
	int num = va_arg(args, long long);
	int spaces = new->width - count_digits(num, new->conversion);
	if (new->conversion == 'i')
	{
		right_padding(new, num, count, spaces);
		left_padding(new, num, count, spaces);
		if (spaces <= 0)
			no_padding(new, num, count);
	}
}