#include "ft_printf.h"

void	ft_printnb_count(long long int nb, int *count)
{
	if (nb < 0)
	{
		ft_putchar_count('-', count);
		nb *= -1;
	}
	if (nb > 9)
		ft_printnb_count(nb / 10, count);
	ft_putchar_count(nb % 10 + '0', count);
}

void	ft_printunb_count(unsigned int nb, int *count)
{
	if (nb > 9)
		ft_printnb_count(nb / 10, count);
	ft_putchar_count(nb % 10 + '0', count);
}
