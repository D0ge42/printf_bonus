#include "ft_printf_bonus.h" 

void	ft_putstr_count(va_list args, int *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str++, 1);
		*count += 1;
	}
}
