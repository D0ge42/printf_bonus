#include "ft_printf.h"

void	struct_to_string(t_format *new, va_list args, int *count)
{
	if (new->conversion == 's')
		string_handler(new, args, count);
	if (new->conversion == 'c')
		char_handler(new, args, count);
	if (new->conversion == 'i' || new->conversion == 'd')
		int_handler(new, args, count);
	if (new->conversion == 'u')
		uint_handler(new, args, count);
	if (new->conversion == 'X' || new->conversion == 'x')
		hexa_handler(new, args, count);
	if (new->conversion == 'p')
		p_handler(new, args, count);
	if (new->conversion == '%')
		ft_putchar_count('%', count);
}

void	char_handler(t_format *new, va_list args, int *count)
{
	int		spaces;
	char	c;

	c = va_arg(args, int);
	spaces = new->width - 1;
	if (new->conversion == 'c')
	{
		if (spaces > 0 && new->minus == 0)
		{
			space_writer(spaces, count);
			ft_putchar_count(c, count);
		}
		else if (spaces > 0 && new->minus == 1)
		{
			ft_putchar_count(c, count);
			space_writer(spaces, count);
		}
		else
			ft_putchar_count(c, count);
	}
}

void	string_handler(t_format *new, va_list args, int *count)
{
	int		len;
	int		spaces;
	char	*str;

	str = va_arg(args, char *);
	if (str)
		len = ft_strlen(str);
	else
		len = 6;
	if (new->precision == -1 || new->precision == 0)
		spaces = new->width - (len);
	else
		spaces = new->width - new->precision;
	if (new->minus == 0 && spaces > 0)
		space_writer(spaces, count);
	ft_putstr_count(str, count, new, len);
	if (new->minus == 1 && spaces > 0)
		space_writer(spaces, count);
}

int	ft_strchr(char c, const char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}
