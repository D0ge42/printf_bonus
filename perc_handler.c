#include "ft_printf.h"

void	perc_handler(t_format *new, int *count)
{
	int	spaces;

	spaces = new->width - 1;
	if (new->conversion == '%')
	{
		if (spaces > 0 && new->minus == 0)
		{
			space_writer(spaces, count);
			ft_putchar_count('%', count);
		}
		else if (spaces > 0 && new->minus == 1)
		{
			ft_putchar_count('%', count);
			space_writer(spaces, count);
		}
		else
			ft_putchar_count('%', count);
	}
}
