#include "ft_printf.h"

void	ft_printnb_count(long long nb, int *count)
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
