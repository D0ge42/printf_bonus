#include "ft_printf.h"

void	struct_to_string(t_format *new, va_list args,
		int *count)
{
	// printf("%i\n",maxl);
	// printf("SPAZI = %i\n",spaces);
	// printf("WIDTH = %i\n",new->width);
	// printf("LEN = %i\n",len);
	// printf("%i\n",new->precision);
	if (new->conversion == 's')
		string_handler(new, args, count);
	if (new->conversion == 'c')
		char_handler(new, args, count);
	if (new->conversion == 'i' || new->conversion == 'd')
		int_handler(new, args, count);
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
	int len;
	int maxl;
	int spaces;

	char *str = va_arg(args, char *);
	if (str)
		len = ft_strlen(str);
	else
		len = 6;
	maxl = max(new->precision, len);
	spaces = new->width - maxl;
	if (new->conversion == 's')
	{
		if (spaces > 0 && new->minus == 0)
		{
			space_writer(spaces, count);
			ft_putstr_count(str, count, new->precision, len);
		}
		else if (spaces > 0 && new->minus == 1)
		{
			ft_putstr_count(str, count, new->precision, len);
			space_writer(spaces, count);
		}
		else
			ft_putstr_count(str, count, new->precision, len);
	}
}