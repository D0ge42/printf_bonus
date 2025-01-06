#include "ft_printf.h"

/*Handle every combination of width/precision for chars. */

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
