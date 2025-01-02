#include "ft_printf.h"

void	p_left_padding(t_format *new, unsigned long long num, int *count,
		int spaces)
{
	int	precision;

	precision = new->precision - count_hex_digits(num);
	if (spaces > 0 && new->minus == 1)
	{
		if (precision > 0)
		{
			while (precision--)
				ft_putchar_count('0', count);
		}
		ft_print_pointer(num, count, -1);
		if (new->zero == 1 && new->precision == 0)
			zero_writer(spaces, count);
		else
			space_writer(spaces, count);
	}
}

void	p_right_padding(t_format *new, unsigned long long num, int *count,
		int spaces)
{
	int	precision;

	precision = new->precision - count_hex_digits(num);
	if (new->zero == 1 && precision <= 0)
		zero_writer(spaces, count);
	else
		space_writer(spaces, count);
	if (precision > 0)
	{
		while (precision--)
			ft_putchar_count('0', count);
	}
	ft_print_pointer(num, count, -1);
}

void	p_no_padding(t_format *new, unsigned long long num, int *count)
{
	int	precision;

	precision = new->precision - count_hex_digits(num);
	if (precision > 0)
	{
		while (precision--)
			ft_putchar_count('0', count);
	}
	ft_print_pointer(num, count, -1);
}

void	p_handler(t_format *new, va_list args, int *count)
{
	unsigned long long	num;
	int					spaces;

	num = va_arg(args, unsigned long long);
	spaces = new->width - count_memory_address_length(num);
	if (new->conversion == 'p')
	{
		if (spaces > 0 && new->minus == 0)
			p_right_padding(new, num, count, spaces);
		else if (spaces > 0 && new->minus == 1)
			p_left_padding(new, num, count, spaces);
		else if (spaces <= 0)
			p_no_padding(new, num, count);
	}
}
