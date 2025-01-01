#include "ft_printf.h"

void	zero_writer(int zeros, int *count)
{
	while (zeros)
	{
		ft_putchar_count('0', count);
		zeros--;
	}
}
void	space_writer(int spaces, int *count)
{
	while (spaces)
	{
		ft_putchar_count(' ', count);
		spaces--;
	}
}
