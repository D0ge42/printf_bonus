#include "ft_printf_bonus.h"

void	ft_print_hexa(unsigned int nb, int *count, char c)
{
	char	*lcbase;
	char	*ucbase;

	lcbase = "0123456789abcdef";
	ucbase = "0123456789ABCDEF";
	if (c == 'x')
	{
		if (nb >= 16)
			ft_print_hexa(nb / 16, count, 'x');
		ft_putchar_count(lcbase[nb % 16], count);
	}
	else if (c == 'X')
	{
		if (nb >= 16)
			ft_print_hexa(nb / 16, count, 'X');
		ft_putchar_count(ucbase[nb % 16], count);
	}
}
